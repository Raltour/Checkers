#pragma once

/**
 * @file Button.h
 * @brief 用户通过鼠标与按钮交互，实现流程控制
 * 
 * 利用EasyX的消息功能为按钮实现相应交互的能力
 * 所有的实现直接写在这个头文件中，不需要另开源文件
 * 
 * @author 杜云飞
 * @version 2.4
 */


#include <easyx.h>
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

    Button(int x, int y, int width, int height, const std::string& text) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_text(text),
        m_oldColor(LIGHTGRAY), m_changeColor(LIGHTGRAY), m_currentColor(LIGHTGRAY) {
    }


    //绘制
    void drawButton() const
    {
        setfillcolor(m_currentColor);       //当前颜色
        fillrectangle(m_x, m_y, m_x + m_width, m_y + m_height);  //绘制矩形按键

        setlinecolor(BLACK);  //设置边框黑色

        //文本
        settextcolor(BLACK);  //设置文本颜色
        settextstyle(20, 0, "宋体");  //高度，自适应宽度，字体
        setbkmode(TRANSPARENT);        // 关键：设置文本背景透明
        outtextxy(m_x + (m_width - textwidth(m_text.c_str())) / 2,
            m_y + (m_height - textheight(m_text.c_str())) / 2, m_text.c_str());
    }


    bool isClicked(int mouseX, int mouseY)const
    {
        if (mouseX >= m_x && mouseX <= m_x + m_width
            && mouseY >= m_y && mouseY <= m_y + m_height)
            return true;
        return false;
    }


    void setText(const std::string& text)
    {
        this->m_text = text;
    }


    //设置颜色
    void setColor(COLORREF changeColor)
    {
        m_oldColor = m_currentColor;  //保存当前颜色
        m_changeColor = changeColor;  //改变颜色
        m_currentColor = m_changeColor; //更新当前颜色
    }


    //恢复上一个颜色
    void removeColor()
    {
        m_currentColor = m_oldColor;
    }
};