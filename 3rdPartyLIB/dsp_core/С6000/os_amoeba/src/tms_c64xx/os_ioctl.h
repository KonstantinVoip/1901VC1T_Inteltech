// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит стандартные коды команд управления драйверами.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_IOControl_H__
#define __OS_IOControl_H__

// -- Standard ioctl calls ---------------------------------------------------

#define IOC__BASE__                     0x00000000

#define IOC_INIT                        ( IOC__BASE__ + 0 )
#define IOC_DEINIT                      ( IOC__BASE__ + 1 )
#define IOC_SHUTDOWN                    ( IOC__BASE__ + 2 )

#define IOC_INIT_DESCRIPTOR             ( IOC__BASE__ + 3 )
#define IOC_DEINIT_DESCRIPTOR           ( IOC__BASE__ + 4 )

#define IOC_EOF                         ( IOC__BASE__ + 5 )
#define IOC_SEEK                        ( IOC__BASE__ + 6 )
#define IOC_SIZE                        ( IOC__BASE__ + 7 )
#define IOC_POSITION                    ( IOC__BASE__ + 8 )
#define IOC_RESIZE                      ( IOC__BASE__ + 9 )

#define IOC_INODE_LIST                  ( IOC__BASE__ + 10 )
#define IOC_INODE_SELECT                ( IOC__BASE__ + 11 )
#define IOC_INODE_CREATE                ( IOC__BASE__ + 12 )
#define IOC_INODE_REMOVE                ( IOC__BASE__ + 13 )
#define IOC_INODE_RENAME                ( IOC__BASE__ + 14 )

// -- Interprocessor message pipe calls --------------------------------------

#define IPMP__BASE__                    0x00001000
#define IPMP_STAT                       ( IPMP__BASE__ + 0 )
#define IPMP__USER__                    ( IPMP__BASE__ + 1 )

// -- Netcard calls ----------------------------------------------------------

#define NET__BASE__                     0x00001100

#define NET_RECV_GET                    ( NET__BASE__ + 0 )
#define NET_RECV_PUT                    ( NET__BASE__ + 1 )
#define NET_SEND_GET                    ( NET__BASE__ + 2 )
#define NET_SEND_PUT                    ( NET__BASE__ + 3 )

#define NET_HOST_RECV_GET               ( NET__BASE__ + 4 )
#define NET_HOST_RECV_PUT               ( NET__BASE__ + 5 )
#define NET_HOST_SEND_GET               ( NET__BASE__ + 6 )
#define NET_HOST_SEND_PUT               ( NET__BASE__ + 7 )

#define NET_SET_CONFIG                  ( NET__BASE__ + 10 )
#define NET_SET_CONFIG_CALLBACK         ( NET__BASE__ + 11 )
#define NET_GET_CONFIG                  ( NET__BASE__ + 12 )
#define NET_UP                          ( NET__BASE__ + 13 )
#define NET_DOWN                        ( NET__BASE__ + 14 )
#define NET_LINK                        ( NET__BASE__ + 15 )

#define NET__USER__                     ( NET__BASE__ + 16 )

// -- Firmware memory calls --------------------------------------------------

#define FWMEM__BASE__                   0x00001200

#define FWMEM_SECTOR_COUNT              ( FWMEM__BASE__ + 0 )
#define FWMEM_SECTOR_SIZE               ( FWMEM__BASE__ + 1 )
#define FWMEM_SECTOR_CLEAR              ( FWMEM__BASE__ + 2 )
#define FWMEM_SET_OFFSET                ( FWMEM__BASE__ + 3 )
#define FWMEM_WRITE                     ( FWMEM__BASE__ + 4 )
#define FWMEM_READ                      ( FWMEM__BASE__ + 5 )
#define FWMEM_SIZE                      ( FWMEM__BASE__ + 6 )

#define FWMEM__USER__                   ( FWMEM__BASE__ + 7 )

// -- LED calls --------------------------------------------------------------

#define LED__BASE__                     0x00001300

#define LED_SETCOLOR                    ( LED__BASE__ + 0 )
#define LED_GETCOLOR                    ( LED__BASE__ + 1 )

