#include"lcd12864.h"
void delay(uint i)
{
	while(i--);
}

void lcd_order_write(uchar choice,uchar dat)
{
	rs=choice;//选择是写命令还是数据
	rw=0;//保持写状态
	Data=dat;
	delay(1);
	en=1;
	delay(1);
	en=0;
}

void lcd_cls()//清屏
{
	uchar i,j;
	csa=csb=1;//同时开启两块屏幕，同时操作
	for(i=0;i<8;i++)//总共八页
	{
		lcd_order_write(0,0xb8+i);//当前页
		lcd_order_write(0,0x40);//当前页首
		for(j=0;j<64;j++)
		{
			lcd_order_write(1,0);//写0清屏
		}
	}
}

void init_lcd()
{
	lcd_order_write(0,0xb8);//显示首列地址
	lcd_order_write(0,0x40);//起始列地址
	lcd_order_write(0,0xc0);//起始行地址
	lcd_order_write(0,0x3f);//开显示
	lcd_cls();
}

//显示函数
void lcd_display(uchar row,uchar col,uchar height,uchar weight,uchar * ss)
{
	uchar nowh,noww;
	for(nowh=0;nowh<height;nowh++)
	{
		for(noww=0;noww<weight;noww++)
		{
			if(col+noww<64)
			{
				csa=1;csb=0;
				lcd_order_write(0,0xb8+nowh+row);
				lcd_order_write(0,0x40+col+noww);
				lcd_order_write(1,ss[nowh*weight+noww]);
			}
			else if(col+noww>=64)
			{
				csa=0;csb=1;
				lcd_order_write(0,0xb8+nowh+row);
				lcd_order_write(0,0x40+col+noww-64);
				lcd_order_write(1,ss[nowh*weight+noww]);
			}
		}
	}
}

