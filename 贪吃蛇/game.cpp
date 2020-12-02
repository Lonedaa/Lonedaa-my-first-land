#define _CRT_SECURE_NO_WARNINGS 1

//个人所想
//贪吃蛇的移动就是首元结点变化，其他节点继承其前端节点坐标
//
//贪吃蛇吃食物的实质就是获取一个新的节点空间添加到自己的身体中
//由于贪吃蛇除了首元节点需要接收键盘信息，其他的节点都是继承其前端节点的坐标
//所以新的节点不能添加到首元结点之后，只能添加在尾结点之前，然后继承其之前的尾结点的前端节点的坐标
//
//因为是双向链表，所以在增加蛇身是需要对前端后继节点同时操作

#include"snake.h"
link head, end;
char key_tmp = 0;//键值暂存  转向方向
char key = 'd';//当前蛇头方向
int scord_1 = '0';//分数
int scord_2 = '0';//分数
int scord_3 = '0';//分数
int foodnum = 4;
int size = 0;
char tmp = 0;
FOOD food[4];//创建食物

void creat_snake_list()//创建双向链表
{
	head = (link)malloc(sizeof(snake));//表头开辟空间
	end = (link)malloc(sizeof(snake));//表尾开辟空间
	head->last = NULL;
	head->next = end;
	end->last = head;
	end->next = NULL;
}

void creat_snake_head(link head, link end)//创建贪吃蛇
{
	link body;//蛇身
	body = (link)malloc(sizeof(snake));//蛇身开辟空间
	head->next = body;
	body->last = head;
	body->next = end;
	end->last = body;
	body->xx = 15;//初始蛇身x坐标
	body->yy = 15;//初始蛇身y坐标
}

void draw_scord()
{
	settextcolor(BLACK);
	setlinecolor(BLACK);
	settextstyle(30, 15, _T("隶书"));
	outtextxy(20, 20, scord_3);
	outtextxy(50, 20, scord_2);
	outtextxy(80, 20, scord_1);
	rectangle(15, 15, 100, 55);
}

void gaming_menu()
{
	settextcolor(BLACK);
	setlinecolor(BLACK);
	settextstyle(30, 15, _T("隶书"));
	outtextxy(560, 20, _T("‖"));
	rectangle(555, 15, 595, 55);
}

void draw_snake_body(link head, link end)
{
	draw_scord();
	BeginBatchDraw();
	link p;
	p = head->next;//==body,双向链表前端节点尾指针指向下一个节点(后继节点)
	setfillcolor(RGB(255,0,0));//蛇身颜色
	setlinecolor(RGB(177, 255, 212));//将蛇身（圆）的边框设置成背景色
	while (p != end)//当head->next不指向表尾时，循环打印蛇身
	{
		fillcircle((p->xx * 20) - 10, (p->yy * 20) - 10, 10);//绘制蛇身
		p = p->next;
	}
	EndBatchDraw();
	p = NULL;//将代管理指针置空，防止野指针
}

void hide_snake_body(link head,link end)//实则就是用背景色覆盖掉蛇身
{
	BeginBatchDraw();
	link p;
	p = head->next;//==body,双向链表前端节点尾指针指向下一个节点(后继节点)
	setfillcolor(RGB(177, 255, 212));//蛇身颜色
	setlinecolor(RGB(177, 255, 212));//将蛇身（圆）的边框设置成背景色
	while (p != end)//当head->next不指向表尾时，循环打印蛇身
	{
		fillcircle((p->xx * 20) - 10, (p->yy * 20) - 10, 10);//绘制蛇身
		p = p->next;
	}
	EndBatchDraw();
	p = NULL;//将代管理指针置空，防止野指针
}

void check_key(char key_t)
{
	if (key_t == 0)
		key_t = 0;
	else if (key_t == 'w'&&key != 's') //蛇头转向方向不能与当前移动方向相反
		key = key_t;
	else if (key_t == 's'&&key != 'w')
		key = key_t;
	else if (key_t == 'a'&&key != 'd')
		key = key_t;
	else if (key_t == 'd'&&key != 'a')
		key = key_t;
	else if (key_t == ' ')
	{
		tmp = key;
		key = key_t;
	}
}

