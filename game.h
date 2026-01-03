#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化棋盘
void infor_board(char board[ROW][COL], int row, int col);
//打印棋盘
void display_board(char board[ROW][COL], int row, int col);
//玩家输入
void playermove(char board[ROW][COL], int row, int col);
//电脑输入
void cputmove(char board[ROW][COL], int row, int col);
//判断输赢
char Iswin(char board[ROW][COL], int row, int col);
// 新增辅助函数：检查是否有一步获胜/堵截的点位，返回1表示找到，0表示未找到
// 参数说明：board-棋盘，row/col-尺寸，target-要检查的棋子（电脑#/玩家*），x/y-输出找到的落子坐标
int check_win_pos(char board[ROW][COL], int row, int col, char target, int* x, int* y);
