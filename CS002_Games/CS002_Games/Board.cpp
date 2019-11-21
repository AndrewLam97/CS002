#include "Board.h"

Board::Board()
{
	ROWS = 3;
	COLS = 3;

	for (int i = 0; i < ROWS; i++)
	{
		board.push_back(vector<char>());
		for (int j = 0; j < COLS; j++)
		{
			board[i].push_back('\0');
		}
	}
}

Board::Board(int ROWS, int COLS, char defaultChar)
{
	vector<vector<char>> vec2(ROWS, vector<char>(COLS, defaultChar));
	board = vec2;
}

void Board::print()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << " " << board[i][j];
			if (j != COLS - 1) { cout << " |"; }
		}
		cout << endl;
		if (i != ROWS - 1)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << "--- ";
			}
		}
		cout << endl;
	}
}

void Board::setROWS(int ROWS)
{
	this->ROWS = ROWS;
}

void Board::setCOLS(int COLS)
{
	this->COLS = COLS;
}

//bool Board::isValidMove(Move move)
//{
//	
//}
//
//void Board::addPiece(Move move)
//{
//
//}