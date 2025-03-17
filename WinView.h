#pragma once

/**
 * @file WinView.h
 * @brief 胜利结算画面
 *
 * 该文件定义了胜利结算画面的类 `WinView`，继承自 `GameState`。
 * 当游戏结束时，进入该状态以显示胜利信息，并提供返回主菜单或重新开始游戏的选项。
 *
 * @author 李明泽
 * @version 2.5.7
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	/**
	 * @brief 构造函数
	 *
	 * 初始化胜利结算画面，并传入状态机的引用以便后续状态切换。
	 *
	 * @param _self_ref 状态机的引用
	 * @author 李明泽
	 */
	WinView(StateMachine& _self_ref);


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * 根据鼠标点击位置或键盘输入字符，更新胜利结算画面的状态。
	 * 例如，处理玩家点击“返回主菜单”或“重新开始”按钮的逻辑。
	 *
	 * @param msg 输入信息，包括鼠标点击位置或键盘输入字符
	 * @author 李明泽
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 *
	 * 绘制胜利结算画面，包括胜利信息、玩家得分、返回主菜单按钮等。
	 *
	 * @author 李明泽
	 */
	virtual void render();


	/**
	 * @brief 进入该状态
	 *
	 * 当切换到胜利结算画面时调用，初始化玩家信息和胜利条件。
	 * 例如，加载玩家名称、颜色和得分等信息。
	 *
	 * @author 李明泽
	 */
	virtual void enter();

private:

	std::vector<std::string> _names; // 存储玩家名称
	std::vector<std::string> _colors; // 存储玩家颜色

};