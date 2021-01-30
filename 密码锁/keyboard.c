#include"keyboard.h"
uchar key_sign='n';

uchar witch_key()
{
	static uchar key_mem;
	uchar key1,key2,key;
	KEY=0xf0;
	key1=KEY&0xf0;//保留高四位
	KEY=0x0f;
	key2=KEY&0x0f;//保留低四位
	key=key1|key2;
	switch(key_mem)
	{
		case key_state0:
			if(key!=no_key)key_mem=key_state1;
		break;
		case key_state1:
			if(key==no_key)key_mem=key_state0;//判断按键误触
			else//确定按下
			{
				switch(key)
				{
					case 0xee:key_sign='1';break;
					case 0xde:key_sign='2';break;
					case 0xbe:key_sign='3';break;
					case 0x7e:key_sign='a';break;
					case 0xed:key_sign='4';break;
					case 0xdd:key_sign='5';break;
					case 0xbd:key_sign='6';break;
					case 0x7d:key_sign='b';break;
					case 0xeb:key_sign='7';break;
					case 0xdb:key_sign='8';break;
					case 0xbb:key_sign='9';break;
					case 0x7b:key_sign='c';break;
					case 0xe7:key_sign='*';break;
					case 0xd7:key_sign='0';break;
					case 0xb7:key_sign='#';break;
					case 0x77:key_sign='d';break;
				}
				key_mem=key_state2;
			}
			break;
		case key_state2:
			if(key==no_key)//按键松开
				key_mem=key_state0;
			break;
	}
	return key_sign;
}


