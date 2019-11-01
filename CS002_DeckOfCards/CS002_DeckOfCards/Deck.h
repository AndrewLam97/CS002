#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Deck
{
private:
	string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
	string values[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	const int ROW_SIZE = 4;
	const int COL_SIZE = 13;

	char deck[4][13];
public:
	int deckUnique = 0;
	int setFail = 0;

	bool inDeck(int row, int col);
	bool deckFull();
	void setDeck(int row, int col);

	void print();

	Deck();
};


