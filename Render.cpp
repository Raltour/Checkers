/**
 * @file Render.cpp
 * @brief 绘图函数的具体实现
 * 
 * @author 
 * @version 2.5.2
 */

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

    int btnWidth = 400;
    int btnHeight = 100;
    int centerX = 1500 / 2 - btnWidth / 2;

    Button btn2(centerX, 250, btnWidth, btnHeight, "双人模式");
    Button btn4(centerX, 400, btnWidth, btnHeight, "4人模式");
    Button btn6(centerX, 550, btnWidth, btnHeight, "6人模式");

    settextcolor(WHITE);
    settextstyle(90, 0, "宋体");
    outtextxy((1500 - textwidth("模式选择")) / 2, 100, "模式选择");

    btn2.drawButton();
    btn4.drawButton();
    btn6.drawButton();

}


// 绘制欢迎界面并添加动画效果
void drawWelcomeInterface(const TCHAR* id) {
    // 设置背景颜色为浅蓝色
    setbkcolor(RGB(173, 216, 230));
    cleardevice();
    // 设置文字颜色为黑色
    settextcolor(BLACK);
    // 增大字体大小
    settextstyle(70, 0, _T("宋体"));
    TCHAR message[50];
    _stprintf_s(message, _T("欢迎，%s！成功登录跳棋游戏！"), id);
    int len = _tcslen(message);
    TCHAR temp[50] = { 0 };
    for (int i = 0; i <= len; i++) {
        _tcsncpy_s(temp, message, i);
        temp[i] = '\0';
        setbkcolor(RGB(173, 216, 230));
        cleardevice();
        int textWidth = textwidth(temp);
        int textHeight = textheight(temp);
        int x = (1600 - textWidth) / 2;
        int y = (900 - textHeight) / 2;

        outtextxy(x, y, temp);
        Sleep(100); // 控制动画速度
    }
}
// 绘制登录界面
void drawLoginInterface() {
    // 设置背景颜色为浅蓝色
    setbkcolor(RGB(173, 216, 230));
    cleardevice();
    // 设置文字颜色为黑色
    settextcolor(BLACK);
    // 增大字体大小
    settextstyle(60, 0, _T("宋体"));
    // 获取文字宽度和高度
    int textWidth = textwidth(_T("请输入游戏 ID（用英文）:"));
    int textHeight = textheight(_T("请输入游戏 ID（用英文）:"));
    int x = (1500 - textWidth) / 2;
    int y = (1000 - textHeight) / 2 - 100;
    outtextxy(x, y, _T("请输入游戏 ID（用英文）:"));
}
void drawPlayerInfo() {
    // 初始化图形窗口，大小为 1600x900
    initgraph(1600, 900);
    // 绘制登录界面
    drawLoginInterface();

    // 绘制欢迎界面并添加动画效果
    //drawWelcomeInterface(id);

    // 关闭图形窗口
    closegraph();
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

