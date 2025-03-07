#pragma once

/**
 * @file GameState.h
 * @author ������
 * @brief ��������Ϸ�Ĳ�ͬ״̬���߱��Ĺ��нӿڣ���״̬��ʹ�á�
 * @version 1.1
 */

class StateMachine;
class StartMenu;

class GameState {
public:

	/**
	 * @brief ����GameState
	 *
	 * ����StateMachine�����ü�¼Ϊ��Ա������
	 * ȷ����ȫ��ֻʹ��Ψһ��һ��mach
	 * 
	 * @param ��mach������
	 * @author ������
	 */
	GameState(StateMachine& mach)
		:_mach(mach) {}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	virtual void update() = 0;


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	virtual void render() = 0;


	/**
	 * @brief �����״̬
	 * 
	 * ��ʼ��
	 * ��Ⱦ����
	 * 
	 * @author ������
	 */
	virtual void enter() = 0;


	/**
	 * @brief �˳���ǰ״̬
	 * 
	 * ��¼���޸ı�Ҫ������
	 * ��ս���
	 * 
	 * @author ������
	 */
	virtual void exit() = 0;



protected:

	/*
	* �ڹ��캯���ж�������ý��г�ʼ����
	* �������е�GameState�����Լ̳�������ã�����������MainGame�ж����Ψһһ��״̬��ʵ����
	* ����������MainGame�ж����Ψһһ��״̬��ʵ�������������Ϸ���Ʒ�������
	*/
	StateMachine& _mach;
};