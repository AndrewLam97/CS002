#pragma once
#include "Card.h"
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Deck
{
private:
	const int DECK_SIZE = 52;
	Card deck[52]; //initialize an array of card objects
	//vector<Card> deckV;

	int uniqueCards = 0; //unique counter
	int currentCard = 0; //current position for nextCard()
	char arr[4][13];
public:
	Card nextCard(); //returns next card based on int currentCard
	Card getCardAt(int index); //returns card at index
	
	bool inDeck(int suit, int card); //checks if card is in deck using arr[][]
	bool deckFull(); //checks if deck contains 52 unique cards
	void setDeck(int suit, int card); //sets arr[][]
	
	void shuffle(); //shuffles deck
	void dealCards(); //deals (prints) cards in deck

	Deck();
};

