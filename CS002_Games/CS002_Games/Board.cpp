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
		for (int j = 0; j < COL_SIZE; j++)
		{
			cout << " " << board[i][j];
			if (j != COL_SIZE - 1)
			{
				cout << " |";
			}
			
		}		
		cout << endl;
		if (i != ROW_SIZE - 1)
		{
			for (int j = 0; j < COL_SIZE+1; j++)
			{
				cout << "---";
			}
		}
		cout << endl;
	}
	/*for (int j = 0; j < COL_SIZE; j++)
	{
		cout << board[board.size() - 1][j] << "|";
	}*/
}

void Board::setROW_SIZE(int ROW_SIZE)
{
	this->ROW_SIZE = ROW_SIZE;
}

void Board::setCOL_SIZE(int COL_SIZE)
{
	this->COL_SIZE = COL_SIZE;
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