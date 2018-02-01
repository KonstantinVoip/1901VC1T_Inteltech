#include "sl_queue.h"

uint32 slq_used_space( uint32 begin, uint32 end, uint32 length )
{
  if( end < begin ) end += length;
  return ( end - begin );
}

char slq_have_space( uint32 begin, uint32 end, uint32 length )
{
  if( slq_used_space( begin, end, length ) == ( length - 1 ) ) return 0;
  return 1;
}
