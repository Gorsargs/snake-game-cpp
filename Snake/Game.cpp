#include "Game.h"
#include <iostream>
#include "Controller.h"

Game::Game(sf::RenderWindow* window)
{
	board = new Board();
	snakePlayer = SnakePlayer(board);
	score = 0;
	myWindow = window;
	controller = Controller(&snakePlayer, board);
}

void Game::update()
{
	myWindow->clear();
	controller.update();
	checkFood();
	snakePlayer.moveSnake();
	draw();
	drawSnake();
	drawFood();
	myWindow->display();
}

void Game::updateEvents(sf::Event event)
{
	controller.listen(event);
}

Game::~Game()
{
	delete board;
}

void Game::drawRectangle(int x, int y, sf::Color fillColor, sf::Color outlineColor)
{
	sf::RectangleShape rectangle(sf::Vector2f(20, 20));
	rectangle.setPosition(1 + x*20.0f,1 + y*20.0f);
	rectangle.setFillColor(fillColor);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(1);
	myWindow->draw(rectangle);
}

void Game::drawSnake()
{
	for (size_t i = 0; i < snakePlayer.body.size(); i++)
	{
		myPosStruct pos = snakePlayer.body[i];
		drawRectangle(pos.x, pos.y, sf::Color::Cyan, sf::Color::Cyan);
	}
}

void  Game::checkLose()
{

}

void Game::checkFood()
{
	myPosStruct snakeHead = snakePlayer.body[snakePlayer.body.size() - 1];
	

	if (snakeHead.y == food.y && snakeHead.x == food.x)
	{
		snakePlayer.Eat(food);
		spawnFood();
	}
}

void Game::spawnFood()
{
	srand(time(0));
	int randX = (rand() % (board->ROW - 1));
	int randY = (rand() % (board->COL - 1));

	food.x = randX;
	food.y = randY;
}

void Game::drawFood()
{
	drawRectangle(food.x, food.y, sf::Color::Magenta, sf::Color::Magenta);
}

void Game::draw()
{
	for (int y = 0; y < board->ROW; y++)
	{
		for (int x = 0; x < board->COL; x++)
		{
			drawRectangle(x, y, sf::Color::Transparent, sf::Color::Cyan);
		}
	}
}
