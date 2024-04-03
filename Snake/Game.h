#pragma once
#include <vector>
#include "Board.h"
#include "SFML/Graphics.hpp"
#include "SnakePlayer.h"
#include "Controller.h"

class Game
{
public:
	int score;
	Board* board;
	SnakePlayer snakePlayer;
	void update();
	void updateEvents(sf::Event event);
	void draw();
	myPosStruct food = { 3,3 };
	Game(sf::RenderWindow* window);
	~Game();
private:
	sf::RenderWindow *myWindow;
	Controller controller;
	void drawRectangle(int x, int y, sf::Color fillColor, sf::Color outlineColor);
	void drawSnake();
	void drawFood();
	void checkLose();
	void checkFood();
	void spawnFood();
};

