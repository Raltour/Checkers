#include "TextBox.h"

TextBox::TextBox(int x, int y, int width, int height, int maxWord)
    : x(x), y(y), width(width), height(height), maxWord(maxWord), isSelected(false), showCursor(false), cursorPos(0)
{
}

const std::string& TextBox::getText() const
{
    return text;
}



bool TextBox::isEmpty() const
{
    return text.empty();
}

void TextBox::setText(const std::string& newText)
{
    text = newText;
    cursorPos = text.length();
}

void TextBox::draw()
{
    setfillcolor(WHITE);
    setlinecolor(RGB(122, 122, 122));
    fillrectangle(x, y, x + width, y + height);

    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(height * 3 / 4, 0, ("����"));

    outtextxy(x + 5, y + (height - textheight(("����"))) / 2, text.c_str());

    setlinecolor(BLACK);
    if (isSelected && showCursor)
    {
        int cursorX = x + 5 + textwidth(text.substr(0, cursorPos).c_str());
        line(cursorX, y + 2 + height / 8, cursorX, y + height * 7 / 8 - 2);
    }
}


bool TextBox::checkClick(int mouseX, int mouseY)
{
    if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
    {
        isSelected = true;
        return true;
    }
    else
    {
        isSelected = false;
        cursorPos = text.length();
        return false;
    }
}

void TextBox::keyInput(wchar_t  ch)
{

    if (isSelected)
    {
        switch (ch)
        {

        case VK_BACK:				// �û����˸����ɾ��һ���ַ�
            if (!text.empty() && cursorPos > 0)
            {
                text.erase(cursorPos - 1, 1);
                cursorPos--;
            }
            break;
        case VK_RETURN:
            cursorPos = text.length();
            isSelected = false;
            break;
        default:				// �û����������������ı�����
            if (text.length() < maxWord)
            {
                text.insert(cursorPos, 1, ch);
                cursorPos++;
            }
        }
    }
}
void TextBox::updateCursor()
{
    static DWORD lastTick = GetTickCount();
    DWORD currentTick = GetTickCount();
    if (currentTick - lastTick >= 500) // ÿ500�����л����״̬
    {
        showCursor = !showCursor;
        lastTick = currentTick;
    }
}
