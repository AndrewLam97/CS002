#include "BoardScorer.h"
#include "Board.h"
int BoardScorer::countAll(Board board, char piece)
{
	int max = 0;
	int temp = 0;
	for (int i = 0; i < board.getROWS(); i++)
	{
		temp = countHorizontal(board, i, piece);
		if (temp > max)
			max = temp;
	}
	for (int j = 0; j < board.getCOLS(); j++)
	{
		temp = countVertical(board, j, piece);
		if (temp > max)
			max = temp;
	}
	temp = countDiagonal(board, 0, 0, piece);
			if (temp > max)
				max = temp;
	temp = countDiagonalAlt(board, 0, 2, piece);
	if (temp > max)
		max = temp;
	return max;
}

bool BoardScorer::boardFull(Board board)
{
	bool isFull = true;
	bool used = false;
	if (board.getPiece(0, 0) != '\0') used = true;

	for (int i = 0; i < board.getROWS(); i++)
	{
		for (int j = 0; j < board.getCOLS(); j++)
		{
			if (used == true && board.getPiece(i, j) == '\0')
			{
				return false;
			}
		}
	}
	return isFull;
}


int BoardScorer::countVertical(Board board, int col, char piece)
{
	int verticalCount = 0, temp = 0;
	for (int i = 0; i < board.getROWS(); i++)
	{
		if (board.getPiece(i, col) != piece)
		{
			if (temp > verticalCount)
			{
				verticalCount = temp;
			}
			temp = 0;
		}
		else
			temp++;
	}
	if (temp > verticalCount)
		verticalCount = temp;
	return verticalCount;
}

int BoardScorer::countHorizontal(Board board, int row, char piece)
{
	int horizontalCount = 0, temp = 0;
	for (int i = 0; i < board.getCOLS(); i++)
	{
		if (board.getPiece(row, i) != piece)
		{
			if (temp > horizontalCount)
			{
				horizontalCount = temp;
			}
			temp = 0;
		}
		else
			temp++;
	}
	if (temp > horizontalCount)
		horizontalCount = temp;
	return horizontalCount;
}

int BoardScorer::countDiagonal(Board board, int startRow, int startCol, char piece)
{
	int rowOffset = startRow - startCol;
	int diagonalCount = 0;
	int temp = 0;

	int i = rowOffset;
	int j = 0;

	if (rowOffset < 0)
	{
		i = 0;
		j = abs(rowOffset);
	}
	while (i < board.getROWS() && j < board.getCOLS())
	{
		if (board.getPiece(i, j) != piece)
		{
			if (temp > diagonalCount)
			{
				diagonalCount = temp;
			}
			temp = 0;
		}
		else
			temp++;
		i++;
		j++;
	}
	if (temp > diagonalCount)
		diagonalCount = temp;

	return diagonalCount;
}

int BoardScorer::countDiagonalAlt(Board board, int startRow, int startCol, char piece)
{
	//int colOffset = startCol - startRow;
	int diagonalCount = 0;
	int temp = 0;

	int i = 0;
	int j = startRow + startCol;

	if (j > board.getCOLS() - 1)
	{
		i = j - 9;
		j = board.getCOLS() - 1;
	}
	while (i < board.getROWS() && j >= 0)
	{
		if (board.getPiece(i, j) != piece)
		{
			if (temp > diagonalCount)
			{
				diagonalCount = temp;
			}
			temp = 0;
		}
		else
			temp++;
		i++;
		j--;
	}
	if (temp > diagonalCount)
		diagonalCount = temp;
	return diagonalCount;
}