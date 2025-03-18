/**
 * @file Render.cpp
 * @brief ��ͼ�����ľ���ʵ��
 * 
 * @author 
 * @version 2.5.8
 */

#include <string>
#include "Render.h"
#include "Board.h"

extern int _num_of_players;

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
void drawChess(int x, int y, COLORREF color)
{
    setfillcolor(color);
    fillcircle(x, y, 12);
}


/**
 * @brief ��������������
 *
 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
 *
 * @param ����1 ��������1������
 * @param ����2 ��������2������
 * @author ��������
 */
void drawHexagonGrid(Board& b)
{
}


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
void drawTriangle(Board& b)
{
    for (auto& p : b.m_chesses)
    {
        drawChess(p->x(), p->y(), p->color());
    }
}


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

    cleardevice();

}


void drawPlayerInfo() {
    setbkcolor(RGB(173, 216, 230));
    cleardevice();


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
void drawChechersGame(Board& b)
{
    setbkcolor(RGB(173, 216, 230));
    cleardevice();

    drawTriangle(b);


}


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

