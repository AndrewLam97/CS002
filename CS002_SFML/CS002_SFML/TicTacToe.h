#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class TicTacToe
{
protected:
private:
	std::vector<std::vector<Tile>> tileVec;
	std::vector<std::vector<sf::Sprite>> spriteVec;
	Tile tile; //test tile

	sf::RectangleShape squares[9], left, right;
	sf::RenderWindow window;

	sf::Texture texture;
public:
	void init();

	void drawBoard();
	void drawTiles();
	void drawSprites();
	TicTacToe();
};

