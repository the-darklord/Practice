unsigned char ASCIICODE[16]={
															0x11,0x21,0x41,0x81,
															0x12,0x22,0x42,0x82,
															0x14,0x24,0x44,0x84,
															0x18,0x28,0x48,0x88
														};

unsigned char ASCIICODE[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
														
void delay_lcd(unsigned int r)
{
	unsigned int t;
	for(t=0;t<r;t++);
}

void clear_ports()
{
	LPC_GPIO0->FIOCLR=0xF<<23;
	LPC_GPIO0->FIOCLR=0x3<<27;
}

void write(int temp,int type)
{
	clear_ports();
	LPC_GPIO0->FIOPIN=temp;
	if(!type)
	{
		LPC_GPIO0->FIOCLR=1<<27;
	}
	else
	{
		LPC_GPIO0->FIOSET=1<<27;
	}
	LPC_GPIO0->FIOSET=1<<28;
	delay_lcd(1000);
	LPC_GPIO0->FIOCLR=1<<28;
}

void lcd_comdata(int temp,int type)
{
	int temp2=temp&0xF0;
	temp2=temp2<<19;
	write(temp2,type);
	temp2=temp&0x0F;
	temp2=temp2<<23;
	write(temp2,type);
	delay_lcd(10000);
}	

void lcd_init()
{
	LPC_GPIO0->FIODIR=0xF<<23|1<<27|1<<28;
	clear_ports();
	delay_lcd(3200);
	
	lcd_comdata(0x33,0);
	delay_lcd(30000);
	
	lcd_comdata(0x32,0);
	delay_lcd(30000);
	
	lcd_comdata(0x28,0);
	delay_lcd(30000);
	
	lcd_comdata(0x0C,0);
	delay_lcd(1000);
	
	lcd_comdata(0x06,0);
	delay_lcd(1000);
	
	lcd_comdata(0x01,0);
	delay_lcd(10000);
}

void lcd_puts(unsigned char* str)
{
	unsigned int temp,i=0;
	lcd_comdata(0x80,0);
	while(str[i])
	{
		temp=str[i];
		lcd_comdata(temp,1);
		i++;
		if(i==16)
		{
			lcd_comdata(0xC0,0);
		}
	}
}

void lcd_putn(unsigned int temp)
{
	lcd_comdata(temp,1);
	delay_lcd(1000);
}

void scan()
{
	temp3=LPC_GPIO1->FIOPIN;
	temp3 &= 0xF<<23;
	if(temp3!=0)
	{
		flag=1;
		temp3=temp3>>19;
		var=var>>10;
		key=temp3|var;
	}
}