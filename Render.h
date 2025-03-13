#pragma once

/**
 * @file Render.h
 * @brief 绘制游戏中的各种图形，以及easyx图形库中的消息传递功能
 * 
 * 包括用来与玩家交互的按钮，
 * 以及所有游戏状态下的render函数，也在这里实现
 * 这个文件不要包含具体实现，都写在.cpp文件里
 * 
 * 每一个绘制界面的函数要包括背景、所有元素
 * （包括但不限于棋子、按钮、各种信息）
 * 所有绘制（即游戏刷新新的一帧）都封装在各个界面的draw***函数中
 * 
 * @author 张三
 * @version 2.0
 */

#include <easyx.h>


 /**
  * @brief 绘制六边形网格
  *
  * 详细描述函数的功能、参数、返回值等信息。
  *
  * @param 参数1 描述参数1的作用
  * @param 参数2 描述参数2的作用
  * @author 作者名字
  */
void drawHexagonGrid();


/**
 * @brief 绘制棋子
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawChesses();


/**
 * @brief 绘制棋盘网格和棋子,调用网格和棋子绘制函数
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void draw();


/**
 * @brief 
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */
void drawStartMenu();


 /**
  * @brief 
  *
  * 详细描述函数的功能、参数、返回值等信息。
  *
  * @param 参数1 描述参数1的作用
  * @param 参数2 描述参数2的作用
  * @return 返回值的描述
  * @author 作者名字
  */
void drawPlayerNum();


  /**
   * @brief 
   *
   * 详细描述函数的功能、参数、返回值等信息。
   *
   * @param 参数1 描述参数1的作用
   * @param 参数2 描述参数2的作用
   * @return 返回值的描述
   * @author 作者名字
   */
void drawPlayerInfo();



   /**
	* @brief 
	*
	* 详细描述函数的功能、参数、返回值等信息。
	*
	* @param 参数1 描述参数1的作用
	* @param 参数2 描述参数2的作用
	* @return 返回值的描述
	* @author 作者名字
	*/
void drawChechersGame();


	/**
	 * @brief 
	 *
	 * 详细描述函数的功能、参数、返回值等信息。
	 *
	 * @param 参数1 描述参数1的作用
	 * @param 参数2 描述参数2的作用
	 * @return 返回值的描述
	 * @author 作者名字
	 */
void drawWinView();


