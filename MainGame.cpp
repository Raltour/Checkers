/**
 * @file MainGame.cpp
 * @author ������
 * @brief ��Ϸ��������
 * 
 * �����ʼ����״̬����ʵ��mach�����������ڲ��������������ã�
 * ���������ô������е�GameState���Ա���ʱ������в���
 * 
 * @version 1.3
 */

#include "StateMachine.h"


 /**
  * @brief ��Ϸѭ��
  *
  * ȫ�ֽ��ڴ˴���ʼ��Ψһ��StateMachineʵ��
  *
  * @author ������
  */
void gameLoop() {
	StateMachine mach;
	while (true) {
		mach.update();
		mach.render();
	}
}

int main() {
	gameLoop();

	return 0;
}


//�ļ�ע�͹淶
/**
 * @file MyClass.cpp
 * @brief ���ļ�ʵ���� MyClass ��Ĺ��ܡ�
 * @author ����
 * @version 1.0
 */


//����ע�͹淶
/**
 * @brief �������ܵļ�Ҫ����
 *
 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
 *
 * @param ����1 ��������1������
 * @param ����2 ��������2������
 * @return ����ֵ������
 * @author ��������
 */