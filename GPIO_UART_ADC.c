#include<lpc214x.h>
//char *ptr;
void delay(unsigned int w)
{
	unsigned int i,j;
	for (i=0;i<w;i++)
	 	for (j=0;j<200;j++);		
}
 int main()
 {		 //char* StringPtr;
 		 //char myString[5] = {0};
		 int i=3,j=3;
		 int digits[3];
		 int value=856;
		//Program to blink led based on ADC conversion value, for vcc>700 led on; for vcc<400 led off; vcc digital value shown using UART
		
		//Select pins as GPIO
																			  
		PINSEL0 = 0x00000000;
		PINSEL1 = 0x00000000;
		
		// configure input, output
		IODIR0 &=	0xFFFFFFBF;			//pin 0.6 is for switch input
		IODIR0 |= (1<<17);				//pin 0.17 is led output
		
		// configure UART0 Txd & Rx
		PINSEL0 |= 0X00000001;
		// configure AD0.4
		PINSEL1 &= 0xfff7ffff;
		PINSEL1 |= 0X00080000;
		PCONP |= (1<<12);

		while(1)
		{
		  value=876;
		  IO0PIN &= 0xFFFCFFFF;
		 //check if 0.6 is high
		 if ((IOPIN0 & 0x00000040))
		 {
		 	
		  //Do ADC Conversion on AD0.4
		    AD0CR=0x00000010;	//select AD0.4		could just select 4th bit using AD0CR |= (1<<4), 7:0 bits used to select the AD0 channel no AD0.5
			AD0CR |= 0x00000700; //set ADC clock as VPB or (PCLK/8)	  bit 8 to 15 for configuring clock
			AD0CR &= 0xFFFEFFFF; //Disabling burst mode of ADC it is done at bit 16
			AD0CR &= 0xFFF1FFFF; // RESOLUTION SET TO 10 BY SETTING BIT 19:17 AS 0 MIN 3 BIT SUPPORTED AND SET BY USING ALL 1
			AD0CR |= 0x00200000; // Activating ADC using bit 21
			AD0CR |= 0x01000000; // SETTING BIT 26:24 001 FOR CONVERSION NOW
		
			while((AD0GDR & 0x80000000)==0); //polling for bit 31 to be free i.e 0
		
			//value=((AD0GDR>>6) & 0x000003FF); // result is in bit 15:6 so shifted right by 6 place to have it in 9:0 then masked other bits to get what's imp
		
			AD0CR &= 0xF8FFFFFf;
		
			delay(100); 
		
			//LED on off based on Vcc input
		
			if (value>=7)
			{
				IO0PIN|=(1<<17);
			}
			else if (value<=4)
			{
				IO0PIN &= 0xFFF7FFFF;
			}
			delay(200);
		
			 // UART Transmission of digital  value
		
			 //snprintf(myString, sizeof(myString), "%d", value);
			 //StringPtr=myString
		
					// 8 bit length
			 U0LCR = 0x83;	// Enable access to Divisor Latch
			 U0DLL = 97;
			 U0LCR = 0x03; 	// Disable access to Divisor Latch

			 
			 while(i!=0)
			 {
			 	 digits[--i]=value%10;
				 value=value/10;
			 }		
	
		      while(j)
				{
					while(!(U0LSR & 0x20));	// wait till the THR is empty
			 		U0THR = '0'+digits[3-j];// now we can write to the Tx FIFO
					j=j-1;			
				}
			
			 }
			 
		}

}	