#define LED__USER__                     ( LED__BASE__ + 2 )

// -- Console calls ----------------------------------------------------------

#define CON__BASE__                     0x00001400

//#define CON_SETSIZE                     ( CON__BASE__ + 0 )
//#define CON_GETSIZE                     ( CON__BASE__ + 0 )
//#define CON_SETSIZE                     ( CON__BASE__ + 0 )

// -- GPIO calls -------------------------------------------------------------

#define GPIO__BASE__                    0x00001500

#define GPIO_INT_ALLOC                  ( GPIO__BASE__ + 0 )
#define GPIO_INT_FREE                   ( GPIO__BASE__ + 1 )
#define GPIO_PULL                       ( GPIO__BASE__ + 2 )
#define GPIO_VALUE                      ( GPIO__BASE__ + 3 )
#define GPIO_LOCK                       ( GPIO__BASE__ + 4 )
#define GPIO_UNLOCK                     ( GPIO__BASE__ + 5 )

#define GPIO__USER__                    ( GPIO__BASE__ + 6 )

// -- Video card (or display) calls ------------------------------------------

#define GDEV__BASE__                    0x00001600

#define GDEV_MODE                       ( GDEV__BASE__ + 0  )
#define GDEV_RESOLUTION                 ( GDEV__BASE__ + 1  )

#define GDEV_CURSOR_VISIBILITY          ( GDEV__BASE__ + 2  )
#define GDEV_CURSOR_POSITION            ( GDEV__BASE__ + 3  )
#define GDEV_CURSOR_HEIGHT              ( GDEV__BASE__ + 4  )
#define GDEV_KEYGEN_LOAD                ( GDEV__BASE__ + 5  )

#define GDEV_PIXEL                      ( GDEV__BASE__ + 6  )
#define GDEV_LINE                       ( GDEV__BASE__ + 7  )
#define GDEV_HLINE                      ( GDEV__BASE__ + 8  )
#define GDEV_VLINE                      ( GDEV__BASE__ + 9  )
#define GDEV_MOVETO                     ( GDEV__BASE__ + 10 )
#define GDEV_LINETO                     ( GDEV__BASE__ + 11 )
#define GDEV_RECT                       ( GDEV__BASE__ + 12 )
#define GDEV_FRECT                      ( GDEV__BASE__ + 13 )
#define GDEV_TEXT                       ( GDEV__BASE__ + 14 )
#define GDEV_IMAGE                      ( GDEV__BASE__ + 15 )
#define GDEV_VGRAD                      ( GDEV__BASE__ + 16 )
#define GDEV_HGRAD                      ( GDEV__BASE__ + 17 )
#define GDEV_COLOR                      ( GDEV__BASE__ + 18 )

#define GDEV_GL_CONTEXT                 ( GDEV__BASE__ + 19 )

#define GDEV__USER__                    ( GDEV__BASE__ + 20 )

// -- File system calls ------------------------------------------------------

#define FSI__BASE__                     0x00001700

#define FSI_TYPE                        ( FSI__BASE__ + 0 )
#define FSI_FORMAT                      ( FSI__BASE__ + 1 )
#define FSI_RESET                       ( FSI__BASE__ + 2 )

#define FSI__USER__                     ( FSI__BASE__ + 3 )

// -- Human Interface Devices calls ------------------------------------------

#define HID_DEVICE( event )             ( event & 0xf0000000 )

#define HID_NOEVENT                     0x00000000
#define HID_DEVICE_KEYBOARD             0x10000000
#define HID_DEVICE_MOUSE                0x20000000

// -- Keyboard - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define HID_KEYBOARD_EVENT( event )     ( event & 0x01000000 )

#define HID_KEYBOARD_PRESS              0x00000000
#define HID_KEYBOARD_RELEASE            0x01000000

// -- Keyboard scan codes  - - - - - - - - - - - - - - - - - - - - - - - - - -

#define HID_KEYBOARD_SCANCODE( event )  ((uint16)( event & 0x0000ffff ))

