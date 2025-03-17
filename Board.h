#pragma once

/**
 * @file Board.h
 * @brief ������������Լ���������
 * @author ���Ʒ�
 * @version 2.5.8
 */

#include "Chess.h"
#include "Player.h"
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>

class Board {
public:

    Board();

    //�ͷ����������е�����ָ���Ӧ���ڴ�
    ~Board();


    /*
        ������: 
        ����: ������ӵ�������
        ����: ���Ӷ���
        ����ֵ: ��
    */
    void addChess(Chess* chess);


    /*
        ������:
        ����: �����������꣬������ӳ�������
        ����pos_map[x][y] = i;
        ����: �޲���
        ����ֵ���޷���ֵ
    */
    void hashIndex();


    /*
        ������:
        ����: �����ڽӱ���������������ڽڵ㣬
        Ȼ��ͨ����ϣ������������������

        �������ж���posÿ�������dx dy��������������
        Ȼ��ͨ����ϣ����ٲ������ڵ���±겢����
        ����: �޲���
        ����ֵ���޷���ֵ
    */
    void buildadj();


    /*
    ������:
    ����: ����ƶ�λ���Ƿ�Ϸ�
          ����ʹ��ʹ��handleClick()�ж�

    ����: ���ӵ�ָ��   �µ�x��y����
    ����ֵ: ���ƶ����򷵻�true�����ܷ���false
*/
    bool isMoveChess(Chess* chess, ExMessage& msg);


	/**
	 * @brief �ж��������λ���ǲ���һ������
	 *
	 * ���������б�ʹ��x��y�����ֵ֮��С�ڰ뾶��ƽ��
	 *
	 * @param �����Ϣ
	 * @return �����һ�����ӣ���ָ�뷵�أ����򷵻ؿտ�ָ��
	 * @author ��������
	 */
	Chess* isHereAChess(ExMessage &msg);


	/**
	 * @brief ���ݺ�����������룬�ƶ�����
	 *
	 * ���������е��ƶ������̼��������Ӷ�Ӧ�������û��ʤ��
	 * ͨ����isChessWin���ݸ����ӵ���ɫ�����ж�
	 *
	 * @param ��Ҫ�ƶ������ӵĵ�ַ
	 * @return ����Ƿ�ʤ��
	 * @author ��������
	 */
	bool moveChess(Chess *chess);//����ֵ���������û��ȡ��ʤ��


    /**
     * @brief �ж��ƶ���ɺ���û��ʤ��
     *
     * ��������Ƿ�ȫ������Խ�����
     * ����ض���ɫ�Ķ�Ӧ�����Ƿ������˶�Ӧ������
     * �����ϵ���ɫ�ֲ��ǹ̶��ģ��������Ӧ��ȥ��λ��
     *
     * @param ��Ҫ�жϵ����ӵ���ɫ
     * @return ����Ƿ�ʤ��
     * @author ��������
     */
    bool isChessWin(COLORREF color);


private:

	std::vector<Chess*> m_chesses;   //��������
	std::unordered_map<int, std::unordered_map<int, int>> pos_map;   //�洢�����Ĺ�ϣ��
	std::vector<std::vector<int>> adj;    //�ڽӱ�
	std::unordered_set<int> visited;      //����ѷ���
	std::vector<int> path;      //·��
	std::vector<bool> state;    //״̬

	const int m_width = 800;       //��� 
	const int m_height = 600;      //�߶�      
	int m_cellSize = 30;           //���̸��Ӵ�С
	COLORREF m_backgroundColor = WHITE;   // ���̱�����ɫ
	std::vector<int> dx = { 30, -30, 15, -15, 15, -15 }; // ��������
	std::vector<int> dy = { 0, 0, -30, -30, 30, 30 };
	const int OFFSET_X = 300;   //�����͵ײ������ε�x����
	const int OFFSET_Y = 590;  //�ײ������ε�y����
	const int top_y = 110;    //���������ε�y����
	const int lt_x = 165;     //���������ε�x����
	const int lt_y = 320;     //���������ε�y����
	const int rt_x = 435;     //���������ε�x����
	const int rt_y = 320;     //���������ε�y����
	const int ld_x = 165;     //���������ε�x����
	const int ld_y = 380;     //���������ε�y����
	const int rd_x = 435;     //���������ε�x����
	const int rd_y = 380;     //���������ε�y����



    /*
    ������:
    ����: �ҵ����ڵ���Ծ�ڵ㣬�����ڽӱ�õ�
          ����path·������
    ����: ���ӵ�ָ��
    ����ֵ����
*/
    void findSingleJumpMove(Chess* chess);


    /*
        ������:
        ����: �ҵ�������Ծ��������Ծ��ͬʱʹ��·������洢��
        ʹ�ñ�ǹ�ϣ��洢�ѷ��ʵ�λ��
            1.�����м�ڵ����Ծ��Ŀ��ڵ㣬�м�ڵ�+[dx,dy] * step
             Ŀ��ڵ�+[dx,dy] * step * 2
            2.���ñ��λ�ò����м�ڵ�֮ǰû������(ͨ��state)�������Ӵ���(ͨ����ϣ���ѯ)����true
               ����ͨ���¼������¼�ֱ�ӷ���false
            ͬʱ�м�����
            �м�ڵ㵽Ŀ��ڵ�û������(ͨ��state)��û��������true
            3.���true
              ���visited��ȷ��û�з��ʹ�
                �����ϣ����û�иýڵ�
                   ���Ŀ��ڵ㵽path,visted
                Ȼ���ٷ��ʽ��еݹ飬��������Ϊ5
        ����: ���ӵ�ָ�룬ÿ����Ծ�Ĳ���
        ����ֵ����
    */
    void findDoybleJumpMove(Chess* chess, int step);


    /*
        ������:
        ����: ����DFS �ݹ�����
             ֱ��ѭ��maxStep�Σ�����findDoybleJumpMove
        ����: ���ӵ�ָ��
        ����ֵ����
    */
    void getJumpMove(Chess* chess);

};