void snake_move(link head, link end)
{
	link p,q;
	p = head->next;
	q = end->last;
	while (q->last != head)//在头节点坐标变化之前把之后每个节点的前端节点坐标赋值给自己
	{
		q->xx = q->last->xx;
		q->yy = q->last->yy;
		q = q->last;
	}
	if (key == 'd')
		p->xx++;
	else if (key == 'a')
		p->xx--;
	else if (key == 's')
		p->yy++;
	else if (key == 'w')
		p->yy--;
	else if (key = ' ')
	{
		settextcolor(RED);
		setlinecolor(BLACK);
		settextstyle(30, 15, _T("隶书"));
		outtextxy(565, 20, _T("▶"));
		rectangle(555, 15, 595, 55);
		if (tmp == 'd')
			p->xx++;
		else if (tmp == 'a')
			p->xx--;
		else if (tmp == 's')
			p->yy++;
		else if (tmp == 'w')
			p->yy--;
		while (1)
		{
			fflush(stdin);
			draw_snake_body(head,end);
			key_tmp = _getch();//获取敲击的键值
			if (key_tmp== ' ')
			{
				key = tmp;
				key_tmp = tmp;
				break;
			}
		}
	}
	p = NULL;//将代管理指针置空，防止野指针
	q = NULL;
} 

int check_SnakeAndWall(link head, link end)
{
	link p = head->next;
	if (p->xx <= 0 || p->xx > 30 || p->yy <= 0 || p->yy > 30)
	{
		p = NULL;//将代管理指针置空，防止野指针
		return 1;//撞墙返回1
	}
	p = NULL;//将代管理指针置空，防止野指针
	return 0;
}

int check_SnakeAndBody(link head, link end)
{
	link p,q;
	q = head->next;
	p = q->next;
	while (p != end)
	{
		if (q->xx == p->xx&&q->yy == p->yy)
		{
			p = NULL;//将代管理指针置空，防止野指针
			q = NULL;
			return 1;
		}
		p = p->next;
	}
	p = NULL;//将代管理指针置空，防止野指针
	q = NULL;
	return 0;
}

int check_food(int i,link* p)
{
	for (int j = 0; j < foodnum&&j != i; j++)
	{
		if (food[j].xx == food[i].xx && food[j].yy == food[i].yy)
		{
			*p = head->next;
			food[i].xx = rand() % 29 + 1;
			food[i].yy = rand() % 29 + 1;
			return 1;
		}
	}
	return 0;
}

void creat_food(link head, link end,int i)
{
	link p = head->next;
	food[i].xx = rand() % 29 + 1;//随机x
	food[i].yy = rand() % 29 + 1;//随机y
	while (1)
	{
		while (!(food[i].xx == p->xx && food[i].yy == p->yy))//当食物与蛇重叠时跳出循环重新生成
		{
			p = p->next;
			if (p == end)//当蛇身全部检查完仍没有重叠，跳出返回函数
			{
				if (check_food(i, &p) == 0)
				{
					return;
				}
			}
		}
		food[i].xx = rand() % 29 + 1;
		food[i].yy = rand() % 29 + 1;
	}
	p = NULL;
}

void draw_food(FOOD food)
{
	setlinecolor(RGB(58, 95, 205));
	setfillcolor(RGB(58, 95, 205));
	fillcircle((food.xx * 20) - 10, (food.yy * 20) - 10, 5);//绘制食物
}

int check_SnakeAndFood(FOOD *food, link head, link end)
{
	link p = head->next;
	for (int i = 0; i < 4; i++)
	{
		if (food[i].xx == p->xx && food[i].yy == p->yy)
		{
			p = NULL;//置空管理指针
			scord_1++;
			size = i;
			foodnum--;
			if (scord_1 >'9')
			{
				scord_1 = '0';
				scord_2++;
				if (scord_2 >'9')
				{
					scord_2 = '0';
					scord_3++;
				}
			}
			return 1;
		}
	}
	p = NULL;
	return 0;
}

void SnakeAdd(link head, link end,int size)
{
	link body = (link)malloc(sizeof(SNAKE));//为增加节点添加空间
	link p;//插入节点
	/*body->xx = food.xx;
	body->yy = food.yy;*/
	p = end->last;
	p->next = body;
	end->last = body;
	body->last = p;
	body->next = end;
	p = NULL;
	if (foodnum < 4)
	{
		creat_food(head, end, size);
		foodnum++;
	}
}

