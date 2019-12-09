#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Move {
	int row;
	int col;
	char piece;
	int player;
	int color;
};

class Board {
protected:
	vector<vector<char>> board;

	int ROWS;
	int COLS;
	char defaultChar;

private:

public:
	void print();

	bool isValidMove(Move move);
	void addPiece(Move move);
	void removePiece(Move move);

	char getPiece(int row, int col);

	void setROWS(int ROWS);
	void setCOLS(int COLS);
	void setDefaultChar(char defaultchar);

	int getROWS();
	int getCOLS();
	vector<vector<char>> getBoard();

	Board();
	Board(int ROWS, int COLS, char defaultChar);
};
