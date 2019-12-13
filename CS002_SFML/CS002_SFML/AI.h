#pragma once
#include "Board.h"
#include "BoardScorer.h"
class AI
{
	BoardScorer mmBS;

public:
	Move AIturn(Board board);
	Move miniMax(Board board);

	int maxSearch(Board temp);
	int minSearch(Board temp);
};

