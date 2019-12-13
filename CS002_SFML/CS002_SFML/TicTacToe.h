#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Board.h"
#include "BoardScorer.h"
#include "AI.h"

class TicTacToe
{
protected:
	int mode = 0, ROWS = 3, COLS = 3, WIN = 3, turn = 0;
	bool gameRunning = true, player = true;

	Board tttBoard; //initialize Board 
	BoardScorer tttBS; //initialize BoardScorer
	AI aiP; //initialize AI

	std::vector<std::vector<Tile>> tileVec;

	sf::RectangleShape left, right;
	sf::RenderWindow window;

	void draw();
	void drawTiles();

	void updateBoard(Board tttBoard);
	
	Move getClick();

	int gameState();

public:

	void init();

	TicTacToe();
};

