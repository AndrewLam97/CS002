#pragma once
class Deck
{
private:
	Card deck[52];
	const int DECK_SIZE = 52;
	int uniqueCards = 0;
	char arr[4][13];
public:
	Card nextCard();
	Card getCardAt();

	void sort();
	bool inDeck(int suit, int card);
	bool deckFull();
	void setDeck(int suit, int card);
	void shuffle();
	void dealCards();

	Deck();
};

