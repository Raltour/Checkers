/**
 * @file Board.cpp
 * @brief Board������ʵ��
 * @author 
 * @version 2.5.8
 */

#include "Board.h"
#include <iostream>

Board::Board() {
    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = top_y + i * m_cellSize;

            
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    for (int i = 4; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = OFFSET_Y - i * m_cellSize;

            
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    //��
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = top_y + i * m_cellSize;

            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    //��
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = OFFSET_Y - i * m_cellSize;

           
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    //����
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = lt_x + (j - i / 2.0) * m_cellSize;
            int y = lt_y - i * m_cellSize;

            
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    //����
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = rd_x + (j - i / 2.0) * m_cellSize;
            int y = rd_y + i * m_cellSize;

            
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    //����
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = ld_x + (j - i / 2.0) * m_cellSize;
            int y = ld_y + i * m_cellSize;

            addChess(Chess::createChess(x, y, WHITE));
            
            state.push_back(false);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = rt_x + (j - i / 2.0) * m_cellSize;
            int y = rt_y - i * m_cellSize;

           
            addChess(Chess::createChess(x, y, WHITE));
            state.push_back(false);
        }
    }

    hashIndex();
    buildadj();
    
}


Board::~Board() {
    for (auto chess : m_chesses) {
        if (chess) {
            delete chess;
            chess = nullptr;
        }
    }
}


void Board::addChess(Chess* chess) {
    m_chesses.push_back(chess);

    //��û����
    /*if (pos_map.find(chess->x()) != pos_map.end() &&
        pos_map[chess->x()].find(chess->y()) != pos_map[chess->x()].end()) {
        int index = pos_map[chess->x()][chess->y()];
        state[index] = false;
    }*/
}


void Board::hashIndex() {
    int size = m_chesses.size();
    for (int i = 0; i < size; i++)
    {
        pos_map[m_chesses[i]->x()][m_chesses[i]->y()] = i;
    }
}


// �����ڽӱ���������������ڽڵ㣬Ȼ��ͨ����ϣ������������������
void Board::buildadj() {
    adj.resize(m_chesses.size());
    for (int i = 0; i < m_chesses.size(); i++)
    {
        int x = m_chesses[i]->x();
        int y = m_chesses[i]->y();
        //std::cout << x << " " << y << std::endl;
        for (int j = 0; j < 6; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            //std::cout << j << std::endl;
            if (pos_map.count(nx) && pos_map[nx].count(ny))
            {

                int neighbor = pos_map[nx][ny];
                //std::cout << neighbor << std::endl;
                adj[i].push_back(neighbor);         //��ѯ���Ӷ�  o(1)
            }
        }
    }
}


bool Board::isMoveChess(Chess* chess, ExMessage& msg) {
    //findSingleJumpMove(chess);
    
        getJumpMove(chess);

        if (isHereAChess(msg))
        {
            int x = isHereAChess(msg)->x();
            int y = isHereAChess(msg)->y();
            if (path.size() >= 1)
            {
                //std::cout << path.size() << std::endl;
                //true ��ʾ�������
                for (auto& p : path)
                {
                    if (p == pos_map[x][y])
                    {
                        //�ָ���ɫ
                        chess->recoveryColor();

                        m_chesses[pos_map[x][y]]->changeChess(chess->color());
                        
                        //�ƶ���ԭ�����ӵ�״̬
                        state[pos_map[chess->x()][chess->y()]] = false;
                       
                       
                        m_chesses[pos_map[chess->x()][chess->y()]]->changeChess(WHITE);
                        //�����ƶ���λ��
                        state[p] = true;

                        //����
                        cleardevice();
                        //std::cout << "wwww" << std::endl;
                        drawChechersGame(*this);
                        hashIndex();   // ������������
                        buildadj();    // �����ڽӱ�
                        //drawChechersGame(*this);
                        return true;
                    }

                }
            }

        return false;
    }
}


