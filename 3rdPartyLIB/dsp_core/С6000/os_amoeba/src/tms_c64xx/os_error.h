/** 
 * System error codes.
 * 
 * @copyright 2012-2015 RCZI
 */
#ifndef OS_ERROR_H_  
#define OS_ERROR_H_

enum Error
{
  OSE_OK                        =  0,     // No comments ^_^
  OSE_NO_MEMORY                 = -1,     // Can't allocate memory
  OSE_NO_DEVICE                 = -2,     // Can't open device or file
  OSE_BAD_RDESC                 = -3,     // Bad resource (interrupt,semaphore,file,...) descriptor
  OSE_BAD_PARAM                 = -4,     // Bad parameter value
  OSE_NULL_PARAM                = -5,     // Null value for some parameter not allowed
  OSE_CANT_OPEN                 = -6,     // Can't open device/file in stream mode
  OSE_CANT_READ                 = -7,     // Can't read from device/file
  OSE_CANT_WRITE                = -8,     // Can't write to device/file
  OSE_CANT_CREATE_HEAP          = -9,     // Can't allocate memory for process heap
  OSE_CANT_CREATE_STACK         = -10,    // Can't allocate memory for process stack
  OSE_MSG_ALLREADY_STARTED      = -11,    // System exchange allready started
  OSE_LIF_BAD_HEADER            = -12,    // Bad LIF file format header
  OSE_LIF_WRONG_TARGET_CPU      = -13,    // Wrong target CPU in LIF file
  OSE_LIF_BAD_SECTION_HEADER    = -14,    // Bad LIF section header
  OSE_LIF_CANT_APPLY_PATCH      = -15,    // Cant apply LIF patch for code (bad patch format)
  OSE_TOO_LONG_STRING           = -16,    // Argument string is too long
  OSE_ALLREADY_NAMED            = -17,    // System allready named
  OSE_TOO_SHORT_BUFFER          = -18,    // Argument buffer is too short
  OSE_FAIL                      = -19,    // Fail status
  OSE_CANT_CREATE_SEM           = -20,    // Can't create semaphore
  OSE_MSG_STREAM_NOT_OPENED     = -21,    // Message stream not opened with function msg_open
  OSE_MSG_BAD_DST_ADDRESS       = -22,    // Bad message destination address
  OSE_VOID_RESOURCE             = -23,    // Void resource
  OSE_SEM_DESTROYED             = -24,    // Semaphore was destroyed
  OSE_SEM_NOT_REGISTERED        = -25,    // Semaphore not registered
  OSE_TIMEOUT                   = -26,    // Time out
  OSE_SEM_LOCKED                = -27,    // Semaphore locked
  OSE_SEM_UNLOCKED              = -28,    // Semaphore unlocked
  OSE_NO_EXTENSION              = -29,    // Extension not loaded or not supported
  OSE_EXTENSION_PLUGGED         = -30,    // Extension allready plugged
  OSE_EXTENSION_BAD_HEADER      = -31,    // Extension have bad header
  OSE_EXTENSION_F_PLUGGED       = -32,    // One or more functions from extension packet allready plugged
  OSE_CANT_CREATE_PROCESS       = -33,    // System can't create or start process
  OSE_BAD_DCTX                  = -34,    // Bad context pointer in device descriptor
  OSE_PERMISSION_DENIED         = -35,    // Some action not permitted
  OSE_BAD_DATA                  = -36,    // Some data is bad
  OSE_ALREADY_PLUGGED           = -37,    // Driver allready plugged
  OSE_CANT_CREATE_INTERRUPT     = -38,    // No free interrupt handle
  OSE_SIDE_TEST_ERROR           = -39,    // Side test of anything error
  OSE_DATA_TEST_ERROR           = -40,    // Data test of anything error
  OSE_ADDRESS_TEST_ERROR        = -41,    // Address test of anything error
  OSE_TOO_MANY_DATA             = -42,    // Too many portion of data, you must shrink <length> parameter
  OSE_DIFFERENT_LENGTH          = -43,    // Some two lengths is different
  OSE_DATA_ALIGNED              = -44,    // Some data was aligned
  OSE_CANT_LOCK_SEM             = -45,    // Can't lock semaphore
  OSE_NO_ELEMENT                = -46,    // Something have no element (for example no elements in list)
  OSE_BAD_CMD                   = -47,    // Bad ioctl command code
  OSE_NO_NODE                   = -48,    // Current index node have no subnode with specifyed name
  OSE_CANT_RESET_PARAM          = -49,    // Can't set new value for some parameter
  OSE_NO_PROCESS                = -50,    // No such process
  OSE_BAD_RESOURCE_TYPE         = -51,    // Bad resource type
  OSE_ALREADY_ADDED             = -52,    // Something already added somewhere
  OSE_NO_ROUTE                  = -53,    // No route
  OSE_SYN_FAIL                  = -54,    // Synchronization error
  OSE_NOT_ENOUGHT_DATA          = -55,    // Not enought data
  OSE_ALLREADY_SET              = -56,    // Some parameter allready set
  OSE_DROPPED                   = -57,    // Something dropped
  OSE_STREAM_OPENED             = -58,    // Some stream is opened
  OSE_STREAM_NOT_OPENED         = -59,    // Some stream is not opened
  OSE_NOT_INITIALIZED           = -60,    // Somthing not initialized
  OSE_TOO_BIG_PROCESS_ID        = -61,    // Too big process id
  OSE_BAD_ACTION                = -62,    // Bad action
  OSE_OUT_OF_A_RANGE            = -63,    // Some value out of a it's range
  OSE_SYN_TIMEOUT               = -64,    // Synchronization timeout
  OSE_DRIVER_UNLOADED           = -65,    // Driver was unloaded from memory
  OSE_NO_DRIVER                 = -66,    // Can't find driver
  OSE_NODE_EXISTS               = -67,    // Some named node allready exists
  OSE_LOOPBACK_PHY              = -68,    // Loopback transmission failed
  OSE_WRONG_QUEUE_SIZE          = -69,    // Wrong queue size
  OSE_RTC_WRITE                 = -70,    // Can't write into RTC chip
  OSE_RTC_READ                  = -71,    // Can't read from RTC chip
  OSE_RTC_TEST                  = -72,    // RTC chip read/write test failed
  OSE_RTC_TICK                  = -73,    // RTC chip work test failed
  OSE_NO_PHY                    = -74,    // No physical part of anything
  OSE_PHY_ERROR                 = -75,    // Physical part of anything initialization error
  OSE_LINK_TEST                 = -76,    // Link test error
  OSE_NAME_EXISTS               = -77,    // Specifyed name of anything already exists
  OSE_BAD_NAME                  = -78,    // Bad name
  OSE_RESOURCE_BUSY             = -79,    // Some resource is busy
  OSE_RESOURCE_POOL_BUSY        = -80,    // Driver for specifyed resource type allready plugged
  OSE_RESOURCE_LIMIT_REACHED    = -81,    // Curent resource type limit reached
  OSE_BAD_RESOURCE_INDEX        = -82,    // Bad resource index
  OSE_NO_DATA                   = -83     // No data
};
#endif //OS_ERROR_H_
