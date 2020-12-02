#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

extern void game(int speed);

void init_choice_window()
{
	initgraph(200, 300);
	setbkcolor(RGB(135, 206, 255));
	cleardevice();//清空背景
	setlinecolor(WHITE);
	settextcolor(WHITE);
	settextstyle(16, 8, _T("隶书"));
	outtextxy(130, 15, _T("游戏说明"));
	outtextxy(15, 15, _T("退出游戏"));
	settextstyle(40, 20, _T("隶书"));
	outtextxy(40, 60, _T("贪吃蛇"));
	outtextxy(60, 120, _T("简单"));
	outtextxy(60, 180, _T("一般"));
	outtextxy(60, 240, _T("困难"));
	rectangle(10, 10, 80, 35);
	rectangle(125, 10, 195, 35);
	rectangle(55, 115, 145, 165);
	rectangle(55, 175, 145, 225);
	rectangle(55, 235, 145, 285);
}

void opengraph()
{
	initgraph(200, 300);
	setbkcolor(RGB(135, 206, 255));
	cleardevice();//清空背景
	settextcolor(WHITE);
}
//用键盘WSAD控制蛇的方向，寻找吃的东西，
//每吃一口就能得到一定的积分，
//而且蛇的身子会越吃越长，身子越长玩的难度就越大，
//不能碰墙，不能咬到自己的身体，更不能咬自己的尾巴，等到了一定的分数，就能过关
void game_exp()
{
	initgraph(300, 300);
	setbkcolor(RGB(135, 206, 225));
	cleardevice();
	setlinecolor(WHITE);
	settextcolor(BLACK);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();//获取鼠标信息
		if (m.x > 165 && m.x < 255 && m.y>255 && m.y < 285)
		{
			settextcolor(RED);
			outtextxy(170, 260, _T("返回游戏"));
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				return;
			}
		}
		else
		{
			settextcolor(WHITE);
			setlinecolor(WHITE);
			settextstyle(20, 10, _T("隶书"));
			outtextxy(20, 20, _T("    用键盘WSAD空格控制蛇，"));
			outtextxy(20, 55, _T("寻找吃的东西，每吃一口就能"));
			outtextxy(20, 90, _T("得到一定的积分，而且蛇的身"));
			outtextxy(20, 125, _T("子会越长，身子越长玩的难度"));
			outtextxy(20, 160, _T("就越大，不能碰墙，不能咬到"));
			outtextxy(20, 195, _T("自己的身体，更不能咬到自己"));
			outtextxy(20, 225, _T("的尾巴，等到了一定的分数，"));
			outtextxy(20, 260, _T("就能过关！"));
			outtextxy(170, 260, _T("返回游戏"));
			rectangle(165, 255, 255, 285);
		}
	}
}

int choice_mode()
{
	MOUSEMSG m;
	m = GetMouseMsg();//获取鼠标信息
	if (m.x > 55 && m.x < 145 && m.y>115 && m.y < 165)
	{
		settextcolor(RED);
		outtextxy(60, 120, _T("简单"));
		if (m.uMsg == WM_LBUTTONDOWN)//如果鼠标左键点下
		{
			closegraph();
			game(SPEED_1);
			opengraph();
		}
	}
	else if (m.x > 55 && m.x < 145 && m.y>175 && m.y < 225)
	{
		settextcolor(RED);
		outtextxy(60, 180, _T("一般"));
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			game(SPEED_2);
			opengraph();
		}
	}
	else if (m.x > 55 && m.x < 145 && m.y>235 && m.y < 285)
	{
		settextcolor(RED);
		outtextxy(60, 240, _T("困难"));
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			game(SPEED_3);
			opengraph();
		}
	}
	else if (m.x > 125 && m.x < 195 && m.y>10 && m.y < 35)
	{
		settextcolor(RED);
		settextstyle(16, 8, _T("隶书"));
		outtextxy(130, 15, _T("游戏说明"));
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			game_exp();
			opengraph();
		}
	}
	else if (m.x > 10 && m.x < 80 && m.y>10 && m.y < 35)
	{
		settextcolor(RED);
		settextstyle(16, 8, _T("隶书"));
		outtextxy(15, 15, _T("退出游戏"));
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			return 1;
		}
	}
	else
	{
		setlinecolor(WHITE);
		settextcolor(WHITE);
		settextstyle(16, 8, _T("隶书"));
		outtextxy(130, 15, _T("游戏说明"));
		outtextxy(15, 15, _T("退出游戏"));
		settextstyle(40, 20, _T("隶书"));
		outtextxy(40, 60, _T("贪吃蛇"));
		outtextxy(60, 120, _T("简单"));
		outtextxy(60, 180, _T("一般"));
		outtextxy(60, 240, _T("困难"));
		rectangle(10, 10, 80, 35);
		rectangle(125, 10, 195, 35);
		rectangle(55, 115, 145, 165);
		rectangle(55, 175, 145, 225);
		rectangle(55, 235, 145, 285);
	}
}

int main()
{
	init_choice_window();
	while (1)
	{
		if (choice_mode() == 1)
			break;
	}
	return 0;
}