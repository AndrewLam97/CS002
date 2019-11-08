#pragma once
#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
	string suits;
	string values;
public:
	string getSuit(int row);
	string getValue(int col);

	void setSuit(string suit);
	void setValue(string value);

	//constructors
	Card(string suit, string value);
	Card();
};

