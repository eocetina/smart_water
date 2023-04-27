/* 
 * File:   app.h
 * Author: Emmanuel Vera
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __APP__H
#define	__APP__H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    /**
     * Start addres of flash memory to stora user data
     */
#define USER_STORAGE 0xEC0
#define HIGH_TILT 10 //tilts per second to determine if is high activiti
    /**
     * Struct to save the user data to flash memory
     */
    typedef struct
    {
        uint8_t remember_time;          //time/5 to remember drink
        //uint8_t sip_time;               //minimum sip time to indicate a drink
        //uint8_t snooze_time;             //maximum time of alert to remember drink
    }APP_CONFIG;//272 bytes (we reserve 320 words of 14 bits). Start at EC0
    /**
     * Union to convert the struct to byte array
     */
    volatile union
    {
        APP_CONFIG app_config;
        uint8_t app_config_raw[sizeof(APP_CONFIG)];
    }app;
    
    /**
     * Flag to indicate that is necessary save the user data in the flash memory
     */
    volatile bool flag_update_mem;
    /**
     * Enumerator to determine the status of the battery
     */
    typedef enum {VERYLOW,CHARGING,CHARGED,NORMAL} batt_stat_t;
    
    #define VBAT_FACTOR (1023.0/3.3)
    #define VBAT_MAX (uint16_t)((4.1/2.0)*VBAT_FACTOR)
    #define VBAT_L4  (uint16_t)((4.0/2.0)*VBAT_FACTOR)
    #define VBAT_L3  (uint16_t)((3.8/2.0)*VBAT_FACTOR)
    #define VBAT_L2  (uint16_t)((3.6/2.0)*VBAT_FACTOR)
    #define VBAT_L1  (uint16_t)((3.3/2.0)*VBAT_FACTOR)
    #define VBAT_MIN (uint16_t)((3.3/2.0)*VBAT_FACTOR)

#define TIME_PUSH_CHANGE    5
#define TIME_PUSH_RESTORE   10
#define TIME_PUSH_SAVE      5
#define TIME_SIP            3
#define TIME_SNOOZE         10
    
    volatile uint32_t tick_100ms;
    volatile uint32_t minutes_count;
    volatile bool button_cont_en;
    volatile bool tilt_cont_en;
    volatile bool snooze_cont_en;
    volatile uint32_t button_time_cont;
    volatile uint32_t tilt_time_cont;
    volatile uint32_t snooze_time_cont;
    volatile bool push_change_event;
    volatile bool push_restore_event;
    volatile bool push_single_event;
    volatile bool sip_event;
    volatile bool snooze_event;
    
    volatile adc_result_t VBAT;
    volatile batt_stat_t batt_stat;
    /**
     * Interrupt manager for minutes
     */
    void minuteInt(void);
    /**
    * Interrupt manager for button released.
    */
    void buttChangeInt(void);
    /**
     * Leds animation for welcome
     */
    void welcomeLeds(void);
    /**
     * Interrupt manager for tilt switch
     */
    void tiltChange(void);
    void tiltChange2(void);
    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    void defaultValues(void);
    void readValues(void);
    void storeValues(void);
    void initValues(void);
    void updateLeds(void);
    void timer1Int(void);
    void batteryLeds(void);
    void batteryGetStatus(void);
    void ledBatteryCharged(void);
    void ledBatteryCharging(void);
    void ledBatteryLow(void);
    void ledMinutes(void);
    void ledDrinkAlert(void);
    void ledDrinkConfig(void);
    void ledSip(void);
    void ledSave(void);
    void ledRestore(void);
#define LED_BRIGHT_50 100
//#define LED_BRIGHT_0  511
    void led1On(void);
    void led1Off(void);
    void led2On(void);
    void led2Off(void);
    void led3On(void);
    void led3Off(void);
    void led4On(void);
    void led4Off(void);
    
    void modeChangeTime(void);


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

