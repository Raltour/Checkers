/**
 * @file MainGame.cpp
 * @author ������
 * @brief ��Ϸ��������
 *
 * ���ļ�������Ϸ������������Ϸѭ���߼���
 * �������ʼ����״̬����Ψһʵ�� `mach`���������ڲ��������������á�
 * �����ûᱻ���ݸ����е� `GameState`���Ա�����Ϸ��������ʱ����״̬�л��Ͳ�����
 *
 * @version 2.5.6
 */

#include "StateMachine.h"
#include <easyx.h>


 /**
  * @brief ��Ϸѭ��
  *
  * �ú�������Ϸ����ѭ���������ʼ��״̬���������û����롢������Ϸ״̬����Ⱦ���档
  * ȫ�ֽ��ڴ˴���ʼ��Ψһ�� `StateMachine` ʵ����
  * ѭ���в��ϻ�ȡ�û��������Ϣ������״̬��״̬����ˢ��һ֡���档
  *
  * @author ������
  */
void gameLoop() {
	StateMachine mach; // ��ʼ��״̬��ʵ��
	ExMessage meg;     // ���ڴ洢�û��������Ϣ

	while (true) {

		BeginBatchDraw();
		//��ȡ�û����루�������������룩
		while (peekmessage(&meg, EX_MOUSE | EX_KEY, true)) { // true��ʾ�Ƴ���Ϣ
			mach.update(meg);
		}

		cleardevice();     // ��ջ���
		// ��Ⱦ��ǰ��Ϸ״̬
		mach.render();


		EndBatchDraw();
		Sleep(1);
	}
	closegraph();
}

/**
 * @brief �������
 *
 * ������������gameLoop������Ϸѭ����
 *
 * @author ������
 */
int main() {
	// ������Ϸѭ��
	gameLoop();

	return 0;
}