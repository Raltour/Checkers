#pragma once

/**
 * @file Board.h
 * @brief 棋盘数据设计以及操作函数
 * @author 杜云飞
 * @version 2.2
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


    ~Board();


    /*
        负责人: 
        功能: 添加棋子到棋盘中
        参数: 智能指针封装的棋子对象
        返回值: 无
    */
    void addChess(std::unique_ptr<Chess> chess);


    /*
        负责人: 
        功能: 检查棋盘位置的棋子
              遍历棋子列表，使用x与y坐标差值之和小于半径的平方
        参数: 坐标x，y
        返回值: 返回棋子对象的指针，失败返回nuiiltr
    */
    Chess* chessAt(ExMessage& msg);


    /*
        负责人:
        功能: 检查移动位置是否合法
              可以使用使用handleClick()判断

        参数: 棋子的指针   新的x，y坐标
        返回值: 能移动，则返回true；不能返回false
    */
    bool isMoveChess(Chess* chess, int newX, int newY);


    /*
        负责人:
        功能: 绘制三角形，
        同时使用addChess添加棋子，
        state 记录顶点的状态  例如空设置0
              根据不同的颜色设置不同的状态
        pos记录所有棋子的坐标

        参数: p_x,p_y 为起始坐标   n 表示画几层  c 表示三角形是正的还是倒的
        color颜色
        返回值：无返回值
    */
    void drawTriangle(int p_x, int p_y, const char c, int n, COLORREF color);


    /*
        负责人:
        功能: 绘制棋盘和棋子,可是使用4个4层的三角形组成外围，
        上下由9层的正三角，8层的倒三角组成，坐标已给出
        调用6个drawTriangle 函数
        参数: 无参数
        返回值：无返回值
    */
    void draw();


    /*
        负责人:
        功能: 遍历所有坐标，将坐标映射成索引
        例如pos_map[x][y] = i;
        参数: 无参数
        返回值：无返回值
    */
    void hashIndex();


    /*
        负责人:
        功能: 建立邻接表，存入六个方向的邻节点，
        然后通过哈希表查找索引，存入矩阵

        遍历所有顶点pos每个点加入dx dy，遍历六个方向
        然后通过哈希表快速查找相邻点的下标并存入
        参数: 无参数
        返回值：无返回值
    */
    void buildadj();


    /*
        负责人:
        功能: 用于查找棋盘的位置
            调用chessAt查找棋子
            使用哈希表查询下标
            记得先通过isHereAChess查询这个位置有没有棋子
        参数: 点击的坐标
        返回值：返回棋子的索引,失败返回-1
    */
    int handleClick(ExMessage& msg);


    /*
        负责人:
        功能: 找到相邻的跳跃节点，遍历邻接表得到
              存入path路径数组
        参数: 棋子的指针
        返回值：无
    */
    void findSingleJumpMove(Chess* chess);


    /*
        负责人:
        功能: 找到隔子跳跃和连续跳跃，同时使用路径数组存储，
        使用标记哈希表存储已访问的位置
            1.查找中间节点和跳跃的目标节点，中间节点+[dx,dy] * step
             目标节点+[dx,dy] * step * 2
            2.设置标记位置查找中间节点之前没有棋子(通过state)并且棋子存在(通过哈希表查询)，有true
               可以通过事件的逆事件直接返回false
            同时中间点存在
            中间节点到目标节点没有棋子(通过state)，没有棋子则true
            3.标记true
              检查visited，确保没有访问过
                如果哈希表中没有该节点
                   添加目标节点到path,visted
                然后再访问进行递归，最大幅度设为5
        参数: 棋子的指针，每次跳跃的步幅
        返回值：无
    */
    void findDoybleJumpMove(Chess* chess, int step);


    /*
        负责人:
        功能: 方便DFS 递归搜索
             直接循环maxStep次，调用findDoybleJumpMove
        参数: 棋子的指针
        返回值：无
    */
    void getJumpMove(Chess* chess);


	/**
	 * @brief 判断鼠标点击的位置是不是一个棋子
	 *
	 * 详细描述函数的功能、参数、返回值等信息。
	 *
	 * @param 鼠标信息
	 * @return 如果是一个棋子，则将指针返回；否则返回空即可
	 * @author 作者名字
	 */
	Chess* isHereAChess(ExMessage &msg);


	/**
	 * @brief 根据后续的鼠标输入，移动棋子
	 *
	 * 进行完所有的移动后，立刻检测这个棋子对应的玩家有没有胜利
	 * 通过向isChessWin传递该棋子的颜色进行判断
	 *
	 * @param 需要移动的棋子的地址
	 * @return 玩家是否胜利
	 * @author 作者名字
	 */
	bool moveChess(Chess *chess);//返回值：该玩家有没有取得胜利


    //loadimage 传入图片名 加载图片
    static std::unique_ptr<Board> create(std::string filename);


    /*
        负责人:
        功能: 输出图片背景
             先输出图片，否则棋盘会覆盖
        参数: 智能指针封装的棋子对象
        返回值: 无
    */
    void putImage();


private:

	std::vector<std::unique_ptr<Chess>> m_chesses;   //棋子数组
	std::unordered_map<int, std::unordered_map<int, int>> pos_map;   //存储索引的哈希表
	std::vector<std::vector<int>> adj;    //邻接表
	std::unordered_set<int> visited;      //标记已访问
	std::vector<int> path;      //路径
	std::vector<bool> state;    //状态

	const int m_width = 800;       //宽度 
	const int m_height = 600;      //高度      
	int m_cellSize = 30;           //棋盘格子大小
	COLORREF m_backgroundColor = WHITE;   // 棋盘背景颜色
	std::vector<int> dx = { 30, -30, 15, -15, 15, -15 }; // 方向向量
	std::vector<int> dy = { 0, 0, -30, -30, 30, 30 };
	const int OFFSET_X = 300;   //顶部和底部三角形的x坐标
	const int OFFSET_Y = 590;  //底部三角形的y坐标
	const int top_y = 110;    //顶部三角形的y坐标
	const int lt_x = 165;     //左上三角形的x坐标
	const int lt_y = 320;     //左上三角形的y坐标
	const int rt_x = 435;     //右上三角形的x坐标
	const int rt_y = 320;     //右上三角形的y坐标
	const int ld_x = 165;     //左下三角形的x坐标
	const int ld_y = 380;     //左下三角形的y坐标
	const int rd_x = 435;     //右下三角形的x坐标
	const int rd_y = 380;     //右下三角形的y坐标


    IMAGE bkimage;              // 加载的图片
    std::string m_filename;     //图片地址



	/**
	 * @brief 判断移动完成后有没有胜利
	 * 
     * 检查棋子是否全部到达对角区域，
     * 检查特定颜色的对应区域是否填满了对应的棋子
	 * 棋盘上的颜色分布是固定的，算出棋子应该去的位置
	 *
	 * @param 需要判断的棋子的颜色
	 * @return 玩家是否胜利
	 * @author 作者名字
	 */
	bool isChessWin(COLORREF color);
};