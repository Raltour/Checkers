#pragma once

/**
 * @file Chess.h
 * @brief �����е�����
 * @author ���Ʒ�
 * @version 2.3
 */

#include <string>
#include "Render.h"
#include <memory>


enum chessState { NORMAL, SELECTED };
class Chess
{
private:

	Chess();

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


public:

    /*
        ������: ���Ʒ�
        ����: ����һ����������ʵ����
        ʹ�� std::unique_ptr ȷ�� Chess �������������������ָ����������ڴ�й©��

           ��ʼ��:ֱ�ӷ���new�Ķ���
        ����: ���� x,y
              ��ɫ color
        ����ֵ������һ��ָ���������ռ����Ȩ������ָ�룬�Զ�����
    */
    static std::unique_ptr<Chess> create(int x, int y, COLORREF);


    /*
        ������: ���Ʒ�
        ����: ��ȡ���ӵ�x���꣬
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    int x() const;


    /*
        ������: ���Ʒ�
        ����: ��ȡ���ӵ�y���꣬
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    int y() const;


    /*
        ������: ���Ʒ�
        ����: ��ȡ������ɫ��
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    COLORREF color() const;


    /*
        ������: ���Ʒ�
        ����: ��ȡ����״̬��
            const��ʾ������
        ����:  ��
        ����ֵ����
    */
    chessState state() const;


    /*
        ������: ���Ʒ�
        ����: ʹ��˽�г�Ա�滭����
            ʹ��easyx����Բ�����ӣ�ʹ�����ӵ�x��y���꣬��ɫ
        ����:  ��
        ����ֵ����
    */
    void draw();


    /*
        ������: ���Ʒ�
        ����: �������ӵ�λ��
            ֱ�ӷ���˽�г�Ա�޸�
        ����: λ������x��y
        ����ֵ����
    */
    void setPosition(int x, int y);


    /*
        ������: ���Ʒ�
        ����: �������ӵ�״̬
             ����״̬�޸�
        ����: ���ӵ�״̬
        ����ֵ����
    */
    void setState(chessState state);


    /*
        ������: ���Ʒ�
        ����: �ı����ӵ���ɫ
        ������ɫ�޸ģ���ʱ���ȼ�¼ԭ����ɫ�����ڻ�ԭ
        ����: ��ɫ
        ����ֵ����
    */
    void changeChess(COLORREF color);


    /*
        ������: ���Ʒ�
        ����: ���ú�����ԭ����ɫ���ָ���ɫ
        ����: ��
        ����ֵ����
    */
    void removeChess();
};