#define KB_NO_EVENT                             0x0000
#define KB_ERROE_ROLL_OVER                      0x0001
#define KB_POST_FAIL                            0x0002
#define KB_ERROR_UNDEFINED                      0x0003
#define KB_A                                    0x0004
#define KB_B                                    0x0005
#define KB_C                                    0x0006
#define KB_D                                    0x0007
#define KB_E                                    0x0008
#define KB_F                                    0x0009
#define KB_G                                    0x000a
#define KB_H                                    0x000b
#define KB_I                                    0x000c
#define KB_J                                    0x000d
#define KB_K                                    0x000e
#define KB_L                                    0x000f
#define KB_M                                    0x0010
#define KB_N                                    0x0011
#define KB_O                                    0x0012
#define KB_P                                    0x0013
#define KB_Q                                    0x0014
#define KB_R                                    0x0015
#define KB_S                                    0x0016
#define KB_T                                    0x0017
#define KB_U                                    0x0018
#define KB_V                                    0x0019
#define KB_W                                    0x001a
#define KB_X                                    0x001b
#define KB_Y                                    0x001c
#define KB_Z                                    0x001d
#define KB_1                                    0x001e
#define KB_2                                    0x001f
#define KB_3                                    0x0020
#define KB_4                                    0x0021
#define KB_5                                    0x0022
#define KB_6                                    0x0023
#define KB_7                                    0x0024
#define KB_8                                    0x0025
#define KB_9                                    0x0026
#define KB_0                                    0x0027
#define KB_ENTER                                0x0028
#define KB_ESCAPE                               0x0029
#define KB_BACKSPACE                            0x002a
#define KB_TAB                                  0x002b
#define KB_SPACE                                0x002c
#define KB_DASH_AND_UNDERSCORE                  0x002d
#define KB_EQUAL_AND_PLUS                       0x002e
#define KB_BRACKET_OPEN                         0x002f
#define KB_BRACKET_CLOSE                        0x0030
#define KB_BACKSLASH                            0x0031
#define KB_NON_US_1                             0x0032
#define KB_SEMI                                 0x0033
#define KB_QUOTE                                0x0034
#define KB_GRAVE_ACCENT_AND_TILDE               0x0035
#define KB_COMMA_LESS                           0x0036
#define KB_DOT_GREATER                          0x0037
#define KB_SLASH_QUERY                          0x0038
#define KB_CAPS_LOCK                            0x0039
#define KB_F1                                   0x003a
#define KB_F2                                   0x003b
#define KB_F3                                   0x003c
#define KB_F4                                   0x003d
#define KB_F5                                   0x003e
#define KB_F6                                   0x003f
#define KB_F7                                   0x0040
#define KB_F8                                   0x0041
#define KB_F9                                   0x0042
#define KB_F10                                  0x0043
#define KB_F11                                  0x0044
#define KB_F12                                  0x0045
#define KB_PRINT_SCREEN                         0x0046
#define KB_SCROLL_LOCK                          0x0047
#define KB_PAUSE                                0x0048
#define KB_INSERT                               0x0049
#define KB_HOME                                 0x004a
#define KB_PAGE_UP                              0x004b
#define KB_DELETE_FORWARD                       0x004c
#define KB_END                                  0x004d
#define KB_PAGE_DOWN                            0x004e
#define KB_RIGHT_ARROW                          0x004f
#define KB_LEFT_ARROW                           0x0050
#define KB_DOWN_ARROW                           0x0051
#define KB_UP_ARROW                             0x0052
#define KP_NUM_LOCK_AND_CLEAR                   0x0053
#define KP_SLASH                                0x0054
#define KP_MULTIPLY                             0x0055
#define KP_MINUS                                0x0056
#define KP_PLUS                                 0x0057
#define KP_ENTER                                0x0058
#define KP_1_AND_END                            0x0059
#define KP_2_AND_DOWN_ARROW                     0x005a
#define KP_3_AND_PAGE_DOWN                      0x005b
#define KP_4_AND_LEFT_ARROR                     0x005c
#define KP_5                                    0x005d
#define KP_6_AND_RIGHT_ARROR                    0x005e
#define KP_7_AND_HOME                           0x005f
#define KP_8_AND_UP_ARROW                       0x0060
#define KP_9_AND_PAGE_UP                        0x0061
#define KP_0_AND_INSERT                         0x0062
#define KP_DOT_AND_DELETE                       0x0063
#define KB_NON_US_2                             0x0064
#define KB_APPLICATION                          0x0065
#define KB_POWER                                0x0066
#define KP_EQUAL                                0x0067
#define KB_F13                                  0x0068
#define KB_F14                                  0x0069
#define KB_F15                                  0x006a
#define KB_F16                                  0x006b
#define KB_F17                                  0x006c
#define KB_F18                                  0x006d
#define KB_F19                                  0x006e
#define KB_F20                                  0x006f
#define KB_F21                                  0x0070
#define KB_F22                                  0x0071
#define KB_F23                                  0x0072
#define KB_F24                                  0x0073
#define KB_EXECUTE                              0x0074
#define KB_HELP                                 0x0075
#define KB_MENU                                 0x0076
#define KB_SELECT                               0x0077
#define KB_STOP                                 0x0078
#define KB_AGAIN                                0x0079
#define KB_UNDO                                 0x007a
#define KB_CUT                                  0x007b
#define KB_COPY                                 0x007c
#define KB_PASTE                                0x007d
#define KB_FIND                                 0x007e
#define KB_MUTE                                 0x007f
#define KB_VOLUME_UP                            0x0080
#define KB_VOLUME_DOWN                          0x0081
#define KB_LOCKING_CAPS_LOCK                    0x0082
#define KB_LOCKING_NUM_LOCK                     0x0083
#define KB_LOCKING_SCROLL_LOCK                  0x0084
#define KP_COMMA                                0x0085
#define KP_EQUAL_SIGN                           0x0086
#define KB_INTERNATIONAL_1                      0x0087
#define KB_INTERNATIONAL_2                      0x0088
#define KB_INTERNATIONAL_3                      0x0089
#define KB_INTERNATIONAL_4                      0x008a
#define KB_INTERNATIONAL_5                      0x008b
#define KB_INTERNATIONAL_6                      0x008c
#define KB_INTERNATIONAL_7                      0x008d
#define KB_INTERNATIONAL_8                      0x008e
#define KB_INTERNATIONAL_9                      0x008f
#define KB_LANG_1                               0x0090
#define KB_LANG_2                               0x0091
#define KB_LANG_3                               0x0092
#define KB_LANG_4                               0x0093
#define KB_LANG_5                               0x0094
#define KB_LANG_6                               0x0095
#define KB_LANG_7                               0x0096
#define KB_LANG_8                               0x0097
#define KB_LANG_9                               0x0098
#define KB_ALTERNATE_ERASE                      0x0099
#define KB_SYSREQ_ATTENTION                     0x009a
#define KB_CANCEL                               0x009b
#define KB_CLEAR                                0x009c
#define KB_PRIOR                                0x009d
#define KB_RETURN                               0x009e
#define KB_SEPARATOR                            0x009f
#define KB_OUT                                  0x00a0
#define KB_OPER                                 0x00a1
#define KB_CLEAR_AGAIN                          0x00a2
#define KB_CRSEL_PROPS                          0x00a3
#define KB_EXSEL                                0x00a4
#define KP_00                                   0x00b0
#define KP_000                                  0x00b1
#define KP_THOUSANDS_SEPARATOR                  0x00b2
#define KP_DECIMAL_SEPARATOR                    0x00b3
#define KP_CURRENCY_UNIT                        0x00b4
#define KP_CURRENCY_SUB_UNIT                    0x00b5
#define KP_PARENTHESES_OPEN                     0x00b6
#define KP_PARENTHESES_CLOSE                    0x00b7
#define KP_OPERATION_CURLY_BRACKET_OPEN         0x00b8
#define KP_OPERATION_CURLY_BRACKET_CLOSE        0x00b9
#define KP_TAB                                  0x00ba
#define KP_BACKSPACE                            0x00bb
#define KP_A_HEX                                0x00bc
#define KP_B_HEX                                0x00bd
#define KP_C_HEX                                0x00be
#define KP_D_HEX                                0x00bf
#define KP_E_HEX                                0x00c0
#define KP_F_HEX                                0x00c1
#define KP_OPERATION_XOR                        0x00c2
#define KP_OPERATION_MOD                        0x00c3
#define KP_OPERATION_INTEGER_DIV                0x00c4
#define KP_OPERATION_SHIFT_LEFT                 0x00c5
#define KP_OPERATION_SHIFT_RIGHT                0x00c6
#define KP_OPERATION_AND                        0x00c7
#define KP_OPERATION_LOGIC_AND                  0x00c8
#define KP_OPERATION_OR                         0x00c9
#define KP_OPERATION_LOGIC_OR                   0x00ca
#define KP_OPERATION_COLON                      0x00cb
#define KP_OPERATION_GRID                       0x00cc
#define KP_SPACE                                0x00cd
#define KP_OPERATION_DOG                        0x00ce
#define KP_OPERATION_NOT                        0x00cf
#define KP_MEMORY_STORE                         0x00d0
#define KP_MEMORY_RECALL                        0x00d1
#define KP_MEMORY_CLEAR                         0x00d2
#define KP_MEMORY_ADD                           0x00d3
#define KP_MEMORY_SUBTRACT                      0x00d4
#define KP_MEMORY_MULTIPLY                      0x00d5
#define KP_MEMORY_DIVIDE                        0x00d6
#define KP_OPERATION_SING                       0x00d7
#define KP_CLEAR                                0x00d8
#define KP_CLEAR_ENTRY                          0x00d9
#define KP_BINARY                               0x00da
#define KP_OCTAL                                0x00db
#define KP_DECIMAL                              0x00dc
#define KP_HEXADECIMAL                          0x00dd
#define KB_LEFT_CONTROL                         0x00e0
#define KB_LEFT_SHIFT                           0x00e1
#define KB_LEFT_ALT                             0x00e2
#define KB_LEFT_GUI                             0x00e3
#define KB_RIGHT_CONTROL                        0x00e4
#define KB_RIGHT_SHIFT                          0x00e5
#define KB_RIGHT_ALT                            0x00e6
#define KB_RIGHT_GUI                            0x00e7
#define KB_SYS_HIDDEN                           0xffff

