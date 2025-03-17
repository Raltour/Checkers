/**
 * @file Board.cpp
 * @brief Board函数的实现
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


//// 建立邻接表，存入六个方向的邻节点，然后通过哈希表查找索引，存入矩阵
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

// 建立邻接表，存入六个方向的邻节点，然后通过哈希表查找索引，存入矩阵
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


// 找到相邻的跳跃节点，遍历邻接表得到，存入path路径数组
void Board::findSingleJumpMove(Chess* chess) {
    int currentIndex = pos_map[chess->x()][chess->y()];
    for (auto neighborIndex : adj[currentIndex]) {
        if (!state[neighborIndex]) {
            path.push_back(neighborIndex);
        }
    }
}


// 找到隔子跳跃和连续跳跃，同时使用路径数组存储，使用标记哈希表存储已访问的位置
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


// 方便DFS 递归搜索，直接循环maxStep次，调用findDoybleJumpMove
void Board::getJumpMove(Chess* chess) {
    visited.clear();  // 清理 visited
    path.clear();     // 清理 path
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
    // 其他颜色的胜利条件
    return false;
}

