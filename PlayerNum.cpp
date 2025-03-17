/**
 * @file PlayerNum.cpp
 * @brief PlayerNum函数的实现
 * @author 
 * @version 2.5.8
 */

#include "PlayerNum.h"
#include "Render.h"


//储存玩家数量，在PlayerNum和PlayerNum之间共享
extern int _num_of_players = 0;


PlayerNum::PlayerNum(StateMachine& _self_ref)
    :GameState(_self_ref) {
    btn2 = Button(700, 250, 400, 100, "双人模式");
    btn4 = Button(700, 400, 400, 100, "4人模式");
    btn6 = Button(700, 550, 400, 100, "6人模式");
}


void PlayerNum::update(ExMessage& msg) {
    if (btn2.isClicked(msg))
    {
        btn2.setColor(BLACK);
        btn2.drawButton();

        FlushBatchDraw();

        btn2.removeColor();
        btn2.drawButton();

        _num_of_players = 2;
        _mach.changeStateTo("PlayerInfo");
    }
    else if (btn4.isClicked(msg)) {
        btn4.setColor(BLACK);
        btn4.drawButton();

        FlushBatchDraw();

        btn4.removeColor();
        btn4.drawButton();

        _num_of_players = 4;
        _mach.changeStateTo("PlayerInfo");
    }
    else if (btn6.isClicked(msg)) {
        btn6.setColor(BLACK);
        btn6.drawButton();

        FlushBatchDraw();

        btn6.removeColor();
        btn6.drawButton();

        _num_of_players = 6;
        _mach.changeStateTo("PlayerInfo");
    }
}


void PlayerNum::render() {
    drawPlayerNum();


    btn2.drawButton();
    btn4.drawButton();
    btn6.drawButton();

    settextstyle(90, 0, "宋体");
    outtextxy((1500 - 100) / 2, 100, "模式选择");


}


void PlayerNum::enter() {

}

