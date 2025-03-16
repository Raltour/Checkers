#pragma once
#include <easyx.h>
#include <iostream>
class TextBox
{
private:
    int x;
    int y;
    int width;
    int height;
    int maxWord;    //����ʸ���
    std::string text;   //�ı�

    bool showCursor;    //�Ƿ���ʾ���
    int cursorPos;      //���λ��

public:

    TextBox(int x, int y, int width, int height, int maxWord);

    // ����Ĭ�Ϲ��캯��
    TextBox() = delete;


    bool isSelected;    //�Ƿ�ѡ��
    const std::string& getText() const;


    bool isEmpty() const;


    void setText(const std::string& newText);

    void draw();

    bool checkClick(int mouseX, int mouseY);

    void keyInput(wchar_t  ch);

    void updateCursor();
};


