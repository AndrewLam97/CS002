#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Move {
	int row;
	int col;
	int player;
	int color;
};

class Board {
protected:
	vector<vector<char>> board;

	int ROWS;
	int COLS;
	char defaultChar;

	void init();
private:

public:
	void print();

	bool isValidMove(Move move);
	void addPiece(Move move);
	void removePiece(Move move);


	char getPiece(int row, int col);
	int getSize();

	void setROWS(int ROWS);
	void setCOLS(int COLS);


	Board();
	Board(int ROWS, int COLS, char defaultChar);
};
