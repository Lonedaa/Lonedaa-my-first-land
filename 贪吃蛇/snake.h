#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

//�ߵ��ƶ��ٶ�
#define SPEED_1 250
#define SPEED_2 150
#define SPEED_3 50

//���ʹ���
typedef struct SNAKE
{
	int xx;//x����
	int yy;//y����
	struct SNAKE *last;//ͷָ��
	struct SNAKE *next;//βָ��
}snake, *link;

typedef struct FOOD
{
	int xx;
	int yy;
}FOOD;
//ö�ٽ�����
enum FAILREASON
{
	SENT1,
	SENT2,
	SENT3,
	SENT4,
};

//��������
void creat_snake_list();
void creat_snake_head(link head, link end);
void draw_snake_body(link head, link end);
void hide_snake_body(link head, link end);
void snake_move(link head, link end);
void check_key(char key_t);
int check_SnakeAndWall(link head, link end);
int check_SnakeAndBody(link head, link end);
void creat_food(link head, link end);
void draw_food(struct FOOD food);
int check_SnakeAndFood(FOOD food, link head, link end);
void SnakeAdd(FOOD food, link head, link end);