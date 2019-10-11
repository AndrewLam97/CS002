// CS002_ 99Bottles.cpp

#include <iostream>
#include <string>
using namespace std;

struct Number
{
	int tens;
	int ones;
};

/*
PURPOSE: changes an integer into its equivalent string form
PARAMETERS: integer x
RETURN VALUES: string containing number written out in letters
*/
string convIntString(int x)
{
	if (x == 0)
		return "zero";
	if (x == 1)
		return "one";
	if (x == 2)
		return "two";
	if (x == 3)
		return "three";
	if (x == 4)
		return "four";
	if (x == 5)
		return "five";
	if (x == 6)
		return "six";
	if (x == 7)
		return "seven";
	if (x == 8)
		return "eight";
	if (x == 9)
		return "nine";
	if (x == 10)
		return "ten";
	if (x == 11)
		return "eleven";
	if (x == 12)
		return "twelve";
	if (x == 13)
		return "thirteen";
	if (x == 14)
		return "fourteen";
	if (x == 15)
		return "fifteen";
	if (x == 16)
		return "sixteen";
	if (x == 17)
		return "seventeen";
	if (x == 18)
		return "eighteen";
	if (x == 19)
		return "nineteen";
	if (x == 20)
		return "twenty";
	if (x == 30)
		return "thirty";
	if (x == 40)
		return "fourty";
	if (x == 50)
		return "fifty";
	if (x == 60)
		return "sixty";
	if (x == 70)
		return "seventy";
	if (x == 80)
		return "eighty";
	if (x == 90)
		return "ninety";
}
/*
PURPOSE: takes a number and returns a string containing the written out number
PARAMETERS: int entryNum
RETURN VALUES: string stringNumber
*/
string stringNum(int entryNum)
{
	string stringNumber = "";
	Number entryNumber = { entryNum / 10, entryNum % 10 };

	if (entryNumber.tens > 1)
	{
		stringNumber += convIntString(entryNumber.tens * 10);
		if (entryNumber.ones != 0)
		{
			stringNumber += "-" + convIntString(entryNumber.ones);
		}
	}
	else
	{
		stringNumber += convIntString(entryNum);
	}
	return stringNumber;
}

void printSong(int x)
{
	for (x; x > 0; x--)//loops from given starting number until 0
	{
		if (x > 1)
		{
			cout << endl << stringNum(x) << " bottles of beer on the wall, " << endl << stringNum(x) << " bottles of beer,"
				<< endl << "Take one down, pass it around," << endl << stringNum(x - 1) << " bottles of beer on the wall." << endl;
		}
		else //handles last bottle
		{
			cout << endl << stringNum(x) << " bottle of beer on the wall, " << endl << stringNum(x) << " bottle of beer,"
				<< endl << "Take one down, pass it around," << endl << stringNum(x - 1) << " bottles of beer on the wall." << endl;
		}
	}
}

int main()
{
	string entry = "";

	cout << "Enter starting number of bottles: ";
	cin >> entry;

	int entryNum = stoi(entry);

	printSong(entryNum);


}
