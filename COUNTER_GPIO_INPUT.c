#include<LPC21xx.h>
int main()

{
	int counter;		
	PINSEL0 &=0XFFFFFFF0;
	IODIR0 &=0XFFFFFFFE;		   //SWITCH	  input
	IODIR0 |=0X00000002;
			   //LED  output
	while(1)
	{
	 
	if((IOPIN0&0X01)==1)
	{	delay(500);
		IOPIN0=counter++;
		}
	}
	return 0;
}
