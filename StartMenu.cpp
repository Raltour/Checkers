/**
 * @file StartMenu.cpp
 * @brief StartMenu������ʵ��
 * @author 
 * @version 2.5.1
 */

#include "StateMachine.h"
#include "Render.h"

StartMenu::StartMenu(StateMachine& _self_ref)
	:GameState(_self_ref) {
    b1 = Button(750, 350, 100, 50, "��ʼ��Ϸ");
    b2 = Button(750, 450, 100, 50, "�˳���Ϸ");
}


void StartMenu::update(ExMessage& msg) {
    //�������
    if (msg.message == WM_LBUTTONDOWN)
    {
        if (b1.isClicked(msg))
        {
            b1.setColor(BLACK);
            b1.drawButton();
            Sleep(2);
            b1.removeColor();
            b1.drawButton();
            Sleep(2);

            _mach.changeStateTo("PlayerMenu");
        }
        else if (b2.isClicked(msg))
        {
            b2.setColor(BLACK);
            b2.drawButton();
            Sleep(2);
            b2.removeColor();
            b2.drawButton();
            Sleep(2);
            exit(0);
        }

    }
}


void StartMenu::render() {
    drawStartMenu();
}


void StartMenu::enter() {
    initgraph(1600, 900);
    render();
}

