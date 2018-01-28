
#ifndef     _TPO_HASH_H
#define     _TPO_HASH_H

	#include <os_types.h>
	#include <crypto_hash.h>

//-------------------------------------------------------------------------------------------------


	struct fwmem_rwbuf
	{
	  void*                         buffer;
	  uint32                        length;
	};

	struct msg_hash_fwm
	{
	  int32           akn;
	  s_hash          hash;
	  s_hash          hash_fwm;
	};

	struct hash_window
	{
	  uint32          start_addr;
	  uint32          end_addr;
	};
//-------------------------------------------------------------------------------------------------
	extern const uint32 hash_bp[];
	extern const uint8  hash_start_vect0[];
//-------------------------------------------------------------------------------------------------

	uint32        cry_hash_fwmem(s_hash* ctx, void* start_vector, hash_window* hwin);
	uint32        hash_get(s_hash* ctx);
	uint32        analysis_hash_fwmem(hash_window* hwin);
	uint32        analysis_hash_fwmem_main(hash_window* hwin);

	uint32        hash_fwmem(hash_window* hwin, uint32 msg_pid_from);
//-------------------------------------------------------------------------------------------------
#endif //_TPO_HASH_H

