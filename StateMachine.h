#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 * 
 * ���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * 
 * @version 1.5
 */

#include <string>
#include <map>
#include "GameState.h"
#include "StartMenu.h"
#include "PlayerNum.h"
#include "PlayerInfo.h"
#include "CheckersGame.h"

class StateMachine {
public:

	/*
	* ��ʼ�����������
	* ��һ����Ϸ״̬�ǲ˵�
	* ��¼�����������
	*/
	StateMachine()
		:_self_ref(*this), _curr("StarMenu") {
		StartMenu start_menu(_self_ref);
		_game_states["StarMenu"] = &start_menu;
		PlayerNum player_num(_self_ref);
		_game_states["PlayerMenu"] = &player_num;
		PlayerInfo player_info(_self_ref);
		_game_states["PlayerMenu"] = &player_info;
		CheckersGame checkers_game(_self_ref);
		_game_states["PlayerMenu"] = &checkers_game;

	}


	~StateMachine() {}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	void update() {
		_game_states[_curr]->update();
	}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	void render() {
		_game_states[_curr]->render();
	}


	/**
	 * @brief ����״̬����������Ϸ״̬λ��
	 * 
	 * �˳�ԭ״̬
	 * �Դ�����ַ�������ӳ�䣬�����Ϊ��Ӧ��GameState
	 * ������״̬
	 * 
	 * @param �����ʾ��һ״̬���Ƶ��ַ���
	 * @author ������
	 */
	void changeStateTo(std::string to) {
		_game_states[_curr]->exit();
		_curr = to;
		_game_states[_curr]->enter();
	}


	//GameState& getState(std::string str) {
	//	return *_game_states[str];
	//}

	int parameter;

private:

	std::string _curr;//��¼��Ϸ��ǰ״̬
	std::map<std::string, GameState*> _game_states;//���ַ�������ӳ��Ϊ��Ӧ��GameState
	StateMachine& _self_ref;//����������ã�����GameStateʱ��Ϊ��������


};