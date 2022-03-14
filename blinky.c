
#include "lib/include.h"

unsigned long Led;

void Delay(void){unsigned long volatile time;
  time = 800000;
  while(time){
        time--;
  }
}

int main() {

    volatile uint32_t ui32Loop;
                        //operacione con bitwise
                        // N      J       F     B
    SYSCTL->RCGCGPIO |= (1<<12)|(1<<8)|(1<<5)|(1<<1);
    SYSCTL->RCGCGPIO |= 0x1122;
    while((SYSCTL->PRGPIO&0x00000100) == 0){;} // allow time for clock to stabilize
    ui32Loop = SYSCTL->RCGCGPIO;
    //Salidas
    GPIOB_AHB->DIR |= (1<<4);
    GPIOF_AHB->DIR |= (1<<4) | (1<<0);
        GPION->DIR |= (1<<1) | (1<<0);
    //Entradas
    GPIOJ_AHB->DIR |= (0<<1)|(0<<0);
    GPIOJ_AHB->PUR  |= (1<<1)|(1<<0);//Estado alto
    //Funciones alternativas
    GPIOB_AHB->AFSEL |= 0x00;
    GPIOJ_AHB->AFSEL |= 0x00;
        GPION->AFSEL |= 0x00;
    GPIOF_AHB->AFSEL |= 0x00;
    //Tabla con GPIOCTL
    GPIOB_AHB->PCTL |= 0x00;
    GPIOJ_AHB->PCTL |= 0x00;
        GPION->PCTL |= 0x00;
    GPIOF_AHB->PCTL |= 0x00;
    //Habilitarlos como digitales
    GPIOB_AHB->DEN |= (1<<4);
    GPIOJ_AHB->DEN |= (1<<1) | (1<<0);
        GPION->DEN |= (1<<1) | (1<<0);
    GPIOF_AHB->DEN |= (1<<4) | (1<<0);
    //GPION->DIR  = 0x03; 
    //GPION->DEN  = 0x03;

  /*Super micros*/
/*esto es una actualizacion*/

  while (1U)
  {
        //
        // Turn on the LED.
        //
         GPION->DATA |= 0x01;
        //GPIO_PORTN_DATA_R |= 0x01;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++)
        {
        }
         GPION->DATA |= 0x02;
        //GPIO_PORTN_DATA_R |= 0x01;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++)
        {
        }
        //
        // Turn off the LED.
        //
        GPION->DATA &= ~(0x01);
        //GPIO_PORTN_DATA_R &= ~(0x01);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
                GPION->DATA &= ~(0x02);
        //GPIO_PORTN_DATA_R &= ~(0x01);

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
  }
}