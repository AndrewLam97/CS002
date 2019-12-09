#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Tile
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2u winSize;
public:
	void setTile(char value);
	void setPos(float x, float y);

	sf::Sprite getSprite();

	Tile();
};

