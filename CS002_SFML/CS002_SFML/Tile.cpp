#include "Tile.h"
void Tile::setTile(char value)
{
	if (value == 'x')
	{
		std::string xStr = "x.png";
		if (!texture.loadFromFile(xStr))
		{
			std::cout << "Error loading: " << xStr << std::endl;
		}
		sprite.setTexture(texture, true);
		texture.setSmooth(true);
		sprite.setScale(0.283, 0.283); //1080p
	}
	if (value == 'o')
	{
		std::string oStr = "o.png";
		if (!texture.loadFromFile(oStr))
		{
			std::cout << "Error loading: " << oStr << std::endl;
		}
		sprite.setTexture(texture, true);
		texture.setSmooth(true);
		sprite.setScale(0.566, 0.566); //1080p
	}
	if (value == 'b')
	{
		std::string bStr = "blank.png";
		if (!texture.loadFromFile(bStr))
		{
			std::cout << "Error loading: " << bStr << std::endl;
		}
		sprite.setTexture(texture);
		sprite.setScale(0.664, 0.664); //1080p
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
	setTile('b');
}