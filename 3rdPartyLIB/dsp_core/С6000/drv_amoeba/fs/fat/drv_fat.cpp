/** 
 * Драйвер FAT
 * 
 * @author Sergey Baigudin
 * @copyright 2014 RCZI
 * @version 0.1.0 
 */
#include <os.h>
//#include <rts_exception.h>
//#include <os_object.h>
#include <drv_fat.h>
#include <drv_fat_controller.hpp>

namespace drv_fat
{

  /**
   * Инициализация драйвера
   *
   * @return int32 OS error
   */
  int32 _iocInit(s_os_driver_context* ctx)
  {
    if( ctx->data != NULL ) return OSE_ALREADY_PLUGGED;
    ctx->data = new DrvFatController();
    if( ctx->data == NULL ) return OSE_NO_MEMORY;
    return ((DrvFatController*)ctx->data)->iocInit();
  }
  
  /**
   * Деинициализация драйвера
   *
   * @return int32 OS error 
   */
  int32 _iocDeinit(s_os_driver_context* ctx)
  {
    if( ctx->data == NULL ) return OSE_NO_DRIVER;
    DrvFatController* drv = (DrvFatController*)ctx->data;
    int32 error = drv->iocDeinit();
    if(error == OSE_OK) delete drv;
    return error;
  }
  
  /**
   * Инициализация дескриптора
   *
   * @return int32 OS error
   */
  int32 _iocInitDescriptor(s_os_driver_descriptor* d)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Деинициализация дескриптора
   *
   * @return int32 OS error
   */
  int32 _iocDeinitDescriptor(s_os_driver_descriptor* d)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Анализ конца потока
   *
   * @return int32 OS error
   */
  int32 _iocEof(s_os_driver_descriptor* d, int32* arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Установить смещение в потоке
   *
   * @return int32 OS error
   */
  int32 _iocSeek(s_os_driver_descriptor* d, int64* arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Размер потока
   *
   * @return int32 OS error
   */
  int32 _iocSize(s_os_driver_descriptor* d, int64* arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Текущая позиция в потоке
   *
   * @return int32 OS error
   */
  int32 _iocPosition(s_os_driver_descriptor* d, int64* arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Удаление данных из потока
   *
   * @return int32 OS error
   */
  int32 _iocResize(s_os_driver_descriptor* d)
  {
    return OSE_OK;
  }
  
  /**
   * Получение списка файлов
   *
   * @return int32 OS error
   */
  int32 _iocInodeList(s_os_driver_descriptor* d, s_inode** arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Выбор директории
   *
   * @return int32 OS error
   */
  int32 _iocInodeSelect(s_os_driver_descriptor* d, char* arg)
  {
    return OSE_BAD_CMD;
  }
  
  /**
   * Открытие потока
   *
   * @return int32 OS error
   */
  int32 _drvOpen(s_os_driver_descriptor* d, uint16 access)
  {
    return OSE_CANT_OPEN;
  }
  
  /**
   * Закрытие потока
   *
   * @return int32 OS error
   */
  int32 _drvClose(s_os_driver_descriptor* d)
  {
    return OSE_STREAM_NOT_OPENED;
  }
  
  /**
   * Чтение из потока
   *
   * @return int32 OS error
   */
  int32 _drvRead(s_os_driver_descriptor* d, void* buf, int32 length)
  {
    return OSE_PERMISSION_DENIED;
  }
  
  /**
   * Запись в поток
   *
   * @return int32 OS error
   */
  int32 _drvWrite(s_os_driver_descriptor* d, const void* buf, int32 length)
  {
    return OSE_PERMISSION_DENIED;
  }
  
  /**
   * Управление вводом/выводом
   *
   * @return int32 OS error
   */
  int32 _drvIoctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
  {
    switch(cmd)
    {
      case IOC_INIT: return _iocInit((s_os_driver_context*)arg);
      case IOC_DEINIT: return _iocDeinit((s_os_driver_context*)arg);
      case IOC_INIT_DESCRIPTOR: return _iocInitDescriptor(d);
      case IOC_DEINIT_DESCRIPTOR: return _iocDeinitDescriptor(d);
      case IOC_EOF: return  _iocEof(d, (int32*)arg);    
      case IOC_SEEK: return _iocSeek(d, (int64*)arg);
      case IOC_SIZE: return _iocSize(d, (int64*)arg);
      case IOC_POSITION: return _iocPosition(d, (int64*)arg);
      case IOC_RESIZE: return _iocResize(d);
      case IOC_INODE_LIST: return _iocInodeList(d, (s_inode**)arg);    
      case IOC_INODE_SELECT: return _iocInodeSelect(d, (char*)arg);
    }
    return OSE_BAD_CMD;
  }

  /**
   * Добавить драйвер в систему
   *
   * @return int32 OS error
   */
  int32 plug()
  {
    try
    {
      int32 error = 0;      
      DrvFatController* drv = new DrvFatController();
      error = drv->somethrow(0);    
      return error;  
    }
    catch(Throwable)
    {
      asm(" nop");
    }
  
    return drv_plug("/vfat", INOT_FOLDER, &_drvOpen, &_drvClose, &_drvRead, &_drvWrite, &_drvIoctl, NULL, 0);
  }

  /**
   * Удалить драйвер из системы 
   *
   * @return int32 OS error
   */
  int32 unplug()
  {
    return drv_unplug("vfat");
  }
}
