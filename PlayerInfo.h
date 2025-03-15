#pragma once

/**
 * @file PlayerNumber.h
 * @brief ���������ҵ�����������������
 * @author ������
 * @version 2.5.1
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"
#include "Player.h"
#include <vector>

class PlayerInfo : public GameState {
public:

	PlayerInfo(StateMachine& _self_ref);


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * �˳��ý���ʱ����������������Ϣ���ɶ�Ӧ���������
	 * 
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	virtual void render();


	/**
	 * @brief �����״̬ʱ������Ӧ����
	 * @author ������
	 */
	virtual void enter();


private:

	//�����������������ǳ�
	std::vector<std::string> names;
	//���������ҵĶ�Ӧ��ɫ
	std::vector<COLORREF> colors;

};