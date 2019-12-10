#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Board.h"
#include "BoardScorer.h"

class TicTacToe
{
protected:
private:
	int ROWS = 3, COLS = 3, WIN = 3, turn = 0;
	bool gameRunning = true, player = true;

	sf::Font font;
	sf::Text text;

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
	
	Move getClick();

	int gameState();

public:

	void init();

	TicTacToe();
};

