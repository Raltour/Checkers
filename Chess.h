#pragma once

/**
 * @file Chess.h
 * @brief 棋盘中的棋子
 * @author 杜云飞
 * @version 2.5
 */

#include <string>
#include "Render.h"
#include <memory>


enum chessState { NORMAL, SELECTED };
class Chess
{
public:

    /*
        负责人: 
        功能: 创建一个单独对象实例，
        避免内存泄漏。

        参数: 坐标 x,y
              颜色 color
        返回值：返回一个指向棋子类独占所有权的智能指针，自动管理
    */
    static Chess* createChess(int x, int y, COLORREF);


    /*
        负责人: 
        功能: 获取棋子的x坐标，
            const表示常函数
        参数:  无
        返回值：无
    */
    int x() const;


    /*
        负责人: 
        功能: 获取棋子的y坐标，
            const表示常函数
        参数:  无
        返回值：无
    */
    int y() const;


    /*
        负责人: 
        功能: 获取棋子颜色，
            const表示常函数
        参数:  无
        返回值：无
    */
    COLORREF color() const;


    /*
        负责人: 
        功能: 获取棋子状态，
            const表示常函数
        参数:  无
        返回值：无
    */
    chessState state() const;


    /*
        负责人: 
        功能: 设置棋子的位置
            直接访问私有成员修改
        参数: 位置坐标x，y
        返回值：无
    */
    void setPosition(int x, int y);


    /*
        负责人: 
        功能: 设置棋子的状态
             传入状态修改
        参数: 棋子的状态
        返回值：无
    */
    void setState(chessState state);


    /*
        负责人: 
        功能: 改变棋子的颜色
        传入颜色修改，当时首先记录原来颜色，便于还原
        参数: 颜色
        返回值：无
    */
    void changeChess(COLORREF color);


    /*
        负责人: 
        功能: 调用函数的原来颜色，恢复颜色
        参数: 无
        返回值：无
    */
    void recoveryColor();

private:

    int _x, _y;//棋子的坐标
    int _chess_size = 12;//棋子半径

    COLORREF _old_color;    //原来颜色
    COLORREF _current_color;//当前颜色
    bool _is_selected;      //是否选中棋子

    /*
        禁用构造，使用智能指针管理对象
        禁止拷贝，只能移动
    */
    Chess(int x, int y, int chessSize = 10, COLORREF currentColor = WHITE);
    Chess(const Chess&) = delete;
    Chess& operator=(const Chess&) = delete;

};

