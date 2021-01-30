#include"keyboard.h"
#include"lcd12864.h"
#include<reg52.h>
#include"work.h"

void ft_dis(uchar*ft_sign)
{
	if(*ft_sign==1)
	{
		lcd_display(0,32,2,16,prompt[3]);
		lcd_display(0,32+16,2,16,prompt[4]);
		lcd_display(0,32+32,2,16,prompt[5]);
		lcd_display(0,32+3*16,2,16,prompt[6]);
		lcd_display(3,16,2,16,prompt[11]);
		lcd_display(3,32,2,16,prompt[16]);
		lcd_display(3,32+16,2,16,prompt[17]);
		lcd_display(3,32+2*16,2,16,prompt[18]);
		lcd_display(3,32+3*16,2,16,prompt[19]);
		lcd_display(3,32+4*16,2,16,prompt[20]);
	}
	else if(*ft_sign==0)
	{
		lcd_display(0,0,2,16,prompt[0]);
		lcd_display(0,16,2,16,prompt[1]);
		lcd_display(0,32,2,16,prompt[2]);
		lcd_display(0,48,2,16,prompt[3]);
		lcd_display(0,64,2,16,prompt[4]);
		lcd_display(2,16,2,8,symbol[0]);
		lcd_display(2,16+8,2,8,symbol[1]);
	}
	else
	{
		lcd_display(0,32,2,16,prompt[3]);
		lcd_display(0,32+16,2,16,prompt[4]);
		lcd_display(0,32+32,2,16,prompt[7]);
		lcd_display(0,32+3*16,2,16,prompt[8]);
		lcd_display(4,24,2,16,prompt[0]);
		lcd_display(4,24+16,2,16,prompt[9]);
		lcd_display(4,24+32,2,16,prompt[10]);
		lcd_display(4,24+3*16,2,16,prompt[1]);
		lcd_display(4,24+4*16,2,16,prompt[2]);
		lcd_display(2,16,2,8,symbol[0]);
		lcd_display(2,16+8,2,8,symbol[1]);
	}
}

void YN_password(char *flag,uchar *ft_sign)
{
	uchar i;
	if(*flag<10)
		{
			switch(witch_key())
			{
			case '0':
				lcd_display(2,24+(*flag+1)*8,2,8,num[0]);
				password[*flag]='0';
				(*flag)++;
				key_sign='n';				
			break;
			case '1':
				lcd_display(2,24+(*flag+1)*8,2,8,num[1]);
				password[*flag]='1';
				(*flag)++;
				key_sign='n';				
			break;
			case '2':
				lcd_display(2,24+(*flag+1)*8,2,8,num[2]);
				password[*flag]='2';
				(*flag)++;
				key_sign='n';				
			break;
			case '3':
				lcd_display(2,24+(*flag+1)*8,2,8,num[3]);
				password[*flag]='3';
				(*flag)++;
				key_sign='n';				
			break;
			case '4':
				lcd_display(2,24+(*flag+1)*8,2,8,num[4]);
				password[*flag]='4';
				(*flag)++;
				key_sign='n';				
			break;
			case '5':
				lcd_display(2,24+(*flag+1)*8,2,8,num[5]);
				password[*flag]='5';
				(*flag)++;
				key_sign='n';
			break;
			case '6':
				lcd_display(2,24+(*flag+1)*8,2,8,num[6]);
				password[*flag]='6';
				(*flag)++;
				key_sign='n';
			break;
			case '7':
				lcd_display(2,24+(*flag+1)*8,2,8,num[7]);
				password[*flag]='7';
				(*flag)++;
				key_sign='n';			
			break;
			case '8':
				lcd_display(2,24+(*flag+1)*8,2,8,num[8]);
				password[*flag]='8';
				(*flag)++;
				key_sign='n';
			break;
			case '9':
				lcd_display(2,24+(*flag+1)*8,2,8,num[9]);
				password[*flag]='9';
				(*flag)++;
				key_sign='n';
			break;
			case 'a':
				lcd_display(2,24+(*flag+1)*8,2,8,num[10]);
				password[*flag]='A';
				(*flag)++;
				key_sign='n';
			break;
			case 'b':
				lcd_display(2,24+(*flag+1)*8,2,8,num[11]);
				(*flag)++;
				key_sign='n';
				password[*flag]='B';
			break;
			case 'c':
				lcd_display(2,24+(*flag+1)*8,2,8,num[12]);
				password[*flag]='C';
				(*flag)++;
				key_sign='n';
			break;
			case 'd':
				lcd_display(2,24+(*flag+1)*8,2,8,num[13]);
				password[*flag]='D';
				(*flag)++;
				key_sign='n';
			break;
			case '*':
				(*flag)--;
				lcd_display(2,24+(*flag+1)*8,2,8,symbol[2]);
				key_sign='n';	
				if(*flag>=0)
					password[*flag]='0';
			break;
			case '#':
				lcd_cls();
				(*flag)=0;
				key_sign='n';
				if(cmp_pass(init_password,password)==0)
				{
					*ft_sign=1;
				}
				else
				{
					*ft_sign=2;
				}
				for(i=0;i<10;i++)
				{password[i]='0';}
			break;
			}
		}
		else 
		{
			switch(witch_key())
			{
			case '*':
				(*flag)--;
				lcd_display(2,24+(*flag+1)*8,2,8,symbol[2]);
				key_sign='n';
				if(*flag>=0)
					password[*flag]='0';
			break;
			case '#':
				lcd_cls();
				(*flag)=0; 
				key_sign='n';
				if(cmp_pass(init_password,password)==0)
				{
					*ft_sign=1;
				}
				else
				{
					*ft_sign=2;
				}
				for(i=0;i<10;i++)
				{password[i]='0';}
			break;
			}
		}
}

void dis_()
{
	lcd_display(0,0,8,113,picture[0]);
	delay(50000);
	lcd_display(0,64+48,2,16,prompt[11]);
	delay(50000);
	lcd_display(2,64+48,2,16,prompt[12]);
	delay(50000);
	lcd_display(4,64+48,2,16,prompt[13]);
	delay(50000);
	lcd_display(6,64+3*16,2,16,prompt[14]);
	delay(50000);

}