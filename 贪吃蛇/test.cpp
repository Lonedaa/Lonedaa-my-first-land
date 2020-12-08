#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"

extern void game(int speed);

void init_choice_window()
{
	initgraph(200, 300);
	setbkcolor(RGB(135, 206, 255));
	cleardevice();//��ձ���
	setlinecolor(WHITE);
	settextcolor(WHITE);
	settextstyle(16, 8, _T("����"));
	outtextxy(130, 15, _T("��Ϸ˵��"));
	outtextxy(15, 15, _T("�˳���Ϸ"));
	settextstyle(40, 20, _T("����"));
	outtextxy(40, 60, _T("̰����"));
	outtextxy(60, 120, _T("��"));
	outtextxy(60, 180, _T("һ��"));
	outtextxy(60, 240, _T("����"));
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
	cleardevice();//��ձ���
	settextcolor(WHITE);
}
//�ü���WSAD�����ߵķ���Ѱ�ҳԵĶ�����
//ÿ��һ�ھ��ܵõ�һ���Ļ��֣�
//�����ߵ����ӻ�Խ��Խ��������Խ������ѶȾ�Խ��
//������ǽ������ҧ���Լ������壬������ҧ�Լ���β�ͣ��ȵ���һ���ķ��������ܹ���
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
		m = GetMouseMsg();//��ȡ�����Ϣ
		if (m.x > 165 && m.x < 255 && m.y>255 && m.y < 285)
		{
			settextcolor(RED);
			outtextxy(170, 260, _T("������Ϸ"));
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
			settextstyle(20, 10, _T("����"));
			outtextxy(20, 20, _T("    �ü���WSAD�ո�����ߣ�"));
			outtextxy(20, 55, _T("Ѱ�ҳԵĶ�����ÿ��һ�ھ���"));
			outtextxy(20, 90, _T("�õ�һ���Ļ��֣������ߵ���"));
			outtextxy(20, 125, _T("�ӻ�Խ��������Խ������Ѷ�"));
			outtextxy(20, 160, _T("��Խ�󣬲�����ǽ������ҧ��"));
			outtextxy(20, 195, _T("�Լ������壬������ҧ���Լ�"));
			outtextxy(20, 225, _T("��β�ͣ��ȵ���һ���ķ�����"));
			outtextxy(20, 260, _T("���ܹ��أ�"));
			outtextxy(170, 260, _T("������Ϸ"));
			rectangle(165, 255, 255, 285);
		}
	}
}

int choice_mode()
{
	MOUSEMSG m;
	m = GetMouseMsg();//��ȡ�����Ϣ
	if (m.x > 55 && m.x < 145 && m.y>115 && m.y < 165)
	{
		settextcolor(RED);
		outtextxy(60, 120, _T("��"));
		if (m.uMsg == WM_LBUTTONDOWN)//�������������
		{
			closegraph();
			game(SPEED_1);
			opengraph();
		}
	}
	else if (m.x > 55 && m.x < 145 && m.y>175 && m.y < 225)
	{
		settextcolor(RED);
		outtextxy(60, 180, _T("һ��"));
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
		outtextxy(60, 240, _T("����"));
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
		settextstyle(16, 8, _T("����"));
		outtextxy(130, 15, _T("��Ϸ˵��"));
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
		settextstyle(16, 8, _T("����"));
		outtextxy(15, 15, _T("�˳���Ϸ"));
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			return 1;
		}
	}
	else
	{
		setlinecolor(WHITE);
		settextcolor(WHITE);
		settextstyle(16, 8, _T("����"));
		outtextxy(130, 15, _T("��Ϸ˵��"));
		outtextxy(15, 15, _T("�˳���Ϸ"));
		settextstyle(40, 20, _T("����"));
		outtextxy(40, 60, _T("̰����"));
		outtextxy(60, 120, _T("��"));
		outtextxy(60, 180, _T("һ��"));
		outtextxy(60, 240, _T("����"));
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