/*************************************************************************************************\
*                         Copyright (C) 2008 RCZI
*-------------------------------------------------------------------------------------------------
* FILENAME...... emif.h
*-------------------------------------------------------------------------------------------------
* Ïðîöèäóðû èíèöèàëèçàöèè
\***sss*******************************************************************************************/
#ifndef __EMIF_TMS64xx_H__
#define __EMIF_TMS64xx_H__

/*************************************************************************************************\
* Èíèöèàëèçàöèÿ øèíû EMIF TMS320C64xx
\***sss*******************************************************************************************/
//=================================================================================================
//              EMIF Global Control Register (GBLCTL)
//===sss===========================================================================================
//19-18 EK2RATE - ECLKOUT2 rate. ECLKOUT2 runs at:
#define GBLCTL_FULLCLK  0x0 //1x   EMIF input clock (ECLKIN, CPU/4 clock, or CPU/6 clock) rate.
#define GBLCTL_HALFCLK  0x1 //1/2x EMIF input clock (ECLKIN, CPU/4 clock, or CPU/6 clock) rate.
#define GBLCTL_QUARCLK  0x2 //1/4x EMIF input clock (ECLKIN, CPU/4 clock, or CPU/6 clock) rate.
//17 EK2HZ - ECLKOUT2 high-impedance control bit.
#define GBLCTL_CLK      0x0 //ECLKOUT2 continues clocking during Hold (if EK2EN = 1).
#define GBLCTL_HIGHZ    0x1 //ECLKOUT2 is in high-impedance state during Hold.
//16 EK2EN - ECLKOUT2 enable bit.
#define GBLCTL_DISABLE  0x0 //ECLKOUT2 is held low.
#define GBLCTL_ENABLE   0x1 //ECLKOUT2 is enabled to clock.
//13 BRMODE - Bus request mode (BRMODE) bit indicates if BUSREQ shows memory refresh status.
#define GBLCTL_MSTATUS  0x0 //BUSREQ indicates memory access pending or in progress.
#define GBLCTL_MRSTATUS 0x1 //BUSREQ indicates memory access or refresh pending or in progress.
//11 BUSREQ - Bus request (BUSREQ) output bit indicates if the EMIF has an 
//   access/refresh pending or in progress.
#define GBLCTL_LOW      0x0 //BUSREQ output is low. No access/refresh pending.
#define GBLCTL_HIGH     0x1 //BUSREQ output is high. Access/refresh pending or in progress.
//10 ARDY - ARDY input bit. Valid ARDY bit is shown only when performing
//   asynchronous memory access (when async CEn is active).
#define GBLCTL_LOW      0x0 //ARDY input is low. External device is not ready.
#define GBLCTL_HIGH     0x1 //ARDY input is high. External device is ready.
//9 HOLD - HOLD input bit.
#define GBLCTL_LOW      0x0 //HOLD input is low. External device requesting EMIF.
#define GBLCTL_HIGH     0x1 //HOLD input is high. No external request pending.
//8 HOLDA - HOLDA output bit.
#define GBLCTL_LOW      0x0 //HOLDA output is low. External device owns EMIF.
#define GBLCTL_HIGH     0x1 //HOLDA output is high. External device does not own EMIF.
//7 NOHOLD - External NOHOLD enable bit.
#define GBLCTL_DISABLE  0x0 //No hold is disabled. Hold requests via the HOLD input are acknowledged via the HOLDA output at the earliest possible time.
#define GBLCTL_ENABLE   0x1 //No hold is enabled. Hold requests via the HOLD input are ignored.
//6 EK1HZ - ECLKOUT1 high-impedance control bit.
#define GBLCTL_CLK      0x0 //ECLKOUT1 continues clocking during Hold (if EK1EN = 1).
#define GBLCTL_HIGHZ    0x1 //ECLKOUT1 is in high-impedance state during Hold.
//5 EK1EN - ECLKOUT1 enable bit.
#define GBLCTL_DISABLE  0x0 //ECLKOUT1 is held low.
#define GBLCTL_ENABLE   0x1 //ECLKOUT1 is enabled to clock.
//4 CLK4EN - CLKOUT4 enable bit. CLKOUT4 pin is muxed with GP1 pin.
//Upon exiting reset, CLKOUT4 is enabled and clocking. After
//reset, CLKOUT4 may be configured as GP1 via the GPIO enable register (GPEN).
#define GBLCTL_DISABLE  0x0 //CLKOUT4 is held high.
#define GBLCTL_ENABLE   0x1 //CLKOUT4 is enabled to clock.
//3 CLK6EN - CLKOUT 6 enable bit. CLKOUT6 pin is muxed with GP2 pin.
//Upon exiting reset, CLKOUT6 is enabled and clocking. After
//reset, CLKOUT6 may be configured as GP2 via the GPIO enable register (GPEN).
#define GBLCTL_DISABLE  0x0 //CLKOUT6 is held high.
#define GBLCTL_ENABLE   0x1 //CLKOUT6 is enabled to clock.

