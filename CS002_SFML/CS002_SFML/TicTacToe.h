#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Board.h"
#include "BoardScorer.h"

class TicTacToe
{
protected:
private:
	int ROWS = 3, COLS = 3;

	Board tttBoard; //initialize Board 
	BoardScorer tttBS; //initialize BoardScorer

	std::vector<std::vector<Tile>> tileVec;

	sf::RectangleShape left, right;
	sf::RenderWindow window;

	void drawBoard();
	void drawTiles();

	//Move playerMove();
	//Move computerMove();
	void updateBoard(Board tttBoard);

public:

	void init();

	TicTacToe();
};

