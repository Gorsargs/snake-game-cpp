#pragma once
#include <vector>
#include "Board.h"

struct myPosStruct
{
	int x; int y;
};

class SnakePlayer
{
public:
	std::vector<myPosStruct> body;
	void moveSnake();
	int dirX = 1;
	int dirY = 0;
	SnakePlayer(Board* pBoard);
	SnakePlayer() = default;
	void Eat(myPosStruct);
	;
private:
	Board* board{};
	void moveHead();
	void moveBodyToHead();
	void checkBorders();
};

