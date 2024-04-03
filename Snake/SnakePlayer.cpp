#include "SnakePlayer.h"


void SnakePlayer::moveSnake()
{
	moveBodyToHead();
	moveHead();
	checkBorders();
}

SnakePlayer::SnakePlayer(Board* pBoard)
{
	body = {
		{1,0},{2,0},{3,0},{4,0}
	};
	board = pBoard;
}

void SnakePlayer::Eat(myPosStruct pos)
{
	body.push_back(pos);
}

void SnakePlayer::moveHead()
{
	body[body.size() - 1].x = body[body.size() - 1].x + (1 * dirX);
	body[body.size() - 1].y = body[body.size() - 1].y + (1 * dirY);
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
	myPosStruct headPos = body[body.size() - 1];
	if (headPos.y == board->COL)
		body[body.size() - 1].y = 0;
	if (headPos.y < 0)
		body[body.size() - 1].y = board->COL - 1;
	if(headPos.x == board->ROW)
		body[body.size() - 1].x = 0;
	if (headPos.x < 0)
		body[body.size() - 1].x = board->ROW - 1;
}


