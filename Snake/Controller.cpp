#include "Controller.h"
#include <iostream>

Controller::Controller(SnakePlayer* pSnake, Board *pBoard)
{
	snake = pSnake;
	board = pBoard;
}

void Controller::listen(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Left:
		case sf::Keyboard::Right:
		case sf::Keyboard::Up:
		case sf::Keyboard::Down:
			eventQueue.push(event.key.code);
			break;
		}
	}
}

void Controller::update()
{
	if (eventQueue.size() < 1)
		return;
	sf::Keyboard::Key keyCode = eventQueue.front();
	if (keyCode == sf::Keyboard::Right)
	{
		if (snake->dirX == 0) {
			snake->dirX = 1;
			snake->dirY = 0;
		}
	}
	if (keyCode == sf::Keyboard::Left)
	{
		if(snake->dirX == 0)
		{
			snake->dirX = -1;
			snake->dirY = 0;
		}
	}
	if (keyCode == sf::Keyboard::Up)
	{
		if (snake->dirY == 0)
		{
			snake->dirY = -1;
			snake->dirX = 0;
		}
	}
	if (keyCode == sf::Keyboard::Down)
	{
		if (snake->dirY == 0)
		{
			snake->dirY = 1;
			snake->dirX = 0;
		}
	}
	eventQueue.pop();
}
