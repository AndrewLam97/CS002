#include "Card.h"
#include <iostream>
using namespace std;

string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
string values[13] = { "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" };

string Card::getSuit(int row)
{
	return suits[row];
}

string Card::getValue(int col)
{
	return values[col];
}