void fail_reason_wall()
{
	char choice;
	choice = rand() % 4;
	settextcolor(RED);//设置字体颜色
	settextstyle(50, 25, _T("隶书"));
	switch (choice)
	{
	case SENT1:
		outtextxy(40, 200, _T("太遗憾了，竟然撞墙了！"));
		break;
	case SENT2:
		outtextxy(125, 200, _T("你也太笨了吧！"));
		break;
	case SENT3:
		outtextxy(100, 200, _T("走路不要玩手机！"));
		break;
	case SENT4:
		outtextxy(50, 200, _T("*眼镜带上 走路不慌*"));
		break;
	}
}

void fail_reason_body()
{
	char choice;
	choice = rand() % 4;
	settextcolor(RED);//设置字体颜色
	settextstyle(50, 25, _T("隶书"));
	switch (choice)
	{
	case SENT1:
		outtextxy(75, 200, _T("好家伙，自己都咬！"));
		break;
	case SENT2:
		outtextxy(125, 200, _T("你也太笨了吧！"));
		break;
	case SENT3:
		outtextxy(150, 200, _T("*再接再厉*"));
		break;
	case SENT4:
		settextstyle(50, 22, _T("隶书"));
		outtextxy(14, 200, _T("我看你的小脑袋瓜是昏了头了"));
		break;
	}
}

void game(int speed);

int menu(link head,link end,int speed)
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.x > 15 && m.x < 185 && m.y>395 && m.y < 445)
		{
			settextcolor(RED);
			settextstyle(40, 20, _T("隶书"));
			outtextxy(20, 400, _T("我要退出"));
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;
			}
		}
		 else if (m.x > 415 && m.x < 585 && m.y>395 && m.y < 445)
		{
			settextcolor(RED);
			settextstyle(40, 20, _T("隶书"));
			outtextxy(420, 400, _T("再来一局"));
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				link p, q;
				p = head->next;
				q = p->next;
				while (p != end)
				{
					free(p);//释放节点
					p = q;
					q = q->next;
				}
				p = NULL;//置空指针，防止野指针
				q = NULL;
				cleardevice();
				closegraph();
				key_tmp = 0;//重置游戏数据
				key = 'd';//
				scord_1 = '0';
				scord_2 = '0';
				scord_3 = '0';
				game(speed);
			}
		}
		 else
		 {
			 settextcolor(WHITE);
			 setlinecolor(WHITE);
			 settextstyle(40, 20, _T("隶书"));
			 outtextxy(20, 400, _T("我要退出"));
			 outtextxy(420, 400, _T("再来一局"));
			 rectangle(15, 395, 185, 445);
			 rectangle(415, 395, 585, 445);
		 }
	}
	closegraph();
}

void game(int speed)
{
	srand((unsigned int)time(NULL));//随机种子（时间）
	initgraph(600,600);//创建窗口
	setbkcolor(RGB(177,255,212));//背景色
	cleardevice();
	creat_snake_list();
	creat_snake_head(head, end); 
	for (int i = 0; i < foodnum; i++)
	{
		creat_food(head, end, i);
	}
	gaming_menu();
	draw_snake_body(head,end);
	while (1)
	{
		for (int i = 0; i < foodnum; i++)
		{
			draw_food(food[i]);
		}
		Sleep(speed);
		hide_snake_body(head,end);
		if (_kbhit())//如果键盘被敲击
			key_tmp = _getch();//获取敲击的键值
		check_key(key_tmp);//检查按键（用于判定筛出不确定情况）
		snake_move(head, end);
		if (check_SnakeAndWall(head, end) == 1)
		{
			draw_snake_body(head, end);
			fail_reason_wall();
			if (menu(head, end, speed) == 0)
				break;
		}
		if (check_SnakeAndBody(head, end) == 1)
		{
			draw_snake_body(head, end);
			fail_reason_body();
			if (menu(head, end, speed) == 0)
				break;
		}
		if (check_SnakeAndFood(food, head, end) == 1)
			SnakeAdd(head, end,size);
		gaming_menu();
		draw_snake_body(head, end);
	}
}