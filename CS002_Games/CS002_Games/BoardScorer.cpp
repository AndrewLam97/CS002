#include "BoardScorer.h"
#include "Board.h"

int BoardScorer::countVertical(Board board, int col, char piece)
{
	int verticalCount = 0;
	for (int i = 0; i < board.getROWS; i++)
	{
		int temp = 0;
		int j = i;
		while (board.getPiece(j, col) == piece)
		{
			temp++;
			j++;
		}
		if (temp > verticalCount)
			verticalCount = temp;
	}
	return verticalCount;
}

int BoardScorer::countHorizontal(Board board, int row, char piece)
{
	int horizontalCount = 0;
	for (int i = 0; i < board.getCOLS; i++)
	{
		int temp = 0;
		int j = i;
		while (board.getPiece(row,j) == piece)
		{
			temp++;
			j++;
		}
		if (temp > horizontalCount)
			horizontalCount = temp;
	}
	return horizontalCount;
}

int BoardScorer::countDiagonal(Board board, int startRow, int startCol, char piece)
{
	int rowOffset = startRow - startCol;
	int colOffset = startCol - startRow;

	int diagonalCount = 0;
	
	int temp = 0;

	for (int i = rowOffset; i < board.getROWS; i++)
	{
		int temp = i;
		int j = i - rowOffset;
		while(board.getPiece(temp, j) == piece)
		{
			i++; j++;
			temp++;
		}
	}
	if (temp > diagonalCount)
	{
		diagonalCount = temp;
	}
	return diagonalCount;
}

