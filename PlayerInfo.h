#pragma once

/**
 * @file PlayerNumber.h
 * @brief ���������ҵ�����������������
 * @author ������
 * @version 1.5
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"
#include "Player.h"
#include <vector>

class PlayerInfo : public GameState {
public:

	PlayerInfo(StateMachine& _self_ref)
		:GameState(_self_ref) {
	}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author
	 */
	virtual void update(ExMessage &msg) {}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author
	 */
	virtual void render() {}


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ���������
	 *
	 * @author
	 */
	virtual void enter() {
		
	}


	/**
	 * @brief �˳�ʱ���ɸ������������
	 *
	 * ����˽�е��ַ�����Ա�������������ɶ�Ӧ����Щ���
	 *
	 * @author ������
	 */
	virtual void exit() {
		for (int i = 0; i < _num_of_players; i++) {
			Player::addNewPlayer(colors[i], names[i]);
		}
		cleardevice();
	}

private:

	std::vector<std::string> names;
	std::vector<std::string> colors;

};