/**
 * @file PlayerInfo.cpp
 * @brief PlayerInfo������ʵ��
 * @author 
 * @version 2.5.6
 */

#include "PlayerInfo.h"


//���������������PlayerNum��PlayerInfo֮�乲��
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
        // ����Ƿ�����ť
        if (btnSubmit.isClicked(msg))
        {
            btnSubmit.setColor(RED); // ��ť���Ч��
            btnSubmit.drawButton();

            names.clear();
            colors.clear();

            // ��ȡ��������
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
        // ����������
        bool selected = false;
        for (auto& p : b)
        {
            if (p.checkClick(x, y))
            {
                selected = true;
                p.isSelected = true;
            }
        }

        // ���δ����κ������ȡ������ѡ��״̬
        if (!selected) {
            for (auto& p : b)
                p.isSelected = false;
        }
        break;
    }
    case WM_KEYDOWN:
    {

        wchar_t ch = msg.vkcode;

        // ��ȡ��ǰѡ�е������
        TextBox* activeTB = nullptr;

        for (auto& s : b)
            if (s.isSelected) {
                activeTB = &s;

                if (activeTB) {
                    activeTB->keyInput(ch); // �����������
                }
                break;
            }
    }
    }

    // �������пؼ�
    cleardevice();
    for (auto& p : b)
        p.draw();

    btnSubmit.drawButton();

    // ���¹����ʾ
    for (auto& p : b)
        if (p.isSelected)
            p.updateCursor();


    Sleep(10);

}


void PlayerInfo::render() {
    drawPlayerInfo();
    settextcolor(BLACK);


    //��ֻ֤��ʼ��һ��

    if (!isInit)
    {
        std::cout << "Creating " << _num_of_players << " TextBox objects." << std::endl;
        for (int i = 0; i < _num_of_players; i++)
        {
            std::cout << "Creating TextBox at index " << i << std::endl;
            b.emplace_back(TextBox(700, 50 + i * 150, 200, 50, 10));
        }
        btnSubmit = Button(1000, 350, 100, 30, "ȷ��");
        isInit = true;
    }

    if (_num_of_players == 2)
    {
        outtextxy(600, 50, ("���1:"));
        outtextxy(600, 200, ("���2:"));
    }
    else if (_num_of_players == 4)
    {
        outtextxy(600, 50, ("���1:"));
        outtextxy(600, 200, ("���2:"));
        outtextxy(600, 350, ("���3:"));
        outtextxy(600, 500, ("���4:"));
    }

    else if (_num_of_players == 6)
    {
        outtextxy(600, 50, ("���1:"));
        outtextxy(600, 200, ("���2:"));
        outtextxy(600, 350, ("���3:"));
        outtextxy(600, 500, ("���4:"));
        outtextxy(600, 650, ("���5:"));
        outtextxy(600, 800, ("���6:"));
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

