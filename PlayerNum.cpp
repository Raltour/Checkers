/**
 * @file PlayerNum.cpp
 * @brief PlayerNum������ʵ��
 * @author 
 * @version 2.5.1
 */

#include "PlayerNum.h"
#include "Render.h"


//���������������PlayerNum��PlayerNum֮�乲��
extern int _num_of_players = 10;//Ϊ�˹��������д��


PlayerNum::PlayerNum(StateMachine& _self_ref)
    :GameState(_self_ref) {
    btn2 = Button(700, 250, 400, 100, "˫��ģʽ");
    btn4 = Button(700, 400, 400, 100, "4��ģʽ");
    btn6 = Button(700, 550, 400, 100, "6��ģʽ");
}


void PlayerNum::update(ExMessage& msg) {
    if (btn2.isClicked(msg))
    {
        btn2.setColor(BLACK);
        btn2.drawButton();

        FlushBatchDraw();

        btn2.removeColor();
        btn2.drawButton();

    }
}


void PlayerNum::render() {
    drawPlayerNum();


    btn2.drawButton();
    btn4.drawButton();
    btn6.drawButton();

    settextstyle(90, 0, "����");
    outtextxy((1500 - 100) / 2, 100, "ģʽѡ��");


}


void PlayerNum::enter() {

}

