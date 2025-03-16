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
    int maxWord;    //最长单词个数
    std::string text;   //文本

    bool showCursor;    //是否显示光标
    int cursorPos;      //光标位置

public:

    TextBox(int x, int y, int width, int height, int maxWord);

    // 禁用默认构造函数
    TextBox() = delete;


    bool isSelected;    //是否被选中
    const std::string& getText() const;


    bool isEmpty() const;


    void setText(const std::string& newText);

    void draw();

    bool checkClick(int mouseX, int mouseY);

    void keyInput(wchar_t  ch);

    void updateCursor();
};


