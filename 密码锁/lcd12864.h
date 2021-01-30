#include<reg52.h>

#ifndef _LCD12864
#define _LCD12864//防止头文件被重复引用

#define uint unsigned int
#define uchar unsigned char 

#define Data P1
sbit rs=P2^7;
sbit rw=P2^6;
sbit en=P2^5;
sbit csa=P2^4;
sbit csb=P2^3;

extern void delay(uint i);
extern void lcd_order_write(uchar choice,uchar dat);
extern void lcd_cls();
extern void init_lcd();
extern void lcd_display(uchar row,uchar col,uchar height,uchar weight,uchar * ss);
#endif