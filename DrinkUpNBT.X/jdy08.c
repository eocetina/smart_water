#include "jdy08.h"
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdlib.h>

void jdyInitAT(void)
{
    EUSART1_RxDefaultInterruptHandler_back = EUSART1_RxDefaultInterruptHandler;
    EUSART1_SetRxInterruptHandler(jdyResponseHandler);
    BT_PWRC_SetLow();
}

void jdyEndAT(void)
{
    EUSART1_SetRxInterruptHandler(EUSART1_RxDefaultInterruptHandler_back);
    BT_PWRC_SetHigh();
}
int8_t jdyWriteCommand(ATCMD command, const uint8_t wait_ms)
{
    //clear buffer
    memset(jdy_resp_buff,'\0',sizeof(jdy_resp_buff));
    buff_idx = 0;
    const uint8_t* cmd = command.cmd;
    while(*(cmd) != '\0')
    {
        EUSART1_Write(*(cmd++));
        __delay_us(100);
    }
    if(command.params != NULL)
    {
        cmd = command.params;
        while(*(cmd) != '\0')
        {
            EUSART1_Write(*(cmd++));
            __delay_us(100);
        }
    }
    //wait delay for response
    uint8_t n_ms = wait_ms;
    while(n_ms-- >0)
    {
        __delay_ms(1);
    }
    
    if(buff_idx == 0)
        return CMD_TOUT;
   
    if(strstr(jdy_resp_buff,command.response) != NULL)
    {
        return CMD_OK;
    }
    
    return CMD_ERR;
    
}

int8_t jdyDevName(const uint8_t* name)
{
    uint8_t* dev_name = &name[0];
    JDY_NAME.params = dev_name;
    return jdyWriteCommand(JDY_NAME,100);
}

int8_t jdySetPass(const uint8_t* pass)
{
    uint8_t* dev_pass = &pass[0];
    JDY_PASS.params = dev_pass;
    return jdyWriteCommand(JDY_PASS,100);
}

int8_t jdyDisablePass()
{
    const uint8_t dis[] = "0";
    JDY_ISCEN.params = dis;
    return jdyWriteCommand(JDY_ISCEN,100);
}

int8_t jdyVersion()
{
    return jdyWriteCommand(JDY_VER,100);
}



void jdyResponseHandler(void)
{
    if(1 == RC1STAbits.OERR)
    {
        // EUSART1 error - restart

        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
    
    if(buff_idx < sizeof(jdy_resp_buff)-1)
        jdy_resp_buff[buff_idx++] = RC1REG;
    else
        jdy_resp_buff[buff_idx] = RC1REG;
}