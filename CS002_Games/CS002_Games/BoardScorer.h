#pragma once
class BoardScorer
{
private:
public:
	int countVertical(Board board, int col, char piece, int max);
	int countHorizontal(Board board, int row, char piece, int max);
	int countDiagonal(Board board, int col, char piece, int max);

};

