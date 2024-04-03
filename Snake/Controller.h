#pragma once
#include "SnakePlayer.h"
#include "Board.h"
#include "SFML/Graphics.hpp"
#include <queue>
#include <array>

class Controller
{
private:
	SnakePlayer* snake{};
	Board* board{};
	std::queue<sf::Keyboard::Key> eventQueue;
public:
	Controller(SnakePlayer* pSnake, Board* pBoard);
	Controller() = default;
	void update();
	void listen(sf::Event event);
};

