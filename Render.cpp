/**
 * @file Render.cpp
 * @brief 绘图函数的具体实现
 * 
 * @author 
 * @version 2.5.7
 */

#include <string>
#include "Render.h"
#include "Board.h"

extern int _num_of_players;

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
void drawChess(int x, int y, COLORREF color)
{
    setfillcolor(color);
    fillcircle(x, y, 12);
}


/**
 * @brief 绘制六边形网格
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @author 作者名字
 */
void drawHexagonGrid(Board& b)
{
    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = b.OFFSET_X + (j - i / 2.0) * b.m_cellSize;
            int y = b.top_y + i * b.m_cellSize;

            b.addChess(Chess::createChess(x, y, WHITE));
            drawChess(x, y, WHITE);
        }
    }

    for (int i = 4; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = b.OFFSET_X + (j - i / 2.0) * b.m_cellSize;
            int y = b.OFFSET_Y - i * b.m_cellSize;

            b.addChess(Chess::createChess(x, y, WHITE));
            drawChess(x, y, WHITE);
        }
    }
}


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
void drawTriangle(Board& b, int p_x, int p_y, const char c, int n, COLORREF color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = p_x + (j - i / 2.0) * b.m_cellSize;
            int y = ((c == '+') ? (p_y + i * b.m_cellSize) : (p_y - i * b.m_cellSize));

            b.addChess(Chess::createChess(x, y, color));
            drawChess(x, y, color);
        }
    }
}


void drawStartMenu() {
    // 加载图片
    IMAGE img;
    loadimage(&img, "p1.jpg", 1600, 900);  // 加载图片，路径为 "p1.jpg"
    putimage(0, 0, &img);  // 将图片绘制到窗口的 (0, 0) 位置


    IMAGE image;
    loadimage(&image, "p2.jpg", 200, 100);
    putimage(700, 100, &image);


}


void drawPlayerNum() {
    setbkcolor(RGB(173, 216, 230));

    cleardevice();

}


void drawPlayerInfo() {
    setbkcolor(RGB(173, 216, 230));
    cleardevice();


}


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
void drawChechersGame(Board& b)
{
    setbkcolor(RGB(173, 216, 230));
    cleardevice();

    drawHexagonGrid(b);

    if (_num_of_players == 2)
    {
        //上
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //下
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);
    }


    else if (_num_of_players == 4)
    {
        //上
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //下
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);

        //左上
        drawTriangle(b, b.lt_x, b.lt_y, '-', 4, BLUE);

        //右下
        drawTriangle(b, b.rd_x, b.rd_y, '+', 4, YELLOW);
    }
    else if (_num_of_players == 6)
    {
        //上
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //下
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);

        //左上
        drawTriangle(b, b.lt_x, b.lt_y, '-', 4, BLUE);

        //右下
        drawTriangle(b, b.rd_x, b.rd_y, '+', 4, YELLOW);

        //左下
        drawTriangle(b, b.ld_x, b.ld_y, '+', 4, YELLOW);

        //右上
        drawTriangle(b, b.rt_x, b.rt_y, '-', 4, BLUE);


    }


}


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

