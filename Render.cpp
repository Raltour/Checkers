/**
 * @file Render.cpp
 * @brief 绘图函数的具体实现
 * 
 * @author 
 * @version 2.4
 */

#include <easyx.h>
#include <string>
#include "Render.h"


  /**
   * @brief 绘制棋子
   *
   * 详细描述函数的功能、参数、返回值等信息。
   *
   * @param 参数1 描述参数1的作用
   * @param 参数2 描述参数2的作用
   * @return 返回值的描述
   * @author 作者名字
   */
void drawChess(){}


/**
 * @brief 绘制六边形网格
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @author 作者名字
 */
void drawHexagonGrid(){}


/*
	负责人:
	功能: 绘制三角形，
	同时使用addChess添加棋子，
	state 记录顶点的状态  例如空设置0
		  根据不同的颜色设置不同的状态
	pos记录所有棋子的坐标



	参数: p_x,p_y 为起始坐标   n 表示画几层  c 表示三角形是正的还是倒的
	color颜色
	返回值：无返回值
*/
void drawTriangle(int p_x, int p_y, const char c, int n, COLORREF color){}


/*
 * @brief 绘制开始菜单
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @author 作者名字
 */
void drawStartMenu(){}


/**
 * @brief
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawPlayerNum(){}


/**
 * @brief
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawPlayerInfo(){}


/**
 * @brief
 *
 * 	绘制棋盘和棋子,可是使用4个4层的三角形组成外围，
 * 上下由9层的正三角，8层的倒三角组成，坐标已给出
 * 调用6个drawTriangle 函数
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawChechersGame(){}


/**
 * @brief
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawWinView(){}


/**
* @brief 加载背景图片
*
* 由界面的打印函数调用，加载给定的背景图片
* 先输出图片，随后打印界面中其他东西
* 否则会覆盖
*
* @param 图片的地址
* @return 返回值的描述
* @author 作者名字
*/
void loadBackGroundImage(std::string filename){}

