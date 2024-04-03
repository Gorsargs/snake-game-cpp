
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SnakePlayer.h"
#include "Game.h"
#include "chrono"

int main()
{
    sf::RenderWindow window(sf::VideoMode(802, 802), "SFML works!");
    Game game = Game(&window);
    window.setFramerateLimit(60);
    
    sf::Clock clock;
    float deltaTime = 0.0f;
    float updateInterval = 0.1f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            game.updateEvents(event);
        }
        deltaTime += clock.restart().asSeconds();
        if (deltaTime >= updateInterval) {
            deltaTime -= updateInterval;
            game.update();
        }
    }
    return 0;
}