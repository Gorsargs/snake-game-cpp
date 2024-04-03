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
	snakePlayer.moveSnake();
	draw();
	drawSnake();
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
	rectangle.setPosition(1 + x*20,1 + y*20);
	rectangle.setFillColor(fillColor);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(1);
	myWindow->draw(rectangle);
}

void Game::drawSnake()
{
	for (size_t i = 0; i < snakePlayer.body.size(); i++)
	{
		std::vector<int> pos = snakePlayer.body[i];
		drawRectangle(pos[1], pos[0], sf::Color::Cyan, sf::Color::Cyan);
	}
}

void Game::draw()
{
	for (size_t y = 0; y < board->ROW; y++)
	{
		for (size_t x = 0; x < board->COL; x++)
		{
			drawRectangle(x, y, sf::Color::Transparent, sf::Color::Cyan);
		}
	}
}
