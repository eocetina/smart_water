/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15344
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_T2 aliases
#define LED_T2_TRIS                 TRISAbits.TRISA2
#define LED_T2_LAT                  LATAbits.LATA2
#define LED_T2_PORT                 PORTAbits.RA2
#define LED_T2_WPU                  WPUAbits.WPUA2
#define LED_T2_OD                   ODCONAbits.ODCA2
#define LED_T2_ANS                  ANSELAbits.ANSA2
#define LED_T2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_T2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_T2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_T2_GetValue()           PORTAbits.RA2
#define LED_T2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_T2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_T2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_T2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_T2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_T2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_T2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_T2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set BUTTON aliases
#define BUTTON_TRIS                 TRISAbits.TRISA5
#define BUTTON_LAT                  LATAbits.LATA5
#define BUTTON_PORT                 PORTAbits.RA5
#define BUTTON_WPU                  WPUAbits.WPUA5
#define BUTTON_OD                   ODCONAbits.ODCA5
#define BUTTON_ANS                  ANSELAbits.ANSA5
#define BUTTON_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BUTTON_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BUTTON_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BUTTON_GetValue()           PORTAbits.RA5
#define BUTTON_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define BUTTON_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define BUTTON_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define BUTTON_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set TILT_SENSOR aliases
#define TILT_SENSOR_TRIS                 TRISBbits.TRISB6
#define TILT_SENSOR_LAT                  LATBbits.LATB6
#define TILT_SENSOR_PORT                 PORTBbits.RB6
#define TILT_SENSOR_WPU                  WPUBbits.WPUB6
#define TILT_SENSOR_OD                   ODCONBbits.ODCB6
#define TILT_SENSOR_ANS                  ANSELBbits.ANSB6
#define TILT_SENSOR_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define TILT_SENSOR_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define TILT_SENSOR_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define TILT_SENSOR_GetValue()           PORTBbits.RB6
#define TILT_SENSOR_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define TILT_SENSOR_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define TILT_SENSOR_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define TILT_SENSOR_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define TILT_SENSOR_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define TILT_SENSOR_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define TILT_SENSOR_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define TILT_SENSOR_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set BAT_STAT aliases
#define BAT_STAT_TRIS                 TRISBbits.TRISB7
#define BAT_STAT_LAT                  LATBbits.LATB7
#define BAT_STAT_PORT                 PORTBbits.RB7
#define BAT_STAT_WPU                  WPUBbits.WPUB7
#define BAT_STAT_OD                   ODCONBbits.ODCB7
#define BAT_STAT_ANS                  ANSELBbits.ANSB7
#define BAT_STAT_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define BAT_STAT_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define BAT_STAT_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define BAT_STAT_GetValue()           PORTBbits.RB7
#define BAT_STAT_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define BAT_STAT_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define BAT_STAT_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define BAT_STAT_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define BAT_STAT_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define BAT_STAT_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define BAT_STAT_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define BAT_STAT_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED_T3 aliases
#define LED_T3_TRIS                 TRISCbits.TRISC3
#define LED_T3_LAT                  LATCbits.LATC3
#define LED_T3_PORT                 PORTCbits.RC3
#define LED_T3_WPU                  WPUCbits.WPUC3
#define LED_T3_OD                   ODCONCbits.ODCC3
#define LED_T3_ANS                  ANSELCbits.ANSC3
#define LED_T3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_T3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_T3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_T3_GetValue()           PORTCbits.RC3
#define LED_T3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_T3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_T3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED_T3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED_T3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED_T3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED_T3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_T3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set LED_T4 aliases
#define LED_T4_TRIS                 TRISCbits.TRISC5
#define LED_T4_LAT                  LATCbits.LATC5
#define LED_T4_PORT                 PORTCbits.RC5
#define LED_T4_WPU                  WPUCbits.WPUC5
#define LED_T4_OD                   ODCONCbits.ODCC5
#define LED_T4_ANS                  ANSELCbits.ANSC5
#define LED_T4_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_T4_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_T4_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_T4_GetValue()           PORTCbits.RC5
#define LED_T4_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_T4_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_T4_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_T4_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_T4_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_T4_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_T4_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_T4_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set VBAT_IN aliases
#define VBAT_IN_TRIS                 TRISCbits.TRISC6
#define VBAT_IN_LAT                  LATCbits.LATC6
#define VBAT_IN_PORT                 PORTCbits.RC6
#define VBAT_IN_WPU                  WPUCbits.WPUC6
#define VBAT_IN_OD                   ODCONCbits.ODCC6
#define VBAT_IN_ANS                  ANSELCbits.ANSC6
#define VBAT_IN_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define VBAT_IN_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define VBAT_IN_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define VBAT_IN_GetValue()           PORTCbits.RC6
#define VBAT_IN_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define VBAT_IN_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define VBAT_IN_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define VBAT_IN_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define VBAT_IN_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define VBAT_IN_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define VBAT_IN_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define VBAT_IN_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED_T1 aliases
#define LED_T1_TRIS                 TRISCbits.TRISC7
#define LED_T1_LAT                  LATCbits.LATC7
#define LED_T1_PORT                 PORTCbits.RC7
#define LED_T1_WPU                  WPUCbits.WPUC7
#define LED_T1_OD                   ODCONCbits.ODCC7
#define LED_T1_ANS                  ANSELCbits.ANSC7
#define LED_T1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED_T1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED_T1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED_T1_GetValue()           PORTCbits.RC7
#define LED_T1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED_T1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED_T1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED_T1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED_T1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED_T1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED_T1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED_T1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF6 pin functionality
 * @Example
    IOCBF6_ISR();
 */
void IOCBF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_InterruptHandler);

*/
extern void (*IOCBF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF6_SetInterruptHandler() method.
    This handler is called every time the IOCBF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF6_SetInterruptHandler(IOCBF6_DefaultInterruptHandler);

*/
void IOCBF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF7 pin functionality
 * @Example
    IOCBF7_ISR();
 */
void IOCBF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_InterruptHandler);

*/
extern void (*IOCBF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_DefaultInterruptHandler);

*/
void IOCBF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/