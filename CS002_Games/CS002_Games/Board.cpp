#include "Board.h"

Board::Board()
{
	ROW_SIZE = 3;
	COL_SIZE = 3;

	for (int i = 0; i < ROW_SIZE; i++)
	{
		board.push_back(vector<char>());
		for (int j = 0; j < COL_SIZE; j++)
		{
			board[i].push_back('\0');
		}
	}
}

Board::Board(int ROW_SIZE, int COL_SIZE, char defaultChar)
{
	vector<vector<char>> vec2(ROW_SIZE, vector<char>(COL_SIZE, defaultChar));
	board = vec2;
}

void Board::print()
{
	for (int i = 0; i < ROW_SIZE; i++)
	{
		cout << endl;
		for (int j = 0; j < COL_SIZE; j++)
		{
			cout << board[i][j] << " ";
		}
	}
}

void Board::setROW_SIZE(int ROW_SIZE)
{
	this->ROW_SIZE = ROW_SIZE;
}
void Board::setCOL_SIZE(int COL_SIZE)
{
	this->COL_SIZE = COL_SIZE;
}