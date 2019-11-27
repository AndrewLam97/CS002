#include "Deck.h"

using namespace std;

bool Deck::inDeck(int row, int col)
{
	return deck[row][col] == 'X' ? false : true;
}

bool Deck::deckFull()
{
	return deckUnique == 52 ? true : false;
}

void Deck::setDeck(int row, int col)
{
	deck[row][col] = 'Y';
	deckUnique++;
}

void Deck::dealCards()
{
	int i = 1;
	srand(time(NULL));
	
	while (deckFull() == false)
	{
		int row = rand() % 4;
		int col = rand() % 13;
		if (inDeck(row, col) == false)
		{
			setDeck(row, col);
			cout << setw(2)<< i++ << " : " << getCardValue(col) << " of " << getSuit(row) << endl;
		}
	}
}

string Deck::getSuit(int row)
{
	string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
	return suits[row];
}

string Deck::getCardValue(int col)
{
	string values[13] = { "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" };
	return values[col];
}

/*
Test Print Func
*/
void Deck::test()
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

/*
Default constructor
*/
Deck::Deck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[i][j] = 'X';
		}
	}
}