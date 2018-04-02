#ifndef __COFF_H__
#define __COFF_H__

#include <os_types.h>
#include <os_lif.h>

// -- COFF target codes ------------------------------------------------------

#define COFF_TGT_C6000          0x0099

// -- COFF header flags ------------------------------------------------------

#define COFF_F_RELFLG           0x0001          // Relocation information was stripped from the file.
#define COFF_F_EXEC             0x0002          // The file is relocatable (it contains no unresolved
                                                // external references).
#define COFF_F_LSYMS            0x0008          // Local symbols were stripped from the file.
#define COOF_F_LITTLE           0x0100          // The target is a little-endian device.
#define COFF_F_BIG              0x0200          // The target is a big-endian device.

// -- COFF section header flags ----------------------------------------------

#define COFF_STYP_REG           0x00000000      // Regular section (allocated, relocated, loaded)
#define COFF_STYP_DSECT         0x00000001      // Dummy section (relocated, not allocated, not loaded)
#define COFF_STYP_NOLOAD        0x00000002      // Noload section (allocated, relocated, not loaded)
#define COFF_STYP_COPY          0x00000010      // Copy section (relocated, loaded, but not allocated; relocation entries are processed normally)
#define COFF_STYP_TEXT          0x00000020      // Section contains executable code
#define COFF_STYP_DATA          0x00000040      // Section contains initialized data
#define COFF_STYP_BSS           0x00000080      // Section contains uninitialized data
#define COFF_STYP_BLOCK         0x00001000      // Alignment used as a blocking factor
#define COFF_STYP_PASS          0x00002000      // Section should pass through unchanged
#define COFF_STYP_CLINK         0x00004000      // Section requires conditional linking
#define COFF_STYP_VECTOR        0x00008000      // Section contains vector table
#define COFF_STYP_PADDED        0x00010000      // Section has been padded

// -- Structures -------------------------------------------------------------

#pragma pack( push, 1 )

struct s_coff_header
{
  uint16                        version;
  uint16                        section_count;
  uint32                        build_date;
  uint32                        symbol_offset;
  uint32                        symbol_count;
  uint16                        opthdr_length;
  uint16                        flags;
  uint16                        target;
};

struct s_coff_opthdr
{
  uint16                        magic;                  // Always 0x0108
  uint16                        version;
  uint32                        size_exec;
  uint32                        size_init_data;
  uint32                        size_uninit_data;
  uint32                        entry_point;
  uint32                        entry_point_exec;
  uint32                        entry_point_init_data;
};

struct s_coff_section
{
  char                          name[8];
  uint32                        physical_address;
  uint32                        virtual_address;
  uint32                        length;
  uint32                        raw_offset;
  uint32                        relocation_offset;
  uint32                        rsvd0;
  uint32                        relocation_count;
  uint32                        rsvd1;
  uint32                        flags;
  uint16                        rsvd2;
  uint16                        mpage_number;
};

struct s_coff_relocation
{
  uint32                        virtual_address;
  uint32                        symbol_index;
  uint16                        rsvd;
  uint16                        type;
};

struct s_coff_symbol
{
  char                          name[8];
  uint32                        value;
  uint16                        section_number;
  uint16                        reserved;
  uint8                         storage_class;
  uint8                         auxiliary;
};

struct s_coff_auxiliary
{
  uint32                        section_length;
  uint16                        relocation_count;
  uint16                        line_count;
  uint8                         rsvd[10];
};

#pragma pack( pop )

#endif
// ---------------------------------------------------------------------------

uint32 cfg_revision = 0;

