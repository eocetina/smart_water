#include <xc.h>
#include <stdlib.h>
#include "nvm_interface.h"

void readFlashData(uint16_t add,uint8_t* data_w14b, uint16_t size)
{
    //free(*data_w14b);
    //*data_w14b = malloc(size * sizeof(uint8_t));
    //if (*data_w14b == NULL)
    //    return;
    //Read PFM
    NVMCON1bits.NVMREGS = 0;
    //Address to read
    NVMADR = add;
    uint16_t idx;
    for (idx = 0; idx < size; idx++)
    {
        //Start to read
        NVMCON1bits.RD = 1;
        data_w14b[idx] = (uint8_t)NVMDAT&(0xff);
        NVMADR++;
    }
    /*while(size)
    {
        //Start to read
        NVMCON1bits.RD = 1;
        //Copy the read data to destination array and increase pointer
        *(data++) = (uint8_t)(NVMDATL);
        size--;
        NVMADR++;
    }*/
}

void eraseFlashData(uint16_t add, uint16_t size)
{  
    uint16_t rows = size/32;
    uint16_t idx =0;
    if(size%32)
    {
        rows++;
    }
    uint8_t flagGIE = INTCONbits.GIE;
    
    for(idx = 0; idx < rows; idx++)
    {
        NVMADR = add+idx*32;
        NVMCON1bits.NVMREGS = 0;
        NVMCON1bits.FREE = 1;
        NVMCON1bits.WREN = 1;
        INTCONbits.GIE = 0;
        NVMCON2 = 0x55;
        NVMCON2 = 0xAA;
        NVMCON1bits.WR = 1;
        INTCONbits.GIE = flagGIE;
        NVMCON1bits.WREN = 0;
    }
    //NVMCON1bits.WREN = 0;
    
    
    
}

void writeFlashData(uint16_t add,uint8_t* data_w14b, uint16_t size)
{
    NVMADR = add;
    uint8_t* data = data_w14b;
    NVMCON1bits.NVMREGS = 0;
    NVMCON1bits.WREN = 1;
    NVMCON1bits.LWLO = 1;
    uint16_t idx;
    uint8_t flagGIE = INTCONbits.GIE;
    INTCONbits.GIE = 0;
    for(idx = 0; idx < size; idx++)
    {
        NVMDAT = data[idx];
        if(NVMCON1bits.WREN == 0)
        {
            NVMCON1bits.WREN = 1;
            NVMCON1bits.LWLO = 1;
        }
        if((NVMADRL^0x1f)&0x1f)
        {
            //unlock sequence
            NVMCON2 = 0x55;
            NVMCON2 = 0xAA;
            NVMCON1bits.WR = 1;
            //increment address
            NVMADR++;
        }
        else
        {
            NVMCON1bits.LWLO = 0;
            //unlock sequence
            //INTCONbits.GIE = 0;
            NVMCON2 = 0x55;
            NVMCON2 = 0xAA;
            NVMCON1bits.WR = 1;
            //INTCONbits.GIE = flagGIE;
            NVMCON1bits.WREN = 0;
            NVMADR++;
        }
    }
    if(NVMCON1bits.WREN == 1)
    {
        NVMADRL = NVMADRL&(~0x1f);
        NVMADR += 0x1f;
        NVMCON1bits.LWLO = 0;
        //unlock sequence
        //INTCONbits.GIE = 0;
        NVMCON2 = 0x55;
        NVMCON2 = 0xAA;
        NVMCON1bits.WR = 1;
        //INTCONbits.GIE = flagGIE;
        NVMCON1bits.WREN = 0;
    }
    INTCONbits.GIE = flagGIE;
}

