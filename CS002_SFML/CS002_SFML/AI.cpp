#include "AI.h"

Move AI::AIturn(Board board)
{
	return miniMax(board);
}

Move AI::miniMax(Board board)
{
	int maxScore = 0;
	Move bestMove;
	for (int i = 0; i < board.getROWS(); i++)
	{
		for (int j = 0; j < board.getCOLS(); j++)
		{
			Board temp = board;
			Move move = { i, j, 'o' };
			if (board.isValidMove(move))
			{
				temp.addPiece(move);
				int tempScore = maxSearch(temp);
				if (tempScore == 100)
				{
					return bestMove = { i,j,'o' };
				}
				else
					bestMove = move;
			}
			temp = board;
			move = { i,j,'x' };
			if (board.isValidMove(move))
			{
				temp.addPiece(move);
				int tempScore = minSearch(temp);
				if (tempScore == -100)
				{
					return bestMove = { i,j,'o' };
				}
			}
		}
	}
	return bestMove;
}

int AI::maxSearch(Board temp)
{
	int score = mmBS.countAll(temp, 'o');
	if (score == 3) { return 100; }
	if (score == 2 || score == 1) { return 0; }
}

int AI::minSearch(Board temp)
{
	int score = mmBS.countAll(temp, 'x');
	if (score == 3) { return -100; }
	if (score == 2 || score == 1) { return 0; }
}