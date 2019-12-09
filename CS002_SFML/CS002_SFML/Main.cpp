#include <iostream>
#include <SFML/Graphics.hpp>
#include "TicTacToeTest.h"
using namespace std;

int main()
{
	test_fnc();
	/*sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "SFML Demo");
	sf::Texture texture;
	
	if (!texture.loadFromFile("csgo1.png"))
	{
		return -1;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Vector2u winSize = window.getSize();
	sf::Rect<float> spriteSize = sprite.getGlobalBounds();
	sprite.setPosition(winSize.x / 2 - spriteSize.width / 2, winSize.y / 2 - spriteSize.height / 2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sprite.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sprite.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sprite.move(0, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			sprite.move(0, -1);
		}
		
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}

	return 0;*/
}