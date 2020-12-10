#include"game.h"

//空地           '  '  0
//人物           '♀'  1
//箱子           '□'  2
//墙壁           '■'  3
//终点           '☆'  4
//人物站在终点   '♂'  5
//箱子放在终点   '★'  6
//

void displaymap(char(*pmap)[COL])
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			switch (*(*(pmap + i) + j))
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("♀");
				break;
			case 2:
				printf("□");
				break;
			case 3:
				printf("■");
				break;
			case 4:
				printf("☆");
				break;
			case 5:
				printf("♂");
				break;
			case 6:
				printf("★");
				break;
			}
		}
		printf("\n");
	}
}

void findman(char(*pmap)[COL])
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COL; j++)
		{
			if (*(*(pmap + i) + j) == 1)
			{
				x = i;
				y = j;
				//printf("%d,%d ",x,y);
			}
			else if (*(*(pmap + i) + j) == 5)
			{
				x = i;
				y = j;
			}
		}
	}
	move(pmap,x,y);
}

void movedirection(char(*ppmap)[COL], int cx1, int cx2, int cx3, int cy1, int cy2, int cy3)
{
	if ((*(*(ppmap+cx1)+cy1))==1)
	{
		if (*(*(ppmap + cx2) + cy2) == 0)
		//if (map[x - 1][y] == 0)
		{
			*(*(ppmap + cx2) + cy2) = 1;//♀“  ”→“  ”♀
			*(*(ppmap + cx1) + cy1) = 0;
		}
		else if (*(*(ppmap + cx2) + cy2) == 4)
		{
			*(*(ppmap + cx2) + cy2) = 5;//♀☆→“  ”♂
			*(*(ppmap + cx1) + cy1) = 0;
		}
		else if (*(*(ppmap + cx3) + cy3) == 0)
		//else if (map[x - 2][y] == 0)
		{
			if (*(*(ppmap + cx2) + cy2) == 2)
			{
				*(*(ppmap + cx3) + cy3) = 2;
				*(*(ppmap + cx2) + cy2) = 1;
				*(*(ppmap + cx1) + cy1) = 0;
			}
			else if (*(*(ppmap + cx2) + cy2) == 6)
			{
				*(*(ppmap + cx3) + cy3) = 2;
				*(*(ppmap + cx2) + cy2) = 5;
				*(*(ppmap + cx1) + cy1) = 0;
			}
		}
		else if (*(*(ppmap + cx3) + cy3) == 4)
		{
			if (*(*(ppmap + cx2) + cy2) == 2)
			{
				*(*(ppmap + cx3) + cy3) = 6;
				*(*(ppmap + cx2) + cy2) = 1;
				*(*(ppmap + cx1) + cy1) = 0;
			}
			else if (*(*(ppmap + cx2) + cy2) == 6)
			{
				*(*(ppmap + cx3) + cy3) = 6;
				*(*(ppmap + cx2) + cy2) = 5;
				*(*(ppmap + cx1) + cy1) = 0;
			}
		}
	}
	else if (*(*(ppmap + cx1) + cy1) == 5)
	{
		if (*(*(ppmap + cx2) + cy2) == 0)
		{
			*(*(ppmap + cx2) + cy2) = 1;//♂“  ”→☆♀
			*(*(ppmap + cx1) + cy1) = 4;
		}
		else if (*(*(ppmap + cx2) + cy2) == 4)
		{
			*(*(ppmap + cx2) + cy2) = 5;//♂☆→☆♂
			*(*(ppmap + cx1) + cy1) = 4;
		}
		else if (*(*(ppmap + cx3) + cy3) == 0)
		{
			if (*(*(ppmap + cx2) + cy2) == 2)
			{
				*(*(ppmap + cx3) + cy3) = 2;
				*(*(ppmap + cx2) + cy2) = 1;
				*(*(ppmap + cx1) + cy1) = 4;
			}
			else if (*(*(ppmap + cx2) + cy2) == 6)
			{
				*(*(ppmap + cx3) + cy3) = 2;
				*(*(ppmap + cx2) + cy2) = 5;
				*(*(ppmap + cx1) + cy1) = 4;
			}
		}
		else if (*(*(ppmap + cx3) + cy3) == 4)
		{
			if (*(*(ppmap + cx2) + cy2) == 2)
			{
				*(*(ppmap + cx3) + cy3) = 6;
				*(*(ppmap + cx2) + cy2) = 1;
				*(*(ppmap + cx1) + cy1) = 4;
			}
			else if (*(*(ppmap + cx2) + cy2) == 6)
			{
				*(*(ppmap + cx3) + cy3) = 6;
				*(*(ppmap + cx2) + cy2) = 5;
				*(*(ppmap + cx1) + cy1) = 4;
			}
		}
	}
}

void move(char(*ppmap)[COL], int x, int y)
{
	char input = getch();
	int changex1;
	int changex2;
	int changex3; 
	int changey1;
	int changey2;
	int changey3;
	switch (input)
	{
	case 'W':
	case 'w':
		changex1 = x;
		changex2 = x - 1;
		changex3 = x - 2;
		changey1 = y;
		changey2 = y;
		changey3 = y;
		(*movedirection)(ppmap, changex1, changex2, changex3, changey1, changey2, changey3);
		break;
	case 'S':
	case 's':
		changex1 = x;
		changex2 = x + 1;
		changex3 = x + 2;
		changey1 = y;
		changey2 = y;
		changey3 = y;
		(*movedirection)(ppmap, changex1, changex2, changex3, changey1, changey2, changey3);
		break;
	case 'A':
	case 'a':
		changex1 = x;
		changex2 = x;
		changex3 = x;
		changey1 = y;
		changey2 = y - 1;
		changey3 = y - 2;
		(*movedirection)(ppmap, changex1, changex2, changex3, changey1, changey2, changey3);
		break;
	case 'D':
	case 'd':
		changex1 = x;
		changex2 = x;
		changex3 = x;
		changey1 = y;
		changey2 = y + 1;
		changey3 = y + 2;
		(*movedirection)(ppmap, changex1, changex2, changex3, changey1, changey2, changey3);
		break;
	case 'R':
	case 'r':
		main();
		break;
	}
}

int countend_box(char(*pmap)[COL], int count)
{
	count = 6;
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL;j++)
		{
			if ((*(*(pmap + i) + j)) == 6)
				count--;
		}
	}
	return count;
}