// -- Mouse  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define HID_MOUSE_EVENT( event )        ( event & 0x0f000000 )

#define HID_MOUSE_BUTTON1               0x00000000
#define HID_MOUSE_BUTTON2               0x01000000
#define HID_MOUSE_BUTTON3               0x02000000
#define HID_MOUSE_BUTTON4               0x03000000
#define HID_MOUSE_BUTTON5               0x04000000
#define HID_MOUSE_BUTTON6               0x05000000
#define HID_MOUSE_BUTTON7               0x06000000
#define HID_MOUSE_BUTTON8               0x07000000
#define HID_MOUSE_WHEEL1                0x08000000
#define HID_MOUSE_WHEEL2                0x09000000
#define HID_MOUSE_MOVE                  0x0a000000

#define HID_BUTTON_STATE( event )       ( event & 0x00000001 )

#define HID_MOUSE_WHEEL_SHIFT( event )  ((int16)( event & 0x0000ffff )

#define HID_MOUSE_MOVE_X( event )       ((int8)( event & 0x000000ff )
#define HID_MOUSE_MOVE_Y( event )       ((int8)( ( event >> 8 ) & 0x000000ff )

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define HID__BASE__                     0x00001800

#define HID_GETEVENT                    ( HID__BASE__ + 0 )
#define HID_IMTEVENT                    ( HID__BASE__ + 1 )
#define HID_PRBEVENT                    ( HID__BASE__ + 2 )

#define HID__USER__                     ( HID__BASE__ + 3 )

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#define DNSD__BASE__                    0x00001900
#define DNSD__USER__                    ( DNSD__BASE__ + 0 )

#define NETFS__BASE__                   0x00002000
#define NETFS__USER__                   (NETFS__BASE__ + 0 )
#endif
