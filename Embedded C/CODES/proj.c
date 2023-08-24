#include<LPC17xx.h>
#define PRESCALE 2

unsigned char array[10]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};	
unsigned int seg_select[4]={0<<23,1<<23,2<<23,3<<23};
int dig[4]={0,0,0,0};
unsigned int i;

void initTimer0(unsigned int millisecond)
{
    LPC_TIM0->CTCR = 0x0;
    LPC_TIM0->TCR = 0x02;
    LPC_TIM0->PR = 2;
    LPC_TIM0->MR0 = millisecond;
    LPC_TIM0->MCR = 2;
    LPC_TIM0->EMR = 0x20;
    LPC_TIM0->TCR = 0x01;
}

void delayms(unsigned int millisecond)
{
    initTimer0(millisecond);

}

int main()
{
    SystemInit();
    SystemCoreClockUpdate();
    LPC_GPIO0->FIODIR |= 0xFF0;
    LPC_GPIO1->FIODIR |= 0x07800000;
    LPC_GPIO2->FIODIR &= 0xFFFFFFFE;
    LPC_GPIO3->FIODIR = 0x02000000;
    while(1)
    {
        if(!(LPC_GPIO2->FIOPIN&1))
        {
            for(dig[3]=0;dig[3]<10;dig[3]++)
            {
                for(dig[2]=0;dig[2]<10;dig[2]++)
                {
                    for(dig[1]=0;dig[1]<6;dig[1]++)
                    {
                        for(dig[0]=0;dig[0]<10;dig[0]++)
                        {
                            for(i=0;i<4;i++)
                            {
                                LPC_GPIO1->FIOPIN=seg_select[i];
                                LPC_GPIO0->FIOPIN =array[dig[i]]<<4;
                                delayms(1000);
                                if(!(LPC_GPIO2->FIOPIN&1))
                                {
                                    LPC_GPIO3->FIOSET=0x02000000;
                                    delayms(1000);
                                    LPC_GPIO3->FIOCLR=0x02000000;
                                    break;
                                }
                            }
                            if(!(LPC_GPIO2->FIOPIN&1))
                            {
                                LPC_GPIO3->FIOSET=0x02000000;
                                delayms(1000);
                                LPC_GPIO3->FIOCLR=0x02000000;
                                break;
                            }               
                        }
                        if(!(LPC_GPIO2->FIOPIN&1))
                        {
                            LPC_GPIO3->FIOSET=0x02000000;
                            delayms(1000);
                            LPC_GPIO3->FIOCLR=0x02000000;
                            break;
                        }
                    }
                    if(!(LPC_GPIO2->FIOPIN&1))
                    {
                        LPC_GPIO3->FIOSET=0x02000000;
                        delayms(1000);
                        LPC_GPIO3->FIOCLR=0x02000000;
                        break;
                    }   
                }
                if(!(LPC_GPIO2->FIOPIN&1))
                {
                    LPC_GPIO3->FIOSET=0x02000000;
                    delayms(1000);
                    LPC_GPIO3->FIOCLR=0x02000000;
                    break;
                }
            }
        }
    }
    return 0 ;
}