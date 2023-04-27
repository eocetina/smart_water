#include "app.h"
#include "mcc_generated_files/mcc.h"
#include "nvm_interface.h"
#include <string.h>
//#include "mcc_generated_files/pin_manager.h"

void minuteInt(void)
{
    minutes_count--;
    if(minutes_count == 0)
    {
        snooze_cont_en = true;
        if (tilt_cont_en == false && button_cont_en == false)
        {
            tick_100ms = 0;
            TMR1_StartTimer();
        }
        snooze_time_cont = tick_100ms;
        minutes_count = app.app_config.remember_time*5;
    }
}

void buttChangeInt(void)
{
    if(BUTTON_GetValue() == 0)
    {
        button_cont_en = true;
        if (tilt_cont_en == false && snooze_cont_en == false)
        {
            tick_100ms = 0;
            TMR1_StartTimer();
        }
        button_time_cont = tick_100ms;
    }
    else
    {
        if (button_cont_en)
        {
            if((tick_100ms - button_time_cont) > TIME_PUSH_CHANGE*10)
            {
                push_change_event = true;
                push_single_event = false;
            }
            else
            {
                push_change_event = false;
                push_single_event = true;
            }
        }
        button_cont_en = false;
        if (tilt_cont_en == false && snooze_cont_en == false)
        {
            TMR1_StopTimer();
        }
    }
}

void tiltChange(void)
{
    if(TILT_SENSOR_GetValue() == 1)
    {
        tilt_cont_en = true;
        if (button_cont_en == false  && snooze_cont_en == false)
        {
            tick_100ms = 0;
            TMR1_StartTimer();
        }
        tilt_time_cont = tick_100ms;
    }
    else
    {
        if (tilt_cont_en)
        {
            if((tick_100ms - tilt_time_cont) > TIME_SIP*10)
            {
                sip_event = true;
            }
            else
            {
                sip_event = false;
            }
        }
        tilt_cont_en = false;
        if (button_cont_en == false && snooze_cont_en == false)
        {
            TMR1_StopTimer();
        }
    }
}

void tiltChange2(void)
{
    if(CMP2_GetOutputStatus() == 1)
    {
        tilt_cont_en = true;
        if (button_cont_en == false  && snooze_cont_en == false)
        {
            tick_100ms = 0;
            TMR1_StartTimer();
        }
        tilt_time_cont = tick_100ms;
    }
    else
    {
        if (tilt_cont_en)
        {
            if((tick_100ms - tilt_time_cont) > TIME_SIP*10)
            {
                sip_event = true;
            }
            else
            {
                sip_event = false;
            }
        }
        tilt_cont_en = false;
        if (button_cont_en == false && snooze_cont_en == false)
        {
            TMR1_StopTimer();
        }
    }
}

void welcomeLeds(void)
{
    led1On();
    led2On();
    led3On();
    led4On();
    __delay_ms(200);
    led4Off();
    __delay_ms(200);
    led3Off();
    __delay_ms(200);
    led2Off();
    __delay_ms(200);
    led1Off();
    __delay_ms(200);
    
}

void initValues(void)
{
    button_cont_en = false;
    tilt_cont_en = false;
    tilt_time_cont = false;
    
    sip_event = false;
    snooze_event = false;
    
    push_change_event = false;
    push_restore_event = false;
    push_single_event = false;
    
    tick_100ms = 0;
    //minutes_count = 0;
    flag_update_mem = true;
    readValues();
    while(app.app_config.remember_time > 10)
    {
        defaultValues();
        storeValues();
    }
    minutes_count = app.app_config.remember_time*5;
}

void updateLeds(void)
{
    /*LED_T1_SetHigh();
    LED_T2_SetHigh();
    LED_T3_SetHigh();
    LED_T4_SetHigh();
    if(app.app_config.last_time_interval == 0)
    {
        LED_T1_SetLow();
    }
    else if(app.app_config.last_time_interval == 1)
    {
        LED_T2_SetLow();
    }
    else if(app.app_config.last_time_interval == 2)
    {
        LED_T3_SetLow();
    }
    else if(app.app_config.last_time_interval == 3)
    {
        LED_T4_SetLow();
    }*/
}

