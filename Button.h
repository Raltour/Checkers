#pragma once

/**
 * @file MyClass.cpp
 * @brief ���ļ�ʵ���� MyClass ��Ĺ��ܡ�
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
    COLORREF m_changeColor;  //�ı���ɫ
    COLORREF m_currentColor; //��ǰ��ɫ
public:
    Button(int x, int y, int width, int height, const std::string& text);

    //���ư�ť
    void draw() const;

    //��ť���������Ƿ��ڰ�ť�У�
    bool isClicked(int mouseX, int mouseY)const;

    //�����ı��ļ�
    void setText(const std::string& text);

    //������ɫ
    void setColor(COLORREF changeColor);

    //�ָ�ԭɫ��Ĭ����ɫ
    void removeColor();

};