//=================================================================================================
//              EMIF CE Space Control Registers (CECTL0-3)
//===sss===========================================================================================
//31-28 WRSETUP OF(value) 0-Fh Write setup width. Number of clock cycles of setup time for
//      address (EA), chip enable (CE), and byte enables (BE)
//      before write strobe falls. For asynchronous read accesses,
//      this is also the setup time of AOE before ARE falls.
//
//27-22 WRSTRB OF(value) 0-3Fh Write strobe width. The width of write strobe (AWE) in clock
//      cycles.
//
//21-20 WRHLD OF(value) 0-3h Write hold width. Number of clock cycles‡ that address (EA)
//      and byte strobes (BE) are held after write strobe rises. For
//      asynchronous read accesses, this is also the hold time of
//      AOE after ARE rising.
//
//19-16 RDSETUP OF(value) 0-Fh Read setup width. Number of clock cycles‡ of setup time for
//      address (EA), chip enable (CE), and byte enables (BE)
//      before read strobe falls. For asynchronous read accesses,
//      this is also the setup time of AOE before ARE falls.
//
//15-14 TA OF(value) 0-3h Minimum Turn-Around time. Turn-around time controls the
//      minimum number of ECLKOUT cycles between a read
//      followed by a write (same or different CE spaces), or between
//      reads from different CE spaces. Applies only to asynchronous
//      memory types.
//
//13-8 RDSTRB OF(value) 0-3Fh Read strobe width. The width of read strobe (ARE) in clock
//      cycles.
//
//7-4 MTYPE - 0-Fh Memory type of the corresponding CE spaces.
#define CECTL_ASYNC8    0x0 //8-bit-wide asynchronous interface.
#define CECTL_ASYNC16   0x1 //16-bit-wide asynchronous interface.
#define CECTL_ASYNC32   0x2 //32-bit-wide asynchronous interface.
#define CECTL_SDRAM32   0x3 //32-bit-wide SDRAM.
#define CECTL_SYNC32    0x4 //32-bit-wide programmable synchronous memory.
#define CECTL_SDRAM8    0x8 //8-bit-wide SDRAM.
#define CECTL_SDRAM16   0x9 //16-bit-wide SDRAM.
#define CECTL_SYNC8     0xA //8-bit-wide programmable synchronous memory.
#define CECTL_SYNC16    0xB //16-bit-wide programmable synchronous memory.
#define CECTL_ASYNC64   0xC //64-bit-wide asynchronous interface.
#define CECTL_SDRAM64   0xD //64-bit-wide SDRAM.
#define CECTL_SYNC64    0xE //64-bit-wide programmable synchronous memory.
//3 WRHLDMSB OF(value) 0-1 Write hold width MSB is the most-significant bit of write hold.
//
//2-0 RDHLD OF(value) 0-7h Read hold width. Number of clock cycles‡ that address (EA)
//    and byte strobes (BE) are held after read strobe rises. For
//    asynchronous read accesses, this is also the hold time of
//    AOE after ARE rising.

