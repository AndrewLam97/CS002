#include "Tile.h"
void Tile::setTile(char value)
{
	if (value == 'x')
	{
		std::string xStr = "ttt_x.jpg";
		if (!texture.loadFromFile(xStr))
		{
			std::cout << "Error loading: " << xStr << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setScale(0.469, 0.469);
	}
}

void Tile::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}

Tile::Tile()
{
	sf::Sprite sprite;

	sprite.setColor(sf::Color::White);
}