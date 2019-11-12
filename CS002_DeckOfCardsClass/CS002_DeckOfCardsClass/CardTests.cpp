#include "CardTests.h"
#include "Card.h"
#include "Deck.h"

void testFnc()
{
	//testCardCon();
	//testDeckCon();
	testDeckShuffle();
}

void testCardCon()
{
	cout << "Testing contstructors" << endl;
	string testSuit = "potato", testValue = "123";
	Card card(testSuit, testValue);
	cout << card.getSuit() << " " << card.getValue() << endl;

	srand(time(NULL));
	Card card1;
	cout << card1.getSuit() << " " << card1.getValue() << endl;
	Card card2;
	cout << card2.getSuit() << " " << card2.getValue() << endl;
}

void testDeckCon()
{
	cout << "Testing Deck constructor" << endl;
	Deck deck;
	deck.dealCards();
}

void testDeckShuffle()
{
	Deck deck;
	deck.dealCards();
	deck.shuffle();
	cout << endl;
	deck.dealCards();
}
	
