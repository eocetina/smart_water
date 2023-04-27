/**
  EUSART1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    eusart1.h

  @Summary
    This is the generated header file for the EUSART1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for EUSART1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15344
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15
*/

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

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
    //+JDY-08-V3.385
    /**
     * Definitions
     */
    typedef struct
    {
        const uint8_t* cmd;
        const uint8_t* response;
        uint8_t* params;
    } ATCMD;
    
    ATCMD JDY_NAME = {(const uint8_t*)"AT+NAME",(const uint8_t*)"OK"};
    ATCMD JDY_RST = {(const uint8_t*)"AT+RST",(const uint8_t*)"OK"};
    ATCMD JDY_DISC = {(const uint8_t*)"AT+DISC",(const uint8_t*)"OK"};
    ATCMD JDY_VER = {(const uint8_t*)"AT+VER",(const uint8_t*)"JDY"};
    ATCMD JDY_ISCEN = {(const uint8_t*)"AT+ISCEN",(const uint8_t*)"OK"};
    ATCMD JDY_PASS = {(const uint8_t*)"AT+PASS",(const uint8_t*)"PASS"};
    
    const int8_t CMD_OK = 0;
    const int8_t CMD_ERR = -1;
    const int8_t CMD_TOUT = -2;
    
    /**
     * Global variables
     */
    volatile uint8_t jdy_resp_buff[16];
    volatile uint8_t buff_idx;
    void (*EUSART1_RxDefaultInterruptHandler_back)(void);
    
    /**
     * Functions prototypes
     */
    void jdyInitAT(void);
    void jdyEndAT(void);
    int8_t jdyWriteCommand(ATCMD command, const uint8_t wait_ms);
    int8_t jdyDevName(const uint8_t* name);
    int8_t jdyDisablePass();
    int8_t jdySetPass(const uint8_t* pass);
    int8_t jdyVersion();
    void jdyResponseHandler(void);

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

