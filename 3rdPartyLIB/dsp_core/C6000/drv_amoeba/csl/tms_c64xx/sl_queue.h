#ifndef __Static_Loop_Queue_H__
#define __Static_Loop_Queue_H__

// --------------------------------------------------------------------------
// ��易⥫쭮 �ந��樠����஢��� SLQ_TYPE ��। �ᯮ�짮������ 
// �����-���� ����ᮢ
// --------------------------------------------------------------------------
// �ਬ��: #define SLQ_TYPE uint32
// --------------------------------------------------------------------------

#include <os_types.h>

// --------------------------------------------------------------------------
// ����� ���樠����樨 ��।�
// >> name  - ��� ��।�
// >> depth - ��㡨�� ��।�: <���-�� ����⮢ � ��।�> = 2^depth - 1
//            depth = [ 1; 31 ]
// ---
#define SLQ_INIT(name,depth) \
  SLQ_TYPE name##_queue[1<<depth]; \
  uint32 name##_begin = 0; \
  uint32 name##_end = 0; \
  uint32 name##_length = 1<<depth; \
  uint32 name##_lmask = (1<<depth)-1

#define SLQ_EXTERN(name,depth) \
  extern SLQ_TYPE name##_queue[1<<depth]; \
  extern uint32 name##_begin ; \
  extern uint32 name##_end ; \
  extern uint32 name##_length ; \
  extern uint32 name##_lmask

// --------------------------------------------------------------------------
// ����� ���⪨ ��।�
// ---
#define SLQ_CLEAN(name) \
  memset(&name##_queue,0,sizeof(name##_queue)); \
  name##_begin = 0; \
  name##_end = 0

// --------------------------------------------------------------------------
// ����� �����頥� ���-�� ����⮢ � ��।�
// ---
#define SLQ_USED_SPACE(name) slq_used_space( name##_begin, name##_end, name##_length )

// --------------------------------------------------------------------------
// ����� �஢���� ����砥 ᢮������� ���� � ��।�
// ---
#define SLQ_HAVE_SPACE(name) ( slq_have_space( name##_begin, name##_end, name##_length ) == 1 )

// --------------------------------------------------------------------------
// ����� �஢���� ����砥 ��ꥪ⮢ � ��।�
// ---
#define SLQ_HAVE_OBJECT(name) ( name##_begin != name##_end )

// --------------------------------------------------------------------------
// ����� ��⠢��� ��ꥪ� � ��।�, ⠪ �⮡� �� �� ���� �� �����祭��
// ---
#define SLQ_INSERT_TO_BE_FIRST(name,object) \
  name##_begin = ( name##_begin - 1 ) & name##_lmask; \
  memcpy( &name##_queue[name##_begin], &object, sizeof(SLQ_TYPE) )

// --------------------------------------------------------------------------
// ����� ��⠢��� ��ꥪ� � ��।�, ⠪ �⮡� �� �� ��᫥���� �� �����祭��
// ---
#define SLQ_INSERT_TO_BE_LAST(name,object) \
  memcpy( &name##_queue[name##_end], &object, sizeof(SLQ_TYPE) ); \
  name##_end = ( name##_end + 1 ) & name##_lmask; \

// --------------------------------------------------------------------------
// ����� ����砥� ���� ��ꥪ� �� ��।�
// ---
#define SLQ_GET_FIRST(name,object) \
  memcpy( object, &name##_queue[name##_begin], sizeof(SLQ_TYPE) ); \
  name##_begin = ( name##_begin + 1 ) & name##_lmask
  
// --------------------------------------------------------------------------
// ����� ����砥� ��᫥���� ��ꥪ� �� ��।�
// ---
#define SLQ_GET_LAST(name,object) \
  name##_end = ( name##_end - 1 ) & name##_lmask; \
  memcpy( object, &name##_queue[name##_end], sizeof(SLQ_TYPE) )

// --------------------------------------------------------------------------
// ����� �ᯥ��뢠�� �� ��६���� ��।�
// ---
#define SLQ_DEBUG(name) \
  printf( "  name##_begin  = %ld\n", name##_begin ); \
  printf( "  name##_end    = %ld\n", name##_end ); \
  printf( "  name##_length = %ld\n", name##_length ); \
  printf( "  name##_lmask  = %ld\n", name##_lmask )

// --------------------------------------------------------------------------
// �ᯮ����⥫�� ��樨
// ---
extern char slq_have_space( uint32 begin, uint32 end, uint32 length );
extern uint32 slq_used_space( uint32 begin, uint32 end, uint32 length );

#endif
