#include"lcd12864.h"
void delay(uint i)
{
	while(i--);
}

void lcd_order_write(uchar choice,uchar dat)
{
	rs=choice;//ѡ����д���������
	rw=0;//����д״̬
	Data=dat;
	delay(1);
	en=1;
	delay(1);
	en=0;
}

void lcd_cls()//����
{
	uchar i,j;
	csa=csb=1;//ͬʱ����������Ļ��ͬʱ����
	for(i=0;i<8;i++)//�ܹ���ҳ
	{
		lcd_order_write(0,0xb8+i);//��ǰҳ
		lcd_order_write(0,0x40);//��ǰҳ��
		for(j=0;j<64;j++)
		{
			lcd_order_write(1,0);//д0����
		}
	}
}

void init_lcd()
{
	lcd_order_write(0,0xb8);//��ʾ���е�ַ
	lcd_order_write(0,0x40);//��ʼ�е�ַ
	lcd_order_write(0,0xc0);//��ʼ�е�ַ
	lcd_order_write(0,0x3f);//����ʾ
	lcd_cls();
}

//��ʾ����
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

