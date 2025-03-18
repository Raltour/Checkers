#pragma once

/**
 * @file CheckersGame.h
 * @brief ��������������壬������Ϸ
 * @author ������
 * @version 2.5.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"
#include "Player.h"


class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref);


	~CheckersGame() {
		delete _chess_board;
	}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	virtual void render();


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author ������
	 */
	virtual void enter();


private:
	Chess* _selected_chess = nullptr; // ��¼��ǰѡ�е�����
	bool _is_chess_selected = false;  // �Ƿ���ѡ������

	//��Ϸ���̵�ָ��
	Board* _chess_board;

	//����Ŀ�����ӻ᲻�ϱ仯��������Ϊ���ã�����ָ��
	Chess* _chess;

};