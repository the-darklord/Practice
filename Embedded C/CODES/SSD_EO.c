#include <LPC17xx.h>

unsigned char array[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int seg_select[4]={0<<15,1<<15,2<<15,3<<15};
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
    LPC_GPIO0->FIODIR=0xFF<<4|0xF<<15;
    while(1)
    {
        for(i=0;i<=9;i++)
        {
            if(i%2==0)
            {
                LPC_GPIO0->FIOPIN=seg_select[2];
				LPC_GPIO0->FIOPIN=array[i]<<4;
				delay(1000);
            }
            else
            {
                LPC_GPIO0->FIOPIN=seg_select[3];
				LPC_GPIO0->FIOPIN=array[i]<<4;
				delay(1000);
            }
        }
        delay(1000);
		LPC_GPIO0->FIOCLR |= 0xFF<<4|0xF<<15;
    }
}