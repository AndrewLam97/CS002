// CS002_ 99Bottles.cpp

#include <iostream>
using namespace std;

string convIntString(int x)
{
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

string stringNum(int x)
{

}

int main()
{
	int entry = 0;

	cout << "Enter starting number of bottles: ";
	cin >> entry;

	cout << convIntString(entry) << endl;
}
