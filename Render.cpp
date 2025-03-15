/**
 * @file Render.cpp
 * @brief ��ͼ�����ľ���ʵ��
 * 
 * @author 
 * @version 2.5.2
 */

#include <string>
#include "Render.h"


  /**
   * @brief ��������
   *
   * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
   *
   * @param ����1 ��������1������
   * @param ����2 ��������2������
   * @return ����ֵ������
   * @author ��������
   */
void drawChess(){}


/**
 * @brief ��������������
 *
 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
 *
 * @param ����1 ��������1������
 * @param ����2 ��������2������
 * @author ��������
 */
void drawHexagonGrid(){}


/*
	������:
	����: ���������Σ�
	ͬʱʹ��addChess������ӣ�
	state ��¼�����״̬  ���������0
		  ���ݲ�ͬ����ɫ���ò�ͬ��״̬
	pos��¼�������ӵ�����



	����: p_x,p_y Ϊ��ʼ����   n ��ʾ������  c ��ʾ�����������Ļ��ǵ���
	color��ɫ
	����ֵ���޷���ֵ
*/
void drawTriangle(int p_x, int p_y, const char c, int n, COLORREF color){}


void drawStartMenu() {

    // ����ͼƬ
    IMAGE img;
    loadimage(&img, "p1.jpg", 1600, 900);  // ����ͼƬ��·��Ϊ "p1.jpg"
    putimage(0, 0, &img);  // ��ͼƬ���Ƶ����ڵ� (0, 0) λ��


    IMAGE image;
    loadimage(&image, "p2.jpg", 200, 100);
    putimage(700, 100, &image);


}


void drawPlayerNum() {
    setbkcolor(RGB(173, 216, 230));

    int btnWidth = 400;
    int btnHeight = 100;
    int centerX = 1500 / 2 - btnWidth / 2;

    Button btn2(centerX, 250, btnWidth, btnHeight, "˫��ģʽ");
    Button btn4(centerX, 400, btnWidth, btnHeight, "4��ģʽ");
    Button btn6(centerX, 550, btnWidth, btnHeight, "6��ģʽ");

    settextcolor(WHITE);
    settextstyle(90, 0, "����");
    outtextxy((1500 - textwidth("ģʽѡ��")) / 2, 100, "ģʽѡ��");

    btn2.drawButton();
    btn4.drawButton();
    btn6.drawButton();

}


// ���ƻ�ӭ���沢��Ӷ���Ч��
void drawWelcomeInterface(const TCHAR* id) {
    // ���ñ�����ɫΪǳ��ɫ
    setbkcolor(RGB(173, 216, 230));
    cleardevice();
    // ����������ɫΪ��ɫ
    settextcolor(BLACK);
    // ���������С
    settextstyle(70, 0, _T("����"));
    TCHAR message[50];
    _stprintf_s(message, _T("��ӭ��%s���ɹ���¼������Ϸ��"), id);
    int len = _tcslen(message);
    TCHAR temp[50] = { 0 };
    for (int i = 0; i <= len; i++) {
        _tcsncpy_s(temp, message, i);
        temp[i] = '\0';
        setbkcolor(RGB(173, 216, 230));
        cleardevice();
        int textWidth = textwidth(temp);
        int textHeight = textheight(temp);
        int x = (1600 - textWidth) / 2;
        int y = (900 - textHeight) / 2;

        outtextxy(x, y, temp);
        Sleep(100); // ���ƶ����ٶ�
    }
}
// ���Ƶ�¼����
void drawLoginInterface() {
    // ���ñ�����ɫΪǳ��ɫ
    setbkcolor(RGB(173, 216, 230));
    cleardevice();
    // ����������ɫΪ��ɫ
    settextcolor(BLACK);
    // ���������С
    settextstyle(60, 0, _T("����"));
    // ��ȡ���ֿ�Ⱥ͸߶�
    int textWidth = textwidth(_T("��������Ϸ ID����Ӣ�ģ�:"));
    int textHeight = textheight(_T("��������Ϸ ID����Ӣ�ģ�:"));
    int x = (1500 - textWidth) / 2;
    int y = (1000 - textHeight) / 2 - 100;
    outtextxy(x, y, _T("��������Ϸ ID����Ӣ�ģ�:"));
}
void drawPlayerInfo() {
    // ��ʼ��ͼ�δ��ڣ���СΪ 1600x900
    initgraph(1600, 900);
    // ���Ƶ�¼����
    drawLoginInterface();

    // ���ƻ�ӭ���沢��Ӷ���Ч��
    //drawWelcomeInterface(id);

    // �ر�ͼ�δ���
    closegraph();
}


/**
 * @brief
 *
 * 	�������̺�����,����ʹ��4��4��������������Χ��
 * ������9��������ǣ�8��ĵ�������ɣ������Ѹ���
 * ����6��drawTriangle ����
 *
 * @param ����1 ��������1������
 * @param ����2 ��������2������
 * @return ����ֵ������
 * @author ��������
 */
void drawChechersGame(){}


/**
 * @brief
 *
 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
 *
 * @param ����1 ��������1������
 * @param ����2 ��������2������
 * @return ����ֵ������
 * @author ��������
 */
void drawWinView(){}


/**
* @brief ���ر���ͼƬ
*
* �ɽ���Ĵ�ӡ�������ã����ظ����ı���ͼƬ
* �����ͼƬ������ӡ��������������
* ����Ḳ��
*
* @param ͼƬ�ĵ�ַ
* @return ����ֵ������
* @author ��������
*/
void loadBackGroundImage(std::string filename){}

