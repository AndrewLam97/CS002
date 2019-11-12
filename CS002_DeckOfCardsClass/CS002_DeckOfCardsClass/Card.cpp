#include "Card.h"
#include "Deck.h"
using namespace std;

string Card::toSuit(int row)
{
	return suits[row];
}

string Card::toValue(int col)
{
	return values[col];
}

void Card::randSuit(string& suit)
{
	int row = rand() % 4;

	suit = suits[row];
}

void Card::randValue(string& value)
{
	int col = rand() % 13;

	value = values[col];
}

void Card::setSuit(string cardSuit)
{
	suit = cardSuit;
}

void Card::setValue(string cardValue)
{
	value = cardValue;
}

string Card::getSuit()
{
	return suit;
}

string Card::getValue()
{
	return value;
}

Card::Card(string conSuit, string conValue)
{
	suit = conSuit;
	value = conValue;
}

Card::Card()
{
	randSuit(suit);
	randValue(value);
}	
