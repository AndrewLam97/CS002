#pragma once
#include <cstdlib>
#include "Board.h"

class BoardScorer
{
private:
public:
	int countVertical(Board board, int col, char piece);
	int countHorizontal(Board board, int row, char piece);
	int countDiagonal(Board board, int startRow, int startCol, char piece);
	int countDiagonalAlt(Board board, int startRow, int startCol, char piece);
};

