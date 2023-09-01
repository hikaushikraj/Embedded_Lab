int main()
{
	int flag=0;
	PINSEL0=0X00000000;
	IODIR0=OXFFFFFFFE
	while(1)
	{
		if ((IOPIN0 & 0x00000001)==0x1 & (flag==0))
		{
			IOPIN0+=0X2;
			flag=1;
		}
		else
		{
		 	IOPIN0=IOPIN0;
			if ((IOPIN0 & 0X00000001)==0X0 & (flag==1)
			{
				flag=0;
			}
		}
	}
}