void defaultValues(void)
{
    app.app_config.remember_time = 2;
    //app.app_config.sip_time = 3;
    //app.app_config.snooze_time = 10;
}

void readValues(void)
{
    readFlashData(USER_STORAGE,&app.app_config_raw[0],sizeof(APP_CONFIG));
}
void storeValues(void)
{
    eraseFlashData(USER_STORAGE,sizeof(APP_CONFIG));
    writeFlashData(USER_STORAGE,app.app_config_raw,sizeof(APP_CONFIG));
    flag_update_mem = false;
}

void timer1Int(void)
{
    tick_100ms++;
}

void led1On(void)
{
    PWM3_LoadDutyValue(LED_BRIGHT_50);
}
void led1Off(void)
{
    PWM3_LoadDutyValue(0);
}

void led2On(void)
{
    PWM4_LoadDutyValue(LED_BRIGHT_50);
}
void led2Off(void)
{
    PWM4_LoadDutyValue(0);
}

void led3On(void)
{
    PWM5_LoadDutyValue(LED_BRIGHT_50);
}
void led3Off(void)
{
    PWM5_LoadDutyValue(0);
}

void led4On(void)
{
    PWM6_LoadDutyValue(LED_BRIGHT_50);
}
void led4Off(void)
{
    PWM6_LoadDutyValue(0);
}

void batteryLeds(void)
{
    adc_result_t VBAT = ADC_GetConversion(VBAT_IN);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    if(VBAT >= VBAT_L1)
    {
        led1On();
    }
    if(VBAT >= VBAT_L2)
    {
        led2On();
    }
    if(VBAT >= VBAT_L3)
    {
        led3On();
    }
    if(VBAT >= VBAT_L4)
    {
        led4On();
    }
    
}

void batteryGetStatus(void)
{
    VBAT = ADC_GetConversion(VBAT_IN);
    batt_stat = NORMAL;
    if(BAT_STAT_GetValue() == 0)
    {
        batt_stat = CHARGING;
    }
    else
    {
        if (VBAT >= VBAT_MAX && batt_stat == CHARGING)
        {
            batt_stat = CHARGED;
        }
        else if(VBAT <= VBAT_MIN)
        {
            batt_stat = VERYLOW;
        }
    }
}

void ledBatteryCharged(void)
{   
    led1On();
    led2On();
    led3On();
    led4On();
    
    __delay_ms(500);
    
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    
    __delay_ms(500);
    
    led1On();
    led2On();
    led3On();
    led4On();
    
    __delay_ms(500);
    
    led1Off();
    led2Off();
    led3Off();
    led4Off();
}
void ledBatteryCharging(void)
{
    VBAT = ADC_GetConversion(VBAT_IN);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(200);
    
    if(VBAT > VBAT_L2)
    {
        led1On();
        __delay_ms(300);
    }
    else
    {
        led1On();
        __delay_ms(400);
        led1Off();
        __delay_ms(400);
        led1On();
        __delay_ms(400);
        led1Off();
        return;
    }
    if(VBAT > VBAT_L3)
    {
        led2On();
        __delay_ms(300);
    }
    else
    {
        led2On();
        __delay_ms(400);
        led2Off();
        __delay_ms(400);
        led2On();
        __delay_ms(400);
        led2Off();
        led1Off();
        return;
    }
    if(VBAT > VBAT_L4)
    {
        led3On();
        __delay_ms(300);
    }
    else
    {
        led3On();
        __delay_ms(400);
        led3Off();
        __delay_ms(400);
        led3On();
        __delay_ms(400);
        led3Off();
        led2Off();
        led1Off();
        return;
    }
    led4On();
    __delay_ms(400);
    led4Off();
    __delay_ms(400);
    led4On();
    __delay_ms(400);
    led4Off();
    led1Off();
    led2Off();
    led3Off();
}

