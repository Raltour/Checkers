/**
 * @file Board.cpp
 * @brief Board函数的实现
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

    //上
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

    //下
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

    //左上
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

    //右下
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

    //左下
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

    //还没建好
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


// 建立邻接表，存入六个方向的邻节点，然后通过哈希表查找索引，存入矩阵
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
                adj[i].push_back(neighbor);         //查询复杂度  o(1)
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
                //true 表示玩家棋子
                for (auto& p : path)
                {
                    if (p == pos_map[x][y])
                    {
                        //恢复颜色
                        chess->recoveryColor();

                        m_chesses[pos_map[x][y]]->changeChess(chess->color());
                        
                        //移动后原来棋子的状态
                        state[pos_map[chess->x()][chess->y()]] = false;
                       
                       
                        m_chesses[pos_map[chess->x()][chess->y()]]->changeChess(WHITE);
                        //棋子移动到位置
                        state[p] = true;

                        //更新
                        cleardevice();
                        //std::cout << "wwww" << std::endl;
                        drawChechersGame(*this);
                        hashIndex();   // 更新坐标索引
                        buildadj();    // 更新邻接表
                        //drawChechersGame(*this);
                        return true;
                    }

                }
            }

        return false;
    }
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
        // 检查中间节点是否存在且有棋子
        if (isChess && pos_map.count(mid_x) && pos_map[mid_x].count(mid_y)) {
            int midPos = pos_map[mid_x][mid_y];
            if (state[midPos] != 0) { // 中间节点有棋子
                // 检查目标节点是否存在且为空
                if (pos_map.count(target_x) && pos_map[target_x].count(target_y)) {
                    int targetPos = pos_map[target_x][target_y];
                    if (state[targetPos] == 0 && visited.count(targetPos) == 0) { // 目标节点为空且未访问
                        // 添加目标节点到路径
                        path.push_back(targetPos);
                        visited.insert(targetPos);
                        // 递归检查是否可以进一步跳跃
                        for (int i = 1; i <= 5; i++)
                            findDoybleJumpMove(m_chesses[targetPos], i); // 从步长1开始递归
                    }
                }
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
    // 其他颜色的胜利条件
    return false;
}

