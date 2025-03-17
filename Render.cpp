/**
 * @file Render.cpp
 * @brief ��ͼ�����ľ���ʵ��
 * 
 * @author 
 * @version 2.5.7
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
    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = b.OFFSET_X + (j - i / 2.0) * b.m_cellSize;
            int y = b.top_y + i * b.m_cellSize;

            b.addChess(Chess::createChess(x, y, WHITE));
            drawChess(x, y, WHITE);
        }
    }

    for (int i = 4; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = b.OFFSET_X + (j - i / 2.0) * b.m_cellSize;
            int y = b.OFFSET_Y - i * b.m_cellSize;

            b.addChess(Chess::createChess(x, y, WHITE));
            drawChess(x, y, WHITE);
        }
    }
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
void drawTriangle(Board& b, int p_x, int p_y, const char c, int n, COLORREF color)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = p_x + (j - i / 2.0) * b.m_cellSize;
            int y = ((c == '+') ? (p_y + i * b.m_cellSize) : (p_y - i * b.m_cellSize));

            b.addChess(Chess::createChess(x, y, color));
            drawChess(x, y, color);
        }
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

    drawHexagonGrid(b);

    if (_num_of_players == 2)
    {
        //��
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //��
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);
    }


    else if (_num_of_players == 4)
    {
        //��
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //��
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);

        //����
        drawTriangle(b, b.lt_x, b.lt_y, '-', 4, BLUE);

        //����
        drawTriangle(b, b.rd_x, b.rd_y, '+', 4, YELLOW);
    }
    else if (_num_of_players == 6)
    {
        //��
        drawTriangle(b, b.OFFSET_X, b.top_y, '+', 4, RED);

        //��
        drawTriangle(b, b.OFFSET_X, b.OFFSET_Y, '-', 4, GREEN);

        //����
        drawTriangle(b, b.lt_x, b.lt_y, '-', 4, BLUE);

        //����
        drawTriangle(b, b.rd_x, b.rd_y, '+', 4, YELLOW);

        //����
        drawTriangle(b, b.ld_x, b.ld_y, '+', 4, YELLOW);

        //����
        drawTriangle(b, b.rt_x, b.rt_y, '-', 4, BLUE);


    }


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

