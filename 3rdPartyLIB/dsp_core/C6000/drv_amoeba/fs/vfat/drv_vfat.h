#ifndef __DRV_VFat_H__
#define __DRV_VFat_H__

struct s_vfat_info
{
  uint16 type;
};

struct s_vfat_format
{
  void   (*func)(uint32,uint32,void*);
  void*  arg;
};

extern int32 drv_vfat_trigger_plug();
extern int32 drv_vfat_trigger_unplug();

#endif
