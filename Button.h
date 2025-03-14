#pragma once

/**
 * @file Button.h
 * @brief �û�ͨ������밴ť������ʵ�����̿���
 * 
 * ����EasyX����Ϣ����Ϊ��ťʵ����Ӧ����������
 * ���е�ʵ��ֱ��д�����ͷ�ļ��У�����Ҫ��Դ�ļ�
 * 
 * @author ���Ʒ�
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
    COLORREF m_changeColor;  //�ı���ɫ
    COLORREF m_currentColor; //��ǰ��ɫ


public:

    Button(int x, int y, int width, int height, const std::string& text) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_text(text),
        m_oldColor(LIGHTGRAY), m_changeColor(LIGHTGRAY), m_currentColor(LIGHTGRAY) {
    }


    //����
    void drawButton() const
    {
        setfillcolor(m_currentColor);       //��ǰ��ɫ
        fillrectangle(m_x, m_y, m_x + m_width, m_y + m_height);  //���ƾ��ΰ���

        setlinecolor(BLACK);  //���ñ߿��ɫ

        //�ı�
        settextcolor(BLACK);  //�����ı���ɫ
        settextstyle(20, 0, "����");  //�߶ȣ�����Ӧ��ȣ�����
        setbkmode(TRANSPARENT);        // �ؼ��������ı�����͸��
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


    //������ɫ
    void setColor(COLORREF changeColor)
    {
        m_oldColor = m_currentColor;  //���浱ǰ��ɫ
        m_changeColor = changeColor;  //�ı���ɫ
        m_currentColor = m_changeColor; //���µ�ǰ��ɫ
    }


    //�ָ���һ����ɫ
    void removeColor()
    {
        m_currentColor = m_oldColor;
    }
};