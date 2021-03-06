/********************************************************************
 FileName:      HardwareProfilePinguino220.h
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
    // #define DEMO_BOARD UBW32
	#define DEMO_BOARD PINGUINO_220

    // #define mInitAllLEDs()      LATE |= 0x000F; TRISE &= 0xFFF0;
	
    
    #define mLED_1              LATBbits.LATB15 // LATEbits.LATE3
    #define mLED_2              LATAbits.LATA10 // LATEbits.LATE2
	#define mInitAllLEDs()      mLED_1 = 0; mLED_2 = 0; TRISBbits.TRISB15 = 0; TRISAbits.TRISA10 = 0;  // TRISE &= 0xFFF0;

    //#define mLED_3              LATEbits.LATE1
    //#define mLED_4              LATEbits.LATE0

    #define mGetLED_1()         mLED_1
    #define mGetLED_USB()       mLED_1
    #define mGetLED_2()         mLED_2
    //#define mGetLED_3()         mLED_3
    //#define mGetLED_4()         mLED_4

    //#define mLED_1_On()         mLED_1 = 0;
    //#define mLED_USB_On()       mLED_1 = 0;
    //#define mLED_2_On()         mLED_2 = 0;

	#define mLED_1_On()         mLED_1 = 1;
    #define mLED_USB_On()       mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    
    //#define mLED_3_On()         mLED_3 = 0;
    //#define mLED_4_On()         mLED_4 = 0;
    
    //#define mLED_1_Off()        mLED_1 = 1;
    //#define mLED_USB_Off()      mLED_1 = 1;
    //#define mLED_2_Off()        mLED_2 = 1;
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_USB_Off()      mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;

    //#define mLED_3_Off()        mLED_3 = 1;
    //#define mLED_4_Off()        mLED_4 = 1;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_USB_Toggle()   mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    //#define mLED_3_Toggle()     mLED_3 = !mLED_3;
    //#define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    //#define mInitSwitch2()      TRISEbits.TRISE7=1;
    //#define mInitSwitch3()      TRISEbits.TRISE6=1;
    //#define mInitAllSwitches()  mInitSwitch2();mInitSwitch3();
    //#define swProgram           PORTEbits.RE7
    //#define swUser              PORTEbits.RE6
	//#define sw2					swProgram
	//#define sw1					swUser

    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0

#endif  //HARDWARE_PROFILE_UBW32_H
