#include<LPC21xx.h>
int main()
{
	PINSEL0 &=0XFFFFFFF0;
	IODIR0 &=0XFFFFFFFE;		   
	IODIR0 |=0X00000002;
	while(1)
	{
	if((IOPIN0&0X01)==1)
	{
		IOSET0|=0x00000002;
		}
	else
	{
		IOCLR0|=0x00000002;
		}
	}
	return 0;
}