//=================================================================================================
//              EMIF CE Space Secondary Control Registers (CESEC0-3)
//===sss===========================================================================================
//6 SNCCLK Synchronization clock selection bit.
#define CESEC_ECLKOUT1 0x0 //Control/data signals for this CE space are synchronized to ECLKOUT1.
#define CESEC_ECLKOUT2 0x1 //Control/data for this CE space are synchronized to ECLKOUT2.
//5 RENEN Read Enable enable bit.
#define CESEC_ADS  0x0 //ADS mode. SADS/SRE signal acts as SADS signal. SADS goes
                      //active for reads, writes, and deselect. Deselect is issued after a
                      //command is completed if no new commands are pending from
                      //the EDMA. (used for SBSRAM or ZBT SRAM interface).
#define CESEC_READ 0x1 //Read enable mode. SADS/SRE signal acts as SRE signal. SRE
                      //goes low only for reads. No deselect cycle is issued. (used for
                      //FIFO interface).
//4 CEEXT CE extension register ENABLE BIT.
#define CESEC_INACTIVE 0x0 //CE goes inactive after the final command has been issued (not
                          //necessarily when all the data has been latched).
#define CESEC_ACTIVE   0x1 //On read cycles, the CE signal will go active when SOE goes
                          //active and will stay active until SOE goes inactive. The SOE
                          //timing is controlled by SYNCRL. (used for synchronous FIFO
                          //reads with glue, where CE gates OE).
//3-2 SYNCWL 0-3h Synchronous interface data write latency.
#define CESEC_0CYCLE 0x0 //0 cycle read latency.
#define CESEC_1CYCLE 0x1 //1 cycle read latency.
#define CESEC_2CYCLE 0x2 //2 cycle read latency.
#define CESEC_3CYCLE 0x3 //3 cycle read latency.
//1-0 SYNCRL 0-3h Synchronous interface data read latency.
#define CESEC_0CYCLE 0x0 //0 cycle read latency.
#define CESEC_1CYCLE 0x1 //1 cycle read latency.
#define CESEC_2CYCLE 0x2 //2 cycle read latency.
#define CESEC_3CYCLE 0x3 //3 cycle read latency.

//=================================================================================================
//              EMIF SDRAM Control Register (SDCTL)
//===sss===========================================================================================
//30 SDBSZ SDRAM bank size bit.
#define SDCTL_2BANKS 0x0 //One bank-select pin (two banks).
#define SDCTL_4BANKS 0x1 //Two bank-select pins (four banks).
//29-28 SDRSZ 0-3h SDRAM row size bits.
#define SDCTL_11ROW 0x0 //11 row address pins (2048 rows per bank).
#define SDCTL_12ROW 0x1 //12 row address pins (4096 rows per bank).
#define SDCTL_13ROW 0x2 //13 row address pins (8192 rows per bank).
//27-26 SDCSZ 0-3h SDRAM column size bits.
#define SDCTL_9COL  0x0 //9 column address pins (512 elements per row).
#define SDCTL_8COL  0x1 //8 column address pins (256 elements per row).
#define SDCTL_10COL 0x2 //10 column address pins (1024 elements per row).
//25 RFEN Refresh enable bit. If SDRAM is not used, be sure RFEN = 0;
//   otherwise, BUSREQ may become asserted when SDRAM timer counts down to 0.
#define SDCTL_DISABLE 0x0 //SDRAM refresh is disabled.
#define SDCTL_ENABLE  0x1 //SDRAM refresh is enabled.
//24 INIT Initialization bit. This write-only bit forces initialization of all
//   SDRAM present. Reading this bit returns an undefined value.
#define SDCTL_NO  0x0 //No effect.
#define SDCTL_YES 0x1 //Initialize SDRAM in each CE space configured for SDRAM. The
                     //CPU should initialize all of the CE space control registers and
                     //SDRAM extension register before setting INIT = 1.
//23-20 TRCD OF(value) 0-Fh Specifies the tRCD value of the SDRAM in EMIF clock cycles.‡
//      TRCD = tRCD / tcyc - 1
//19-16 TRP OF(value) 0-Fh Specifies the tRC value of the SDRAM in EMIF clock cycles.‡
//      TRC = tRC / tcyc - 1
//15-12 TRC OF(value) 0-Fh Specifies the tRC value of the SDRAM in EMIF clock cycles.‡
//      TRC = tRC / tcyc - 1
//0     SLFRFR Self-refresh mode, if SDRAM is used in the system:
#define SDCTL_DISABLE 0x0 //Self-refresh mode is disabled.
#define SDCTL_ENABLE  0x1 //Self-refresh mode is enabled.
                          //If SDRAM is not used:
