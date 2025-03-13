/**
 * @file MainGame.cpp
 * @author ������
 * @brief ��Ϸ��������
 * 
 * �����ʼ����״̬����ʵ��mach�����������ڲ��������������ã�
 * ���������ô������е�GameState���Ա���ʱ������в���
 * 
 * @version 2.0
 */

#include "StateMachine.h"
#include <easyx.h>


 /**
  * @brief ��Ϸѭ��
  *
  * ȫ�ֽ��ڴ˴���ʼ��Ψһ��StateMachineʵ��
  * ��ȡ�û��������Ϣ������״̬��Ȼ��ˢ��һ֡
  *
  * @author ������
  */
void gameLoop() {
	StateMachine mach;
	ExMessage meg;
	while (true) {
		peekmessage(&meg);
		mach.update(meg);
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