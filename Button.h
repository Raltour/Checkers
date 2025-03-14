#pragma once

/**
 * @file MyClass.cpp
 * @brief 该文件实现了 MyClass 类的功能。
 * @author
 * @version 2.3
 */


#include <easyx.h>
#include <graphics.h>
#include <string>

class Button
{
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    std::string m_text;
    COLORREF m_oldColor;
    COLORREF m_changeColor;  //改变颜色
    COLORREF m_currentColor; //当前颜色
public:
    Button(int x, int y, int width, int height, const std::string& text);

    //绘制按钮
    void draw() const;

    //按钮点击（检查是否在按钮中）
    bool isClicked(int mouseX, int mouseY)const;

    //设置文本文件
    void setText(const std::string& text);

    //设置颜色
    void setColor(COLORREF changeColor);

    //恢复原色，默认颜色
    void removeColor();

};