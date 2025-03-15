/**
 * @file StartMenu.cpp
 * @brief StartMenu函数的实现
 * @author 
 * @version 2.5.4
 */

#include "StateMachine.h"
#include "Render.h"

StartMenu::StartMenu(StateMachine& _self_ref)
	:GameState(_self_ref) {
    b1 = Button(750, 350, 100, 50, "开始游戏");
    b2 = Button(750, 450, 100, 50, "退出游戏");
}


void StartMenu::update(ExMessage& msg) {

    if (b1.isClicked(msg))
    {
        b1.setColor(BLACK);
        b1.drawButton();
        FlushBatchDraw(); // 立即刷新显示
        b1.removeColor();
        b1.drawButton();
        Sleep(2);

        _mach.changeStateTo("PlayerNum");
    }
    else if (b2.isClicked(msg))
    {
        b2.setColor(BLACK);
        b2.drawButton();
        FlushBatchDraw(); // 立即刷新显示
        b2.removeColor();
        b2.drawButton();

        closegraph(); // 先关闭图形窗口
        exit(0);
    }


}


void StartMenu::render() {
    drawStartMenu();
    b1.drawButton();
    b2.drawButton();
}


void StartMenu::enter() {
    initgraph(1600, 900);
    render();
}

