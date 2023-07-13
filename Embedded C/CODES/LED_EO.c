#include <LPC17xx.h>

unsigned int i;

void delay(unsigned int r)
{
    unsigned int t;
    for(t=0;t<r;t++);
}

int main()
{
    SystemInit();
    SystemCoreClockUpdate();
    LPC_GPIO0->FIODIR=0xFF<<15;
    LPC_GPIO0->FIOPIN &=~(0xFF<<15);
    LPC_GPIO0->FIOPIN |=0xFF<<15;
    while(1)
    {
        LPC_GPIO0->FIOPIN = ~(0x55<<15);
        LPC_GPIO0->FIOPIN = 0xAA<<15;
        delay(10000);
        LPC_GPIO0->FIOPIN = ~(0xAA<<15);
        LPC_GPIO0->FIOPIN = 0x55<<15;
        delay(10000);
    }
}