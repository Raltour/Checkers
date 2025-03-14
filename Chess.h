#pragma once

/**
 * @file Chess.h
 * @brief �����е�����
 * @author ���Ʒ�
 * @version 2.5
 */

#include <string>
#include "Render.h"
#include <memory>


enum chessState { NORMAL, SELECTED };
class Chess
{
public:

    /*
        ������: 
        ����: ����һ����������ʵ����
        �����ڴ�й©��

        ����: ���� x,y
              ��ɫ color
        ����ֵ������һ��ָ���������ռ����Ȩ������ָ�룬�Զ�����
    */
    static Chess* createChess(int x, int y, COLORREF);


    /*
        ������: 
        ����: ��ȡ���ӵ�x���꣬
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    int x() const;


    /*
        ������: 
        ����: ��ȡ���ӵ�y���꣬
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    int y() const;


    /*
        ������: 
        ����: ��ȡ������ɫ��
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    COLORREF color() const;


    /*
        ������: 
        ����: ��ȡ����״̬��
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    chessState state() const;


    /*
        ������: 
        ����: �������ӵ�λ��
            ֱ�ӷ���˽�г�Ա�޸�
        ����: λ������x��y
        ����ֵ����
    */
    void setPosition(int x, int y);


    /*
        ������: 
        ����: �������ӵ�״̬
             ����״̬�޸�
        ����: ���ӵ�״̬
        ����ֵ����
    */
    void setState(chessState state);


    /*
        ������: 
        ����: �ı����ӵ���ɫ
        ������ɫ�޸ģ���ʱ���ȼ�¼ԭ����ɫ�����ڻ�ԭ
        ����: ��ɫ
        ����ֵ����
    */
    void changeChess(COLORREF color);


    /*
        ������: 
        ����: ���ú�����ԭ����ɫ���ָ���ɫ
        ����: ��
        ����ֵ����
    */
    void recoveryColor();

private:

    int _x, _y;//���ӵ�����
    int _chess_size = 12;//���Ӱ뾶

    COLORREF _old_color;    //ԭ����ɫ
    COLORREF _current_color;//��ǰ��ɫ
    bool _is_selected;      //�Ƿ�ѡ������

    /*
        ���ù��죬ʹ������ָ��������
        ��ֹ������ֻ���ƶ�
    */
    Chess(int x, int y, int chessSize = 10, COLORREF currentColor = WHITE);
    Chess(const Chess&) = delete;
    Chess& operator=(const Chess&) = delete;

};

