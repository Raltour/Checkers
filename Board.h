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
	bool moveChess(Chess *chess,ExMessage &msg);//����ֵ���������û��ȡ��ʤ��


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

    std::vector<bool> state;        //״̬
    //const int m_width = 1600;       //��� 
    //const int m_height = 900;      //�߶�      
    int m_cellSize = 40;           //���̸��Ӵ�С
    //COLORREF m_backgroundColor = WHITE;   // ���̱�����ɫ
    std::vector<int> dx = { 40, -40, 20, -20, 20, -20 }; // ��������
    std::vector<int> dy = { 0, 0, -40, -40,40, 40 };
    const int OFFSET_X = 800;   //�����͵ײ������ε�x����
    const int OFFSET_Y = 740;  //�ײ������ε�y����
    const int top_y = 100;    //���������ε�y����
    const int lt_x = 620;     //���������ε�x����
    const int lt_y = 380;     //���������ε�y����
    const int rt_x = 980;     //���������ε�x����
    const int rt_y = 380;     //���������ε�y����
    const int ld_x = 620;     //���������ε�x����
    const int ld_y = 460;     //���������ε�y����
    const int rd_x = 980;     //���������ε�x����
    const int rd_y = 460;     //���������ε�y����
    std::vector<Chess*> m_chesses;   //��������
private:
    
    std::unordered_map<int, std::unordered_map<int, int>> pos_map;   //�洢�����Ĺ�ϣ��
    std::vector<std::vector<int>> adj;    //�ڽӱ�
    std::unordered_set<int> visited;      //����ѷ���
    std::vector<int> path;      //·��


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