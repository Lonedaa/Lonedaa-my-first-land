#include"game.h"

void menu()
{
	printf("************************\n");
	printf("******    play    ******\n");
	printf("******    exit    ******\n");
	printf("************************\n");
}

game()
{
	int count = 0;
	int ret = 0;
	char map[ROW][COL] = {
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3 },
		{ 3, 3, 3, 0, 0, 3, 0, 0, 0, 3, 3, 3 },
		{ 3, 3, 3, 0, 0, 2, 0, 0, 3, 3, 3, 3 },
		{ 3, 3, 3, 0, 3, 3, 0, 2, 0, 0, 3, 3 },
		{ 3, 3, 3, 0, 3, 0, 2, 3, 2, 0, 3, 3 },
		{ 3, 3, 3, 0, 3, 0, 0, 2, 0, 0, 3, 3 },
		{ 3, 3, 0, 0, 3, 3, 0, 0, 0, 0, 3, 3 },
		{ 3, 3, 0, 0, 0, 3, 3, 0, 0, 0, 3, 3 },
		{ 3, 3, 0, 0, 4, 4, 3, 3, 2, 3, 3, 3 },
		{ 3, 3, 3, 4, 4, 4, 4, 3, 1, 3, 3, 3 },
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
		{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
	};
	displaymap(map);
	while (1)
	{
		findman(map);
		//move(map);
		system("CLS");
		displaymap(map);
		ret = countend_box(map, count);
		if (ret == 0)
		{
			system("CLS");
			displaymap(map);
			printf("恭喜你过关了！\n");
			break;
		}
	}
}

test()
{
	int input = 0;
	do
	{
		menu();
		printf("W(w)进入游戏	S(s)退出游戏\n");
		//printf("请选择:>");
		input = getch();
		switch (input)
		{
		case 'W':
		case 'w':
			printf("游戏开始\nW（w）向上移动\nS（s）向下移动\nA（a）向左移动\nD（d）向右移动\nR（r）重新开始\n");
			game();
			break;
		case 'S':
		case 's':
			printf("游戏结束\n");
			break;
		default:
			printf("无效输入！\n");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
