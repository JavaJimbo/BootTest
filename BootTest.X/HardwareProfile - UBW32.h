/********************************************************************
 FileName:      HardwareProfile - UBW32.h
 Dependencies:  See INCLUDES section
 Processor:     PIC32 USB Microcontrollers
 Hardware:      UBW32
 Compiler:      Microchip C32 (for PIC32)
 Company:       SchmalzHaus

 ********************************************************************  
 File Description:

 Change History:
  Rev   Date         Description
  1.0   10/24/2009   Initial release
 ********************************************************************/

#ifndef HARDWARE_PROFILE_UBW32_H
#define HARDWARE_PROFILE_UBW32_H

/*******************************************************************/
/******** USB stack hardware selection options *********************/
/*******************************************************************/
//This section is the set of definitions required by the MCHPFSUSB
//  framework.  These definitions tell the firmware what mode it is
//  running in, and where it can find the results to some information
//  that the stack needs.
//These definitions are required by every application developed with
//  this revision of the MCHPFSUSB framework.  Please review each
//  option carefully and determine which options are desired/required
//  for your application.

//#define USE_SELF_POWER_SENSE_IO
#define tris_self_power     TRISAbits.TRISA2    // Input
#define self_power          1

//#define USE_USB_BUS_SENSE_IO
#define tris_usb_bus_sense  TRISBbits.TRISB5    // Input
#define USB_BUS_SENSE       1 

/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/******** Application specific definitions *************************/
/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

/** Board definition ***********************************************/
//These defintions will tell the main() function which board is
//  currently selected.  This will allow the application to add
//  the correct configuration bits as wells use the correct
//  initialization functions for the board.  These defitions are only
//  required in the stack provided demos.  They are not required in
//  final application design.
#define DEMO_BOARD UBW32

#define mInitAllLEDs()      LATE |= 0x000F; TRISE &= 0xFFF0;

#define mLED_1              LATEbits.LATE3
#define mLED_2              LATEbits.LATE2
#define mLED_3              LATEbits.LATE1
#define mLED_4              LATEbits.LATE0

#define mGetLED_1()         mLED_1
#define mGetLED_USB()       mLED_1
#define mGetLED_2()         mLED_2
#define mGetLED_3()         mLED_3
#define mGetLED_4()         mLED_4

#define mLED_1_On()         mLED_1 = 0;
#define mLED_USB_On()       mLED_1 = 0;
#define mLED_2_On()         mLED_2 = 0;
#define mLED_3_On()         mLED_3 = 0;
#define mLED_4_On()         mLED_4 = 0;

#define mLED_1_Off()        mLED_1 = 1;
#define mLED_USB_Off()      mLED_1 = 1;
#define mLED_2_Off()        mLED_2 = 1;
#define mLED_3_Off()        mLED_3 = 1;
#define mLED_4_Off()        mLED_4 = 1;

#define mLED_1_Toggle()     mLED_1 = !mLED_1;
#define mLED_USB_Toggle()   mLED_1 = !mLED_1;
#define mLED_2_Toggle()     mLED_2 = !mLED_2;
#define mLED_3_Toggle()     mLED_3 = !mLED_3;
#define mLED_4_Toggle()     mLED_4 = !mLED_4;

/** SWITCH *********************************************************/
#define mInitSwitch2()      TRISEbits.TRISE7=1;
#define mInitSwitch3()      TRISEbits.TRISE6=1;
#define mInitAllSwitches()  mInitSwitch2();mInitSwitch3();
#define swProgram           PORTEbits.RE7
#define swUser              PORTEbits.RE6
#define sw2					swProgram
#define sw1					swUser

/** I/O pin definitions ********************************************/
#define INPUT_PIN 1
#define OUTPUT_PIN 0


#define USE_SD_INTERFACE_WITH_SPI
#define MDD_USE_SPI_2

//SPI Configuration
#define SPI_START_CFG_1     (PRI_PRESCAL_64_1 | SEC_PRESCAL_8_1 | MASTER_ENABLE_ON | SPI_CKE_ON | SPI_SMP_ON)
#define SPI_START_CFG_2     (SPI_ENABLE)

// Define the SPI frequency
#define SPI_FREQUENCY			(20000000)

// Description: SD-SPI Chip Select Output bit
#define SD_CS               LATCbits.LATC4 // LATBbits.LATB9
// Description: SD-SPI Chip Select TRIS bit
#define SD_CS_TRIS          TRISCbits.TRISC4 // TRISBbits.TRISB9

// Description: SD-SPI Card Detect Input bit
#define SD_CD               PORTGbits.RG9 // PORTGbits.RG0
// Description: SD-SPI Card Detect TRIS bit
#define SD_CD_TRIS          TRISGbits.TRISG9 // TRISGbits.TRISG0

// Description: SD-SPI Write Protect Check Input bit
#define SD_WE               PORTAbits.RA0 // PORTGbits.RG1
// Description: SD-SPI Write Protect Check TRIS bit
#define SD_WE_TRIS          TRISAbits.TRISA0 // TRISGbits.TRISG1

// Description: The main SPI control register
#define SPICON1             SPI2CON
// Description: The SPI status register
#define SPISTAT             SPI2STAT
// Description: The SPI Buffer
#define SPIBUF              SPI2BUF
// Description: The receive buffer full bit in the SPI status register
#define SPISTAT_RBF         SPI2STATbits.SPIRBF
// Description: The bitwise define for the SPI control register (i.e. _____bits)
#define SPICON1bits         SPI2CONbits
// Description: The bitwise define for the SPI status register (i.e. _____bits)
#define SPISTATbits         SPI2STATbits
// Description: The enable bit for the SPI module
#define SPIENABLE           SPI2CONbits.ON
// Description: The definition for the SPI baud rate generator register (PIC32)
#define SPIBRG			    SPI2BRG

// Tris pins for SCK/SDI/SDO lines

// Description: The TRIS bit for the SCK pin
#define SPICLOCK            TRISGbits.TRISG6
// Description: The TRIS bit for the SDI pin
#define SPIIN               TRISGbits.TRISG7
// Description: The TRIS bit for the SDO pin
#define SPIOUT              TRISGbits.TRISG8
//SPI library functions
#define putcSPI             putcSPI2
#define getcSPI             getcSPI2
#define OpenSPI(config1, config2)   OpenSPI2(config1, config2)

// Will generate an error if the clock speed is too low to interface to the card
//#if (GetSystemClock() < 100000)
//    #error Clock speed must exceed 100 kHz
//#endif


#endif  //HARDWARE_PROFILE_UBW32_H
