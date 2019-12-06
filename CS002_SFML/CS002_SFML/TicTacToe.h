#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class TicTacToe
{
protected:
private:
	std::vector<std::vector<Tile>> tileVec;
	//std::vector<std::vector<sf::Sprite>> spriteVec;

	sf::RectangleShape left, right;
	sf::RenderWindow window;

	void drawBoard();
	void drawTiles();
	//void drawSprites();
public:
	void init();

	TicTacToe();
};

