#include<reg52.h>

#ifndef KEY_
#define KEY_
#define KEY P0

#define uint unsigned int
#define uchar unsigned char 
#define no_key 0xff

extern uchar key_sign;

enum STATE
{
	key_state0=0,
	key_state1=1,
	key_state2=2,
};

extern uchar witch_key();

#endif

