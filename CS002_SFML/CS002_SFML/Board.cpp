#include "Board.h"

Board::Board()
{
	setROWS(3);
	setCOLS(3);
	setDefaultChar('\0');

	for (int i = 0; i < ROWS; i++)
	{
		board.push_back(vector<char>());
		for (int j = 0; j < COLS; j++)
		{
			board[i].push_back(defaultChar);
		}
	}
}

Board::Board(int ROWS, int COLS, char defaultChar)
{
	setDefaultChar(defaultChar);
	setROWS(ROWS);
	setCOLS(COLS);
	vector<vector<char>> vec2(ROWS, vector<char>(COLS, this->defaultChar));
	board = vec2;
}

void Board::print()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << " " << board[i][j];
			if (j != COLS - 1)
			{
				cout << " |";
			}
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

void Board::setDefaultChar(char defaultChar)
{
	this->defaultChar = defaultChar;
}

int Board::getROWS()
{
	return ROWS;
}

int Board::getCOLS()
{
	return COLS;
}

vector<vector<char>> Board::getBoard()
{
	return board;
}

bool Board::isValidMove(Move move)
{
	if (board[move.row][move.col] == '\0')
		return true;
	else return false;
}

void Board::addPiece(Move move)
{
	if (isValidMove(move))
	{
		board[move.row][move.col] = move.piece;
	}
}

void Board::removePiece(Move move)
{
	if (!isValidMove(move))
	{
		board[move.row][move.col] = defaultChar;
	}
}

char Board::getPiece(int row, int col)
{
	return board[row][col];
}
