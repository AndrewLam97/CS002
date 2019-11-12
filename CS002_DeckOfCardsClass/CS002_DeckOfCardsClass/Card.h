#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Card
{
private:
	string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
	string values[13] = { "King", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen" };

	string suit;
	string value;
public:
	string toSuit(int row); //converts integer row to its string representation in suits
	string toValue(int col); //converts integer col to its string representation in values

	void randSuit(string& suit); //sets card's suit to random suit
	void randValue(string& value); //sets card's value to random value
	
	string getSuit(); //returns card's suit
	string getValue(); //returns card's value

	void setSuit(string cardSuit); //sets card's suit to cardSuit
	void setValue(string cardValue); //sets card's value to cardValue

	//constructors
	Card(string suit, string value); //Construct card with predetermined values
	Card(); //Construct card with randomized values
};

