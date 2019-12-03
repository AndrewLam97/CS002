#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "SFML Demo");
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
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}

	return 0;
}