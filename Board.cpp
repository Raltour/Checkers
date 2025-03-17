/**
 * @file Board.cpp
 * @brief Board������ʵ��
 * @author 
 * @version 2.5.6
 */

#include "Board.h"


Board::Board() {
    adj.resize(m_width * m_height / (m_cellSize * m_cellSize));
    state.resize(m_width * m_height / (m_cellSize * m_cellSize), false);
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
    if (pos_map.find(chess->x()) != pos_map.end() &&
        pos_map[chess->x()].find(chess->y()) != pos_map[chess->x()].end()) {
        int index = pos_map[chess->x()][chess->y()];
        state[index] = true;
    }
}


void Board::hashIndex() {
    int index = 0;
    for (int x = 0; x < m_width; x += m_cellSize) {
        for (int y = 0; y < m_height; y += m_cellSize) {
            pos_map[x][y] = index++;
        }
    }
}


//// �����ڽӱ���������������ڽڵ㣬Ȼ��ͨ����ϣ������������������
//void Board::buildadj() {
//    for (int x = 0; x < m_width; x += m_cellSize) {
//        for (int y = 0; y < m_height; y += m_cellSize) {
//            int currentIndex = pos_map[x][y];
//            for (int i = 0; i < 6; ++i) {
//                int newX = x + dx[i];
//                int newY = y + dy[i];
//                if (isPositionInBoard(newX, newY)) {
//                    int neighborIndex = pos_map[newX][newY];
//                    adj[currentIndex].push_back(neighborIndex);
//                }
//            }
//        }
//    }
//}

// �����ڽӱ���������������ڽڵ㣬Ȼ��ͨ����ϣ������������������
void Board::buildadj() {
    for (int x = 0; x < m_width; x += m_cellSize) {
        for (int y = 0; y < m_height; y += m_cellSize) {
            int currentIndex = pos_map[x][y];
            for (int i = 0; i < 6; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                int neighborIndex = pos_map[newX][newY];
                adj[currentIndex].push_back(neighborIndex);
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

