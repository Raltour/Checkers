/**
 * @file PlayerInfo.cpp
 * @brief PlayerInfo函数的实现
 * @author 
 * @version 2.5.6
 */

#include "PlayerInfo.h"


//储存玩家数量，在PlayerNum和PlayerInfo之间共享
extern int _num_of_players;


bool PlayerInfo::isInit = false;

PlayerInfo::PlayerInfo(StateMachine& _self_ref)
    :GameState(_self_ref) {
    b.clear();
}

void PlayerInfo::update(ExMessage& msg) {

    switch (msg.message)
    {
    case WM_LBUTTONDOWN:
    {
        int x = msg.x, y = msg.y;
        // 检查是否点击按钮
        if (btnSubmit.isClicked(msg))
        {
            btnSubmit.setColor(RED); // 按钮点击效果
            btnSubmit.drawButton();

            names.clear();
            colors.clear();

            // 获取输入内容
            for (auto& name : b)
                names.push_back(name.getText());

            if (_num_of_players == 2)
            {
                colors.push_back(RED);
                colors.push_back(GREEN);
            }
            else if (_num_of_players == 4)
            {
                colors.push_back(RED);
                colors.push_back(GREEN);
                colors.push_back(BLUE);
                colors.push_back(YELLOW);
            }
            else if (_num_of_players == 6)
            {
                colors.push_back(RED);
                colors.push_back(GREEN);
                colors.push_back(BLUE);
                colors.push_back(YELLOW);
                colors.push_back(CYAN);
                colors.push_back(MAGENTA);
            }

            for (int i = 0; i < _num_of_players; i++)
                Player::addNewPlayer(colors[i], names[i]);
            btnSubmit.removeColor();
            btnSubmit.drawButton();
        }
        // 检查输入框点击
        bool selected = false;
        for (auto& p : b)
        {
            if (p.checkClick(x, y))
            {
                selected = true;
                p.isSelected = true;
            }
        }

        // 如果未点击任何输入框，取消所有选中状态
        if (!selected) {
            for (auto& p : b)
                p.isSelected = false;
        }
        break;
    }
    case WM_KEYDOWN:
    {

        wchar_t ch = msg.vkcode;

        // 获取当前选中的输入框
        TextBox* activeTB = nullptr;

        for (auto& s : b)
            if (s.isSelected) {
                activeTB = &s;

                if (activeTB) {
                    activeTB->keyInput(ch); // 处理键盘输入
                }
                break;
            }
    }
    }

    // 绘制所有控件
    cleardevice();
    for (auto& p : b)
        p.draw();

    btnSubmit.drawButton();

    // 更新光标显示
    for (auto& p : b)
        if (p.isSelected)
            p.updateCursor();


    Sleep(10);

}


void PlayerInfo::render() {
    drawPlayerInfo();
    settextcolor(BLACK);


    //保证只初始化一次

    if (!isInit)
    {
        std::cout << "Creating " << _num_of_players << " TextBox objects." << std::endl;
        for (int i = 0; i < _num_of_players; i++)
        {
            std::cout << "Creating TextBox at index " << i << std::endl;
            b.emplace_back(TextBox(700, 50 + i * 150, 200, 50, 10));
        }
        btnSubmit = Button(1000, 350, 100, 30, "确认");
        isInit = true;
    }

    if (_num_of_players == 2)
    {
        outtextxy(600, 50, ("玩家1:"));
        outtextxy(600, 200, ("玩家2:"));
    }
    else if (_num_of_players == 4)
    {
        outtextxy(600, 50, ("玩家1:"));
        outtextxy(600, 200, ("玩家2:"));
        outtextxy(600, 350, ("玩家3:"));
        outtextxy(600, 500, ("玩家4:"));
    }

    else if (_num_of_players == 6)
    {
        outtextxy(600, 50, ("玩家1:"));
        outtextxy(600, 200, ("玩家2:"));
        outtextxy(600, 350, ("玩家3:"));
        outtextxy(600, 500, ("玩家4:"));
        outtextxy(600, 650, ("玩家5:"));
        outtextxy(600, 800, ("玩家6:"));
    }

    for (int i = 0; i < _num_of_players; i++)
        b[i].draw();

    btnSubmit.drawButton();
}


void PlayerInfo::enter() {
    render();
}

PlayerInfo::~PlayerInfo()
{
    b.clear();
}

