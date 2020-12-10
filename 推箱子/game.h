#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_WARNINGS 1
#define ROW 14
#define COL 12

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

void displaymap(char(*pmap)[COL]);
void findman(char(*pmap)[COL]);
void move(char(*ppmap)[COL], int x, int y);
void movedirection(char(*ppmap)[COL], int cx1, int cx2, int cx3, int cy1, int cy2, int cy3);
int countend_box(char(*pmap)[COL], int count);

