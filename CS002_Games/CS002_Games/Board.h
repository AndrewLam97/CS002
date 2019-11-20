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

	int ROW_SIZE;
	int COL_SIZE;
	char defaultChar;

	void init();
private:

public:
	void print();

	bool addPiece(Move move);
	void removePiece(Move move);
	bool isValidMove(Move move);

	char getPiece(int row, int col);
	int getSize();

	void setROW_SIZE(int ROW_SIZE);
	void setCOL_SIZE(int COL_SIZE);


	Board();
	Board(int ROW_SIZE, int COL_SIZE, char defaultChar);
};
