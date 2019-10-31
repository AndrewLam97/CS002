#include "Deck.h"

#include <iostream>
#include <iomanip>

bool Deck::inDeck(int row, int col)
{
	deck[row][col];
}
bool Deck::deckFull()
{
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (deck[i][j] == 'x')
			{
				return false;
			}
		}
	}return true;*/

	if (deckUnique == 52)return true;
}

void Deck::setDeck(int row, int col)
{
	if (deck[row][col] = 'X')
	{
		deck[row][col] = 'Y';
		deckUnique++;
	}
	else setFail++;
}

void Deck::print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << setw(2) << deck[i][j];
		}
		cout << endl;
	}
}

Deck::Deck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i][j] = 'x';
		}
	}
}