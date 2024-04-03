#pragma once
#include <vector>
#include "Board.h"
class SnakePlayer
{
public:
	std::vector<std::vector<int>> body;
	void moveSnake();
	int dirX = 1;
	int dirY = 0;
	SnakePlayer(Board* pBoard);
	SnakePlayer() = default;
private:
	Board* board;
	void moveHead();
	void moveBodyToHead();
	void checkBorders();
};

