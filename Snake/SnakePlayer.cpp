#include "SnakePlayer.h"
#include <iostream>


void SnakePlayer::moveSnake()
{
	moveBodyToHead();
	moveHead();
	checkBorders();
}

SnakePlayer::SnakePlayer(Board* pBoard)
{
	body = {
		{0,0},{0,1},{0,2},{0,3}
	};
	board = pBoard;
}

void SnakePlayer::moveHead()
{
	body[body.size() - 1][0] = body[body.size() - 1][0] + (1 * dirY);
	body[body.size() - 1][1] = body[body.size() - 1][1] + (1 * dirX);
}

void SnakePlayer::moveBodyToHead()
{
	int headPos = body.size() - 1;
	for (size_t i = 0; i < headPos; i++)
	{
		body[i] = body[i + 1];
	}
}

void SnakePlayer::checkBorders()
{
	//teleports the snake's head to the opposite side if out of border
	std::vector<int> headPos = body[body.size() - 1];
	if (headPos[1] == board->ROW)
		body[body.size() - 1][1] = 0;
	if (headPos[1] < 0)
		body[body.size() - 1][1] = board->ROW - 1;
	if(headPos[0] == board->COL)
		body[body.size() - 1][0] = 0;
	if (headPos[0] < 0)
		body[body.size() - 1][0] = board->COL - 1;
}


