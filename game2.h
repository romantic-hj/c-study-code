#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define EASY 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化数组
void init_board(char ch[ROWS][COLS], int rows, int cols, char target);
//打印数组
void display_board(char ch[ROWS][COLS], int row, int col);
//设置雷
void set_mine(char ch[ROWS][COLS], int row, int col);
//排雷函数
void play_game(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//数出坐标周围的雷
int get_mine(char show[ROWS][COLS], int x, int y);
//展开函数
void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
//判断输赢（1为赢，0为输）
int judge(char show[ROWS][COLS], int row, int col);