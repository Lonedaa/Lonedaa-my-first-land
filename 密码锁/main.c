#include"keyboard.h"
#include"lcd12864.h"
#include<reg52.h>
extern void ft_dis(uchar *ft_sign);
extern void YN_password(char* flag,uchar* ft_sign);
extern void dis_();

void main()
{
	while(1)
	{
		char flag=0;
		uchar ft_sign=0;
		init_lcd();//≥ı ºªØœ‘ æ∆¡
		while(1)
		{
			if(flag<0)flag=0;
			YN_password(&flag,&ft_sign);
			ft_dis(&ft_sign);
			if(ft_sign==1)
			{
				delay(50000);
				delay(50000);
				delay(50000);
				delay(50000);
				lcd_cls();
				break;
			}
		}
		while(1)
		{
			dis_();
		}
	}
}