void ledBatteryLow(void)
{
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    uint16_t pwm_val = 60;
    while (pwm_val)
    {
        PWM3_LoadDutyValue(pwm_val);
        /*PWM4_LoadDutyValue(pwm_val);
        PWM5_LoadDutyValue(pwm_val);
        PWM6_LoadDutyValue(pwm_val);*/
        pwm_val--;
        __delay_ms(10);
    }
    
    led1Off();
    led2Off();
    led3Off();
    led4Off();
}
void ledMinutes(void)
{
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    switch(app.app_config.remember_time)
    {
        case 1:
        {
            led1On();
            break;
        }
        case 2:
        {
            led2On();
            break;
        }
        case 3:
        {
            led3On();
            break;
        }
        case 4:
        {
            led4On();
            break;
        }
        case 5:
        {
            led1On();
            led4On();
            break;
        }
        case 6:
        {
            led2On();
            led4On();
            break;
        }
        case 7:
        {
            led4On();
            led3On();
            break;
        }
        case 8:
        {
            led1On();
            led3On();
            led4On();
            break;
        }
        case 9:
        {
            led2On();
            led3On();
            led4On();
            break;
        }
        case 10:
        {
            led1On();
            led2On();
            led3On();
            led4On();
            break;
        }
    }
}

void ledDrinkConfig(void)
{
    ledMinutes();
    __delay_ms(200);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(200);
    ledMinutes();
    __delay_ms(200);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
}

void ledDrinkAlert(void)
{
    /*
    ledMinutes();
    __delay_ms(200);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(200);
    ledMinutes();
    __delay_ms(200);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
     */
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    //
    led1On();
    __delay_ms(200);
    led2On();
    __delay_ms(200);
    led4On();
    __delay_ms(200);
    led3On();
    __delay_ms(400);
    led3Off();
    __delay_ms(200);
    led4Off();
    __delay_ms(200);
    led2Off();
    __delay_ms(200);
    led1Off();
    __delay_ms(200);
}
void ledSip(void)
{
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2On();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2On();
    led3Off();
    led4On();
    __delay_ms(100);
    led1On();
    led2On();
    led3On();
    led4On();
    __delay_ms(100);
    led1On();
    led2Off();
    led3On();
    led4On();
    __delay_ms(100);
    led1On();
    led2Off();
    led3On();
    led4Off();
    __delay_ms(100);
    led1On();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
}

void ledSave(void)
{
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2On();
    led3On();
    led4On();
    __delay_ms(100);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2On();
    led3On();
    led4On();
    __delay_ms(100);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    __delay_ms(100);
    led1On();
    led2On();
    led3On();
    led4On();
    __delay_ms(100);
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    
}

void ledRestore(void)
{
    led1Off();
    led2Off();
    led3Off();
    led4Off();
    uint16_t pwm_val = 1023;
    while (pwm_val)
    {
        PWM3_LoadDutyValue(pwm_val);
        PWM4_LoadDutyValue(pwm_val);
        PWM5_LoadDutyValue(pwm_val);
        PWM6_LoadDutyValue(pwm_val);
        pwm_val--;
        __delay_ms(2);
    }
    
    led1Off();
    led2Off();
    led3Off();
    led4Off();
}

void modeChangeTime(void)
{
    PIE0bits.IOCIE = 0;
    PIE0bits.TMR0IE = 0;
    bool mode = true;
    uint32_t initial_time;
    //ledDrinkAlert();
    ledMinutes();
    while(mode)
    {
        TMR1_StartTimer();
        tick_100ms = 0;
        while(BUTTON_GetValue() == 1);
        initial_time = tick_100ms;
        while(BUTTON_GetValue() == 0)
        {
            if ((tick_100ms - initial_time) > TIME_PUSH_SAVE*10)
            {
                TMR1_StopTimer();
                storeValues();
                ledSave();
                mode = false;
                PIE0bits.IOCIE = 1;
                PIE0bits.TMR0IE = 1;
                return;
            }
        }
        TMR1_StopTimer();
        __delay_ms(300);
        app.app_config.remember_time++;
        if(app.app_config.remember_time > 10)
            app.app_config.remember_time = 1;
        ledMinutes();
        
    }
}