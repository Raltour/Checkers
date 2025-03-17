#pragma once

/**
 * @file WinView.h
 * @brief ʤ�����㻭��
 *
 * ���ļ�������ʤ�����㻭����� `WinView`���̳��� `GameState`��
 * ����Ϸ����ʱ�������״̬����ʾʤ����Ϣ�����ṩ�������˵������¿�ʼ��Ϸ��ѡ�
 *
 * @author ������
 * @version 2.5.7
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	/**
	 * @brief ���캯��
	 *
	 * ��ʼ��ʤ�����㻭�棬������״̬���������Ա����״̬�л���
	 *
	 * @param _self_ref ״̬��������
	 * @author ������
	 */
	WinView(StateMachine& _self_ref);


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * ���������λ�û���������ַ�������ʤ�����㻭���״̬��
	 * ���磬������ҵ�����������˵��������¿�ʼ����ť���߼���
	 *
	 * @param msg ������Ϣ�����������λ�û���������ַ�
	 * @author ������
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 *
	 * ����ʤ�����㻭�棬����ʤ����Ϣ����ҵ÷֡��������˵���ť�ȡ�
	 *
	 * @author ������
	 */
	virtual void render();


	/**
	 * @brief �����״̬
	 *
	 * ���л���ʤ�����㻭��ʱ���ã���ʼ�������Ϣ��ʤ��������
	 * ���磬����������ơ���ɫ�͵÷ֵ���Ϣ��
	 *
	 * @author ������
	 */
	virtual void enter();

private:

	std::vector<std::string> _names; // �洢�������
	std::vector<std::string> _colors; // �洢�����ɫ

};