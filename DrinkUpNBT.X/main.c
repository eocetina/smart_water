/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15344
        Driver Version    :  2.00
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

#include <xc8debug.h>

#include "mcc_generated_files/mcc.h"
#include "app.h"
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    PMD1bits.NCOMD = 1;
    PMD2bits.DAC1MD = 1;
    PMD2bits.CMP1MD = 1;
    //PMD2bits.CMP2MD = 1;
    PMD2bits.ZCDMD = 1;
    PMD3bits.CCP1MD = 1;
    PMD3bits.CCP2MD = 1;
    PMD4bits.CWG1MD = 1;
    PMD4bits.MSSP1MD = 1;
    PMD4bits.UART1MD = 1;
    PMD4bits.UART2MD = 1;
    PMD5 = 0xff;
    

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //Setting interrupt for button
    IOCAF5_SetInterruptHandler(buttChangeInt);
    CMP2_SetInterruptHandler(tiltChange2);
    //IOCBF6_SetInterruptHandler(tiltChange);
    IOCBF7_SetInterruptHandler(batteryGetStatus);
    TMR0_SetInterruptHandler(minuteInt);
    TMR1_SetInterruptHandler(timer1Int);
    TMR1_StopTimer();
    
    initValues();
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    welcomeLeds();
    batteryGetStatus();
    /*__delay_ms(1000);
    ledSave();
    __delay_ms(1000);
    ledRestore();
    __delay_ms(1000);*/
    CPUDOZEbits.IDLEN = 1;
    /*
    CPUDOZEbits.ROI = 1;
    CPUDOZEbits.DOE = 1;
    CPUDOZEbits.DOZE = 0x07;
    CPUDOZEbits.DOZEN = 1;
     * */
    //modeChangeTime();
    ledBatteryCharging();
    batteryGetStatus();
    if (batt_stat != VERYLOW)
    {
        ledDrinkConfig();
        ledDrinkConfig();
        ledDrinkConfig();
    }
    while (1)
    {
        if (batt_stat == NORMAL)
        {
            /**
             * validate push button
             */
            if(button_cont_en)
            {
                if ((tick_100ms - button_time_cont) >= TIME_PUSH_RESTORE*10)
                {
                    INTERRUPT_GlobalInterruptDisable();
                    ledRestore();
                    defaultValues();
                    storeValues();
                    RESET();
                }
                else if((tick_100ms - button_time_cont) >= TIME_PUSH_CHANGE*10)
                {
                    ledDrinkConfig();
                }
            }
            if (push_change_event)
            {
                modeChangeTime();
                RESET();
                push_change_event = false;
            }
            if(push_single_event)
            {
                ledDrinkConfig();
                push_single_event = false;
            }
            if(tilt_cont_en || sip_event)
            {
                if ((tick_100ms - tilt_time_cont) >= TIME_SIP*10)
                {
                    sip_event = true;
                }
                if (sip_event)
                {
                    INTERRUPT_GlobalInterruptDisable();
                    ledSip();
                    snooze_cont_en = false;
                    sip_event = false;
                    tilt_cont_en = false;
                    minutes_count = app.app_config.remember_time*5;
                    TMR0_StopTimer();
                    TMR0_WriteTimer(0);
                    TMR0_StartTimer();
                    if(button_cont_en == false)
                    {
                        TMR1_StopTimer();
                    }
                    INTERRUPT_GlobalInterruptEnable();
                }
            }
            if(snooze_cont_en)
            {
                ledDrinkAlert();
                if ((tick_100ms - snooze_time_cont) >= TIME_SNOOZE*10)
                {
                    INTERRUPT_GlobalInterruptDisable();
                    snooze_cont_en = false;
                    if(button_cont_en == false && tilt_cont_en == false)
                    {
                        TMR1_StopTimer();
                    }
                    INTERRUPT_GlobalInterruptEnable();
                }
            }
            SLEEP();
        }
        else if (batt_stat == VERYLOW)
        {
            ledBatteryLow();
        }
        else if (batt_stat == CHARGING)
        {
            ledBatteryCharging();
        }
        else if (batt_stat == CHARGED)
        {
            ledBatteryCharged();
        }
        batteryGetStatus();
        // Add your application code
        /*
        if(flag_update_mem)
        {
            storeValues();
            updateLeds();
        }
        if(tok_cont>0)
            executeCommands();
        SLEEP();
        */
        //batteryLeds();
        //__delay_ms(1000);
        
        //BT_PWRC_SetHigh();
    }
}
/**
 End of File
*/