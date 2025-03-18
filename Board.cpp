/**
 * @file Board.cpp
 * @brief Board������ʵ��
 * @author 
 * @version 2.5.8
 */

#include "Board.h"


Board::Board()
{
    for (int i = 4; i < 8; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = top_y + i * m_cellSize;

            addChess(Chess::createChess(x, y, WHITE));
        }
    }

    for (int i = 4; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = OFFSET_X + (j - i / 2.0) * m_cellSize;
            int y = OFFSET_Y - i * m_cellSize;

            addChess(Chess::createChess(x, y, WHITE));
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
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = rt_x + (j - i / 2.0) * m_cellSize;
            int y = rt_y - i * m_cellSize;

            addChess(Chess::createChess(x, y, WHITE));
        }
    }
    buildadj();
    hashIndex();
}


Board::~Board() {
    for (auto chess : m_chesses) {
        if (chess) {
            delete chess;
            chess = nullptr;
        }
    }
}


//void Board::addChess(Chess* chess) {
//    m_chesses.push_back(chess);
//    if (pos_map.find(chess->x()) != pos_map.end() &&
//        pos_map[chess->x()].find(chess->y()) != pos_map[chess->x()].end()) {
//        int index = pos_map[chess->x()][chess->y()];
//        state[index] = true;
//    }
//}
void Board::addChess(Chess* chess) {

    state.push_back(0);
    m_chesses.push_back(chess);
}

void Board::hashIndex() {
    int size = m_chesses.size();
    for (int i = 0; i < size; i++)
    {
        pos_map[m_chesses[i]->x()][m_chesses[i]->y()] = i;
    }
}


void Board::buildadj() {
    adj.resize(m_chesses.size());
    for (int i = 0; i < m_chesses.size(); i++)
    {
        int x = m_chesses[i]->x();
        int y = m_chesses[i]->y();
        for (int j = 0; j < 6; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (pos_map.count(nx) && pos_map[nx].count(ny))
            {
                int neighbor = pos_map[nx][ny];
                adj[i].push_back(neighbor);         //��ѯ���Ӷ�  o(1)
            }
        }
    }
}


bool Board::isMoveChess(Chess* chess, ExMessage& msg) {
    findSingleJumpMove(chess);
    getJumpMove(chess);
    int x = NULL;
    int y = NULL;
    if (isHereAChess(msg)) {
        x = isHereAChess(msg)->x();
        y = isHereAChess(msg)->y();
    }
    for (auto& p : path) {
        if (p == pos_map[x][y])
            return true;
    }
    return false;
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
    int currentX = chess->x();
    int currentY = chess->y();
    for (int i = 0; i < 6; ++i) {
        int middleX = currentX + dx[i] * step;
        int middleY = currentY + dy[i] * step;
        int targetX = currentX + dx[i] * step * 2;
        int targetY = currentY + dy[i] * step * 2;

        int middleIndex = pos_map[middleX][middleY];
        int targetIndex = pos_map[targetX][targetY];
        if (state[middleIndex] && !state[targetIndex] && visited.find(targetIndex) == visited.end()) {
            path.push_back(targetIndex);
            visited.insert(targetIndex);
            if (step < 5) {
                findDoybleJumpMove(chess, step + 1);
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
    Chess* isHere = NULL;
    if (peekmessage(&msg, EX_MOUSE)) {
        if (msg.message == WM_LBUTTONDOWN) {
            for (std::vector<Chess*>::iterator it = m_chesses.begin(); it != m_chesses.end(); ++it) {
                int x = msg.x;
                int y = msg.y;
                Chess* chessPtr = *it;
                if (x < chessPtr->x() + 12 && x > chessPtr->x() - 12 && y < chessPtr->y() + 12 && y > chessPtr->y() - 12) {
                    Chess* isHere = chessPtr;
                }
            }
        }
    }
    return isHere;
}


bool Board::moveChess(Chess* chess) {
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

