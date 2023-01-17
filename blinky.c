
//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2013-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include "../inc/tm4c1294ncpdt.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************

int main(void)
{
    volatile uint32_t ui32Loop;

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    //SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R12 | SYSCTL_RCGCGPIO_R5;
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R1; //puerto b 

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGCGPIO_R;

    //
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //


    GPIO_PORTB_AHB_DIR_R = (0x10); //pb4, bit 4 en hexadecimal 
    GPIO_PORTB_AHB_DEN_R = (0x10);


    /*
    GPIO_PORTN_DIR_R = (0x01) | (0x00);
    GPIO_PORTN_DEN_R = (0x01) | (0x00);
    GPIO_PORTF_AHB_DIR_R = (0x01);
    GPIO_PORTF_AHB_DEN_R = (0x01);
    */
    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED.
        //
        GPIO_PORTB_AHB_DATA_R |= (0x10);
        /*
        GPIO_PORTN_DATAR |= 0x01;
        GPIO_PORTN_DATA_R |= 0x00;
        GPIO_PORTF_AHB_DATA_R |= 0x01;
        */

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 746269; ui32Loop++)
        {
        }

        //
        // Turn off the LED.
        //
      
        GPIO_PORTB_AHB_DATA_R &= ~(0x10);
        /*
        GPIO_PORTN_DATA_R &= ~(0x00);
        GPIO_PORTF_AHB_DATA_R &= ~(0x00);
        GPIO_PORTN_DATA_R &= ~(0x01);
        */

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 746271; ui32Loop++)
        {
        }
    }
}
//Holis bolis