// ---------------------------------------------------------------------------
uint32 crc32( void* data, uint32 length, uint32 crc )
{
  static uint32 tab[256];
  static bool tab_init = false;
  uint8* cdata = (uint8*)data;
  int32 i, j;
  uint32 v;

  if( length == 0 ) return crc;
  
  if( !tab_init )
  {
    for( i = 0; i < 256; i++ )
    {
      v = i;
      for( j = 0; j < 8; j++ )
      {
        if( v & 1 ) v = ( v >> 1 ) ^ 0xedb88320; else v >>= 1;
      }
      tab[i] = v;
    }

    tab_init = true;
  }

  crc ^= 0xffffffff;
  while( length-- )
  {
    crc = tab[ ( crc ^ (*cdata) ) & 0xff ] ^ ( crc >> 8 );
    cdata++;
  }
  crc ^= 0xffffffff;

  return crc;
}
// ---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>
// ---------------------------------------------------------------------------
uint32 time_local()
{
  struct timeb timebp;
  ftime( &timebp );
  return (uint32)timebp.time + (uint32)( (int32)-timebp.timezone * 60 ) + (uint32)timebp.dstflag * 3600;
}
// ---------------------------------------------------------------------------
s_coff_section* coff_read_section_headers( FILE* f, uint32 count )
{
  int32 hdrlen = sizeof(s_coff_section) * count;

  s_coff_section* hdr = new s_coff_section[count];
  if( hdr == NULL ) return NULL;

  memset( hdr, 0, hdrlen );
  if( fread( hdr, hdrlen, 1, f ) != 1 )
  {
    delete[] hdr;
    return NULL;
  }

  return hdr;
}
// ---------------------------------------------------------------------------
char* coff_get_string( FILE* f, char* name, uint32 string_offset )
{
  uint32 a, t, l;
  char* r;
  char ch;

  if( name[0] == 0 )
  {
    a = (*((uint32*)( name + 4 )));
    t = ftell( f );
    fseek( f, string_offset + a, SEEK_SET );
    l = 0;
    while( true )
    {
      fread( &ch, 1, 1, f );
      l++;
      if( ch == 0 ) break;
    }
    r = new char[l+1];
    if( r == NULL )
    {
      fseek( f, t, SEEK_SET );
      return NULL;
    }
    fseek( f, string_offset + a, SEEK_SET );
    fread( r, l + 1, 1, f );
    fseek( f, t, SEEK_SET );
  }
  else
  {
    for( l = 0; l < 8; l++ ) if( name[l] == 0 ) break;
    r = new char[l+1];
    if( r == NULL ) return NULL;
    memcpy( r, name, l );
    r[l] = 0;
  }

  return r;
}
// ---------------------------------------------------------------------------
bool coff_read_symbol( FILE* f, s_coff_symbol* symbol, uint32 n, s_coff_header& header )
{
  uint32 t;
  bool r = false;
  if( n >= header.symbol_count ) return r;
  t = ftell( f );
  fseek( f, header.symbol_offset + n * sizeof(s_coff_symbol), SEEK_SET );
  if( fread( symbol, sizeof(s_coff_symbol), 1, f ) == 1 ) r = true;
  fseek( f, t, SEEK_SET );
  return r;
}
// ---------------------------------------------------------------------------
int32 get_slen( uint8* imag, uint32 l, int32& i )
{
  int32 r = 0;
  if( imag[i] == 0 ) return 0;
  while( true )
  {
    i++; r++;
    if( i >= (int32)l ) break;
    if( imag[i] != 1 ) break;
  }
  return r;
}
// ---------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  s_coff_header hdr;
  s_coff_opthdr opthdr;
  s_coff_section* shdr = NULL;
  FILE* f = NULL;
  FILE* fbin = NULL;
  char* sname = NULL;
  uint32 string_offset;
  int32 res;
  uint8* image = NULL;
  uint8* image_inter = NULL;
  uint32 image_length = 0;
  uint32 scount = 0;
  int32 i, j;
  uint32 olen;
  uint32 crc = 0;

  if( argc != 4 )
  {
    printf( "usage: mkcore-tms320c6x.exe <revision> <coff file name> <bin file name>\n" );
    return 0;
  }

  if( sscanf( argv[1], "%u", &cfg_revision ) != 1 )
  {
    fprintf( stderr, "Error: Can't parse revision number!\n" );
    goto l_fail;
  }

  if( ( f = fopen( argv[2], "rb" ) ) == NULL )
  {
    fprintf( stderr, "Error: Can't open file!\n" );
    goto l_fail;
  }
  
  fread( &hdr, sizeof(hdr), 1, f );
  string_offset = hdr.symbol_offset + sizeof(s_coff_symbol) * hdr.symbol_count;

  if( hdr.opthdr_length == sizeof(s_coff_opthdr) )
  {
    fread( &opthdr, sizeof(s_coff_opthdr), 1, f );
  }
  
  if( ( shdr = coff_read_section_headers( f, hdr.section_count ) ) != NULL )
  {
    // Create image
    image_length = 0;
    for( i = 0; i < hdr.section_count; i++ )
    {
      uint32 k = shdr[i].virtual_address + shdr[i].length;
      if( shdr[i].flags & COFF_STYP_NOLOAD ) continue;
      sname = coff_get_string( f, shdr[i].name, string_offset );
      if( strstr( sname, ".debug" ) != NULL )
      {
        delete[] sname;
        sname = NULL;
        continue;
      }
      delete[] sname;
      sname = NULL;
      if( k > image_length ) image_length = k;
    }

    if( image_length & 0x0000003f ) image_length = ( image_length & 0xffffffc0 ) + 64;
    
	image = new uint8[image_length];
    image_inter = new uint8[image_length];
    
	if( ( image == NULL ) || ( image_inter == NULL ) )
    {
      fprintf( stderr, "Error: Can't allocate memory for binary image!\n" );
      goto l_fail;
    }
    memset( image, 0, image_length );
    memset( image_inter, 0, image_length );

    printf( "mkcore: ------------------------------------------------------ read sections --\n" );
    printf( "mkcore:  address  : length   : section name                                    \n" );
    printf( "mkcore: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );

    // Load and relocate sections
    for( i = 0; i < hdr.section_count; i++ )
    {
      if( ( sname = coff_get_string( f, shdr[i].name, string_offset ) ) == NULL )
      {
        fprintf( stderr, "Error: Can't allocate memory for section name!\n" );
        goto l_fail;
      }
      if( strstr( sname, ".debug" ) != NULL )
      {
        printf( "mkcore:    -  -   :   -  -   : %s\n", sname );
        delete[] sname;
        sname = NULL;
        continue;
      }
      if( shdr[i].length == 0 )
      {
        printf( "mkcore:    -  -   :   -  -   : %s\n", sname );
        delete[] sname;
        sname = NULL;
        continue;
      }
      if( shdr[i].flags & COFF_STYP_NOLOAD )
      {
        printf( "mkcore:    -  -   :   -  -   : %s\n", sname );
        delete[] sname;
        sname = NULL;
        continue;
      }

      printf( "mkcore:  %08x : %08x : %s\n", shdr[i].virtual_address, shdr[i].length, sname );

      // Read section to memory
      fseek( f, shdr[i].raw_offset, SEEK_SET );
      int32 jl = (int32)shdr[i].length;
      if( jl & 3 ) jl = ( jl & 0xfffffffc ) + 4;
      for( j = 0; j < jl; j++ )
      {
        if( shdr[i].raw_offset == 0 )
        {
          image_inter[shdr[i].virtual_address+j] = 1;
          image[shdr[i].virtual_address+j] = 0;
          continue;
        }
        if( j < (int32)shdr[i].length )
        {
          if( image_inter[shdr[i].virtual_address+j] )
          {
            fprintf( stderr, "Error: Section intersection!\n" );
            goto l_fail;
          }
          image_inter[shdr[i].virtual_address+j] = 1;
          if( fread( &image[shdr[i].virtual_address+j], 1, 1, f ) != 1 )
          {
            fprintf( stderr, "Error: Can't read data from input COFF file!\n" );
            goto l_fail;
          }
        }
        else
        {
          image_inter[shdr[i].virtual_address+j] = 1;
        }
      }

      if( shdr[i].relocation_count != 0 )
      {
        fprintf( stderr, "Error: Not relocated section was detected (link core with option Absolute-Executable)!\n" );
        goto l_fail;
      }

      delete[] sname;
      sname = NULL;
    }
    delete[] shdr;
    shdr = NULL;
  }
  else
  {
    fprintf( stderr, "Error: Can't read section headers!\n" );
    goto l_fail;
  }

  printf( "mkcore: ----------------------------------------------------- write sections --\n" );
  printf( "mkcore:  address  : length                                                     \n" );
  printf( "mkcore: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );

  fbin = fopen( argv[3], "wb" );
  if( fbin == NULL )
  {
    fprintf( stderr, "Error: Can't create output bin file!\n" );
    goto l_fail;
  }

  // Determine section count
  for( i = 0; i < (int32)image_length; i++ )
  {
    j = get_slen( image_inter, image_length, i );
    if( j == 0 ) continue;
    scount++;
  }

  // Write LIF core image
  {
    s_lif_header header;
    s_lif_section* section;
    int32 s;

    section = new s_lif_section[scount];
    memset( &header, 0, sizeof(header) );
    memset( section, 0, sizeof(s_lif_section) * scount );

    // Fill LIF header
    header.magic = 0x3046494c;
    header.type = LIF_T_SEED;
    header.target = LIF_TGT_TMS320C64XX;
    header.length = sizeof(s_lif_header) + sizeof(s_lif_section) * scount;
    header.revision = cfg_revision;
    header.scount = scount;
    header.btime = time_local();
    crc = crc32( &header, 32, 0 );

    // Fill sections header
    for( s = 0, i = 0; i < (int32)image_length; i++ )
    {
      uint32 ti = i;
      j = get_slen( image_inter, image_length, i );
      if( j == 0 ) continue;
      section[s].magic = 0xf01ff10f;
      section[s].size = j;
      section[s].length = j;
      section[s].vaddr = ti;
      section[s].paddr = ti;
      section[s].flags = LIF_SF_STATIC;
      header.length += j;
      s++;
    }
    crc = crc32( section, sizeof(s_lif_section) * scount, crc );

    for( i = 0; i < (int32)image_length; i++ )
    {
      uint32 ti = i;
      j = get_slen( image_inter, image_length, i );
      if( j == 0 ) continue;
      crc = crc32( &image[ti], j, crc );
    }

    header.chk[0] = crc;
    olen = 0;

    fwrite( &header, sizeof(s_lif_header), 1, fbin );
    fwrite( section, sizeof(s_lif_section) * scount, 1, fbin );
    for( i = 0; i < (int32)image_length; i++ )
    {
      uint32 ti = i;
      j = get_slen( image_inter, image_length, i );
      if( j == 0 ) continue;
      olen += j;
      fwrite( &image[ti], j, 1, fbin );
      printf( "mkcore:  %08x : %08x\n", ti, j );
    }

    printf( "mkcore: ----------------------------------------------------- output summary --\n" );
    printf( "mkcore: output code size     : %d bytes\n", olen );
    printf( "mkcore: crc32                : %08x\n", crc );
    printf( "mkcore: -----------------------------------------------------------------------\n" );
  }

  res = 0;
  goto l_end;

l_fail:

  res = -1;

l_end:

  if( shdr ) delete[] shdr;
  if( image ) delete[] image;
  if( image_inter ) delete[] image_inter;
  if( f ) fclose( f );
  if( fbin ) fclose( fbin );

  return res;
}
// ---------------------------------------------------------------------------
