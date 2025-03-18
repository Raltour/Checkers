#pragma once

/**
 * @file Render.h
 * @brief 绘制游戏中的各种图形，以及easyx图形库中的消息传递功能
 *
 * 包括用来与玩家交互的按钮，
 * 以及所有游戏状态下的render函数，也在这里实现
 * 这个文件不要包含具体实现，都写在.cpp文件里
 *
 * 每一个绘制界面的函数要包括背景、所有元素
 * （包括但不限于棋子、按钮、各种信息）
 * 所有绘制（即游戏刷新新的一帧）都封装在各个界面的draw***函数中
 *
 * @author 吕建豪 李沐恒
 */

#include <easyx.h>
#include "Button.h"

class Board;

 /**
  * @brief 绘制棋子
  *
  * 该函数负责在屏幕上绘制棋子。棋子的颜色、位置和状态由外部逻辑控制。
  * 该函数通常由游戏主循环调用，以确保棋子能够正确显示在棋盘上。
  *
  * @author 作者名字
  */
void drawChess(int x, int y, COLORREF color);


/**
 * @brief 绘制六边形网格
 *
 * 该函数负责绘制六边形的棋盘网格。六边形网格是游戏棋盘的基础结构，
 * 棋子将放置在六边形的顶点或中心位置。
 *
 * @author 作者名字
 */
void drawHexagonGrid(Board& b);


/**
 * @brief 绘制三角形
 *
 * 该函数负责绘制三角形，并根据参数决定三角形的方向（正三角或倒三角）。
 * 同时，该函数会调用 `addChess` 函数在三角形的顶点位置添加棋子。
 * 每个顶点的状态由 `state` 参数决定，例如空顶点设置为 0。
 * 根据不同的颜色设置不同的状态，`pos` 记录所有棋子的坐标。
 *
 * @param p_x 三角形的起始 x 坐标
 * @param p_y 三角形的起始 y 坐标
 * @param c 三角形的方向，'u' 表示正三角，'d' 表示倒三角
 * @param n 三角形的层数
 * @param color 三角形的颜色
 * @author 作者名字
 */
//void drawTriangle(Board& b, int p_x, int p_y, const char c, int n, COLORREF color);
void drawTriangle(Board& b);

/**
 * @brief 绘制开始菜单
 *
 * 该函数负责绘制游戏的开始菜单界面。开始菜单通常包括游戏标题、开始按钮、
 * 设置按钮和退出按钮等元素。
 *
 * @author 吕建豪 杜云飞
 */
void drawStartMenu();


/**
 * @brief 绘制玩家数量选择界面
 *
 * 该函数负责绘制玩家数量选择界面。玩家可以在此界面中选择游戏的玩家数量，
 * 双人模式、四人模式、六人模式
 *
 * @author 李沐恒
 */
void drawPlayerNum();


/**
 * @brief 绘制玩家信息界面
 *
 * 该函数负责绘制玩家信息界面。
 * 该界面要求玩家输入昵称
 *
 * @author 李沐恒
 */
void drawPlayerInfo();


/**
 * @brief 绘制棋盘和棋子
 *
 * 该函数负责绘制完整的棋盘和棋子。棋盘由 4 个 4 层的三角形组成外围，
 * 上下分别由 9 层的正三角和 8 层的倒三角组成。该函数会调用 6 次 `drawTriangle` 函数
 * 来完成棋盘的绘制。
 *
 * @author 作者名字
 */
void drawChechersGame(Board& board);


/**
 * @brief 绘制胜利界面
 *
 * 该函数负责绘制胜利界面。当游戏结束时，根据胜利的玩家显示相应的胜利信息。
 *
 * @author 作者名字
 */
void drawWinView();


/**
 * @brief 加载背景图片
 *
 * 该函数负责加载并显示背景图片。背景图片通常由界面的打印函数调用，
 * 加载完成后会先输出图片，随后打印界面中的其他元素，以避免覆盖。
 *
 * @param filename 背景图片的文件路径
 * @author 作者名字
 */
void loadBackGroundImage(std::string filename);


// 这里根据实际需求存储多张图片的地址