// �ҵ����ڵ���Ծ�ڵ㣬�����ڽӱ�õ�������path·������
void Board::findSingleJumpMove(Chess* chess) {
    int currentIndex = pos_map[chess->x()][chess->y()];
    for (auto neighborIndex : adj[currentIndex]) {
        if (!state[neighborIndex]) {
            path.push_back(neighborIndex);
        }
    }
}


// �ҵ�������Ծ��������Ծ��ͬʱʹ��·������洢��ʹ�ñ�ǹ�ϣ��洢�ѷ��ʵ�λ��
void Board::findDoybleJumpMove(Chess* chess, int step) {
    for (int dir = 0; dir < 6; dir++) {
        int mid_x = chess->x() + dx[dir] * step;
        int mid_y = chess->y() + dy[dir] * step;

        int target_x = chess->x() + dx[dir] * step * 2;
        int target_y = chess->y() + dy[dir] * step * 2;

        bool isChess = true;
        for (int i = 1; i < step; i++)
        {
            int check_x = chess->x() + dx[dir] * i;
            int check_y = chess->y() + dy[dir] * i;
            if (!pos_map.count(check_x) || !pos_map[check_x].count(check_y) || state[pos_map[check_x][check_y]])
            {
                isChess = false;
                continue;
            }
        }

        if (isChess)
        {
            for (int i = step + 1; i < (step << 1); i++)
            {
                int check_x = chess->x() + dx[dir] * i;
                int check_y = chess->y() + dy[dir] * i;
                if (!pos_map.count(check_x) || !pos_map[check_x].count(check_y) || state[pos_map[check_x][check_y]])
                {
                    isChess = false;
                    continue;
                }
            }
        }
        // ����м�ڵ��Ƿ������������
        if (isChess && pos_map.count(mid_x) && pos_map[mid_x].count(mid_y)) {
            int midPos = pos_map[mid_x][mid_y];
            if (state[midPos] != 0) { // �м�ڵ�������
                // ���Ŀ��ڵ��Ƿ������Ϊ��
                if (pos_map.count(target_x) && pos_map[target_x].count(target_y)) {
                    int targetPos = pos_map[target_x][target_y];
                    if (state[targetPos] == 0 && visited.count(targetPos) == 0) { // Ŀ��ڵ�Ϊ����δ����
                        // ���Ŀ��ڵ㵽·��
                        path.push_back(targetPos);
                        visited.insert(targetPos);
                        // �ݹ����Ƿ���Խ�һ����Ծ
                        for (int i = 1; i <= 5; i++)
                            findDoybleJumpMove(m_chesses[targetPos], i); // �Ӳ���1��ʼ�ݹ�
                    }
                }
            }
        }
    }
}


// ����DFS �ݹ�������ֱ��ѭ��maxStep�Σ�����findDoybleJumpMove
void Board::getJumpMove(Chess* chess) {
    visited.clear();  // ���� visited
    path.clear();     // ���� path
    findSingleJumpMove(chess);
    for (int step = 1; step <= 5; ++step) {
        findDoybleJumpMove(chess, step);
    }
}


Chess* Board::isHereAChess(ExMessage& msg) {
    int x = msg.x;
    int y = msg.y;

    for (auto& p : m_chesses)
    {
        int p_x = p->x();
        int p_y = p->y();
        int m_x = p_x - x;
        int m_y = p_y - y;
        if (m_x * m_x + m_y * m_y <= 144)
            return p;
    }
    return nullptr;
}


bool Board::moveChess(Chess* chess, ExMessage& msg) {
    
	return false;
}


bool Board::isChessWin(COLORREF color) {
    if (color == WHITE) {
        for (auto chess : m_chesses) {
            if (chess->color() == color) {
                if (chess->y() > top_y) {
                    return false;
                }
            }
        }
        return true;
    }
    // ������ɫ��ʤ������
    return false;
}

