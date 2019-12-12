#include "AI.h"

Move AI::AIturn(Board board)
{
	for (int i = 0; i < board.getROWS(); i++)
	{
		for (int j = 0; j < board.getCOLS(); j++)
		{
			Move move = { i,j,'o' };
			if (board.isValidMove(move))
			{
				return move;
			}
		}
	}
}