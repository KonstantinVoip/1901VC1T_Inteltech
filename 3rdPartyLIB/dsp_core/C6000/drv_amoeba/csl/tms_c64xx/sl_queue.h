#ifndef __Static_Loop_Queue_H__
#define __Static_Loop_Queue_H__

// --------------------------------------------------------------------------
// Обязательно проинициализировать SLQ_TYPE перед использованием 
// каких-либо макросов
// --------------------------------------------------------------------------
// Пример: #define SLQ_TYPE uint32
// --------------------------------------------------------------------------

#include <os_types.h>

// --------------------------------------------------------------------------
// Макрос инициализации очереди
// >> name  - имя очереди
// >> depth - глубина очереди: <кол-во элементов в очереди> = 2^depth - 1
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
// Макрос очистки очереди
// ---
#define SLQ_CLEAN(name) \
  memset(&name##_queue,0,sizeof(name##_queue)); \
  name##_begin = 0; \
  name##_end = 0

// --------------------------------------------------------------------------
// Макрос возвращает кол-во элементов в очереди
// ---
#define SLQ_USED_SPACE(name) slq_used_space( name##_begin, name##_end, name##_length )

// --------------------------------------------------------------------------
// Макрос проверяет наличае свободного места в очереди
// ---
#define SLQ_HAVE_SPACE(name) ( slq_have_space( name##_begin, name##_end, name##_length ) == 1 )

// --------------------------------------------------------------------------
// Макрос проверяет наличае объектов в очереди
// ---
#define SLQ_HAVE_OBJECT(name) ( name##_begin != name##_end )

// --------------------------------------------------------------------------
// Макрос вставляет объект в очередь, так чтобы тот был первым на извлечение
// ---
#define SLQ_INSERT_TO_BE_FIRST(name,object) \
  name##_begin = ( name##_begin - 1 ) & name##_lmask; \
  memcpy( &name##_queue[name##_begin], &object, sizeof(SLQ_TYPE) )

// --------------------------------------------------------------------------
// Макрос вставляет объект в очередь, так чтобы тот был последним на извлечение
// ---
#define SLQ_INSERT_TO_BE_LAST(name,object) \
  memcpy( &name##_queue[name##_end], &object, sizeof(SLQ_TYPE) ); \
  name##_end = ( name##_end + 1 ) & name##_lmask; \

// --------------------------------------------------------------------------
// Макрос получает первый объект из очереди
// ---
#define SLQ_GET_FIRST(name,object) \
  memcpy( object, &name##_queue[name##_begin], sizeof(SLQ_TYPE) ); \
  name##_begin = ( name##_begin + 1 ) & name##_lmask
  
// --------------------------------------------------------------------------
// Макрос получает последний объект из очереди
// ---
#define SLQ_GET_LAST(name,object) \
  name##_end = ( name##_end - 1 ) & name##_lmask; \
  memcpy( object, &name##_queue[name##_end], sizeof(SLQ_TYPE) )

// --------------------------------------------------------------------------
// Макрос распечатывает все переменные очереди
// ---
#define SLQ_DEBUG(name) \
  printf( "  name##_begin  = %ld\n", name##_begin ); \
  printf( "  name##_end    = %ld\n", name##_end ); \
  printf( "  name##_length = %ld\n", name##_length ); \
  printf( "  name##_lmask  = %ld\n", name##_lmask )

// --------------------------------------------------------------------------
// Вспомогательные фукции
// ---
extern char slq_have_space( uint32 begin, uint32 end, uint32 length );
extern uint32 slq_used_space( uint32 begin, uint32 end, uint32 length );

#endif
