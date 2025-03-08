#pragma once

/**
 * @file Render.h
 * @brief 绘制游戏中的各种图形
 * @author 张三
 * @version 1.3
 */

#include <easyx.h>

 /*
     功能: 绘制六边形网格
     参数: 无参数
     返回值：无返回值
 */
void drawHexagonGrid();

/*
    功能: 绘制棋子
    参数: 无参数
    返回值：无返回值
*/
void drawChesses();

/*
    功能: 绘制棋盘网格和棋子,调用网格和棋子绘制函数
    参数: 无参数
    返回值：无返回值
*/
void draw();