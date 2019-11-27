#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Deck
{
private:
	char deck[4][13];

	int deckUnique = 0;
public:
	bool inDeck(int row, int col);
	bool deckFull();
	void setDeck(int row, int col);

	void dealCards();

	string getSuit(int row);
	string getCardValue(int col);

	void test();

	Deck();
};