#define SDCTL_DISABLE 0x0 //General-purpose output, SDCKE = 1.
#define SDCTL_ENABLE  0x1 //General-purpose output, SDCKE = 0.

//=================================================================================================
//              EMIF SDRAM Timing Register (SDTIM)
//===sss===========================================================================================
//25-24 XRFR OF(value) 0-3h Extra refreshes controls the number of refreshes performed to
//      SDRAM when the refresh counter expires.
#define SDTIM_1REFR_0h 0x0  //1 refresh.
#define SDTIM_2REFR_1h 0x1  //2 refreshes.
#define SDTIM_3REFR_2h 0x2  //3 refreshes.
#define SDTIM_4REFR_3h 0x3  //4 refreshes.
//
//23-12 CNTR OF(value) 0-FFFh Current value of the refresh counter.
//
//11-0 PERIOD OF(value) 0-FFFh Refresh period in EMIF clock cycles.


//=================================================================================================
//              EMIF SDRAM Extension Register (SDEXT)
//===sss===========================================================================================
//20    WR2RD OF(value) 0-1 Specifies minimum number of cycles between WRITE to READ
//      command of the SDRAM in ECLKOUT cycles.
//      WR2RD = (# of cycles WRITE to READ) - 1
//
//19-18 WR2DEAC OF(value) 0-3h Specifies minimum number of cycles between WRITE to DEAC/
//      DCAB command of the SDRAM in ECLKOUT cycles.
//      WR2DEAC = (# of cycles WRITE to DEAC/DCAB) - 1
//
//17    WR2WR OF(value) 0-1 Specifies minimum number of cycles between WRITE to WRITE
//      command of the SDRAM in ECLKOUT cycles.
//      WR2WR = (# of cycles WRITE to WRITE) - 1
//
//16-15 R2WDQM OF(value) 0-3h Specifies number of of cycles that BEx signals must be high
//      preceding a WRITE interrupting a READ.
//      R2WDQM = (# of cycles BEx high) - 1
//
//14-12 RD2WR OF(value) 0-7h Specifies number of cycles between READ to WRITE command
//      of the SDRAM in ECLKOUT cycles.‡
//      RD2WR = (# of cycles READ to WRITE) - 1
//
//11-10 RD2DEAC OF(value) 0-3h Specifies number of cycles between READ to DEAC/DCAB of
//      the SDRAM in ECLKOUT cycles.
//      RD2DEAC = (# of cycles READ to DEAC/DCAB) - 1
//
//9     RD2RD OF(value) Specifies number of cycles between READ to READ command
//      (same CE space) of the SDRAM in ECLKOUT cycles.‡
//      0 READ to READ = 1 ECLKOUT cycle.
//      1 READ to READ = 2 ECLKOUT cycle.
//
//8-7   THZP OF(value) 0-3h Specifies tHZP (also known as tROH) value of the SDRAM in
//      ECLKOUT cycles.‡
//      THZP = tHZP / tcyc - 1
//
//6-5   TWR OF(value) 0-3h Specifies tWR value of the SDRAM in ECLKOUT cycles.
//      TWR = tWR / tcyc - 1
//
//4     TRRD OF(value) Specifies tRRD value of the SDRAM in ECLKOUT cycles.
//      0 TRRD = 2 ECLKOUT cycles.
//      1 TRRD = 3 ECLKOUT cycles.
//
//3-1   TRAS OF(value) 0-7h Specifies tRAS value of the SDRAM in ECLKOUT cycles.
//      TRAS = tRAS / tcyc - 1
//      0 TCL OF(value) Specified CAS latency of the SDRAM in ECLKOUT cycles.
//      0 CAS latency = 2 ECLKOUT cycles.
//      1 CAS latency = 3 ECLKOUT cycles.


#endif  //__EMIF_TMS64xx_H__
