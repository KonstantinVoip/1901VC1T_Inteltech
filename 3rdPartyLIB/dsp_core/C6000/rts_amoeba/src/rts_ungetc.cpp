// ---------------------------------------------------------------------------
// int ungetc( int c, FILE* stream )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int ungetc( int c, FILE* stream )
{
  if( stream == NULL ) return EOF;
  if( stream->ungetc_count == FILE_UNGETC_BUFSIZE ) return EOF;
  stream->ungetc_buf[stream->ungetc_count] = (uint8)c;
  stream->ungetc_count++;
  return c;
}
// ---------------------------------------------------------------------------
