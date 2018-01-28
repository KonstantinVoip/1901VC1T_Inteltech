/** 
 * ������� FAT
 * 
 * @author Sergey Baigudin
 * @copyright 2014 RCZI
 * @version 0.1.0 
 */
#include <os.h>
#include <drv_controller.hpp>

class DrvFatController : public DrvController
{
  private:

  public:

  /** 
   * �����������
   * 
   * @return void
   */
  DrvFatController()
  {
    asm(" nop");
  }

  /** 
   * ����������
   * 
   * @return void
   */
  ~DrvFatController()
  {
    asm(" nop");
  }

  int32 somethrow( int32 arg )
  {
    if(arg == 0)
      throw Throwable();
    return 0;
  }

  /**
   * ������������� ��������
   *
   * @return int32 OS error
   */
  int32 iocInit()
  {
    return OSE_OK;
  }

  /**
   * ��������������� ��������
   *
   * @return int32 OS error 
   */
  int32 iocDeinit()
  {
    return OSE_OK;
  }
};
