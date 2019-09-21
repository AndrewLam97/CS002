/* CS002_Assignment2
 * Andrew Lam
 * Purpose: High/Low Guessing Game
 * Constraints: 10 guesses, use switch
 */

#include <iostream>
using namespace std;
#include <ctime>

int * randNumsGen()
{
	srand((unsigned)time(NULL));

	int range = 10 + rand() % 10;
	static int randNums[3];
	int actualVal = rand() % 100;

	randNums[0] = actualVal - range;
	randNums[1] = actualVal;
	randNums[2] = actualVal + range;

	for (int i = 0; i < 3; i++) {
		cout << randNums[i] << endl;
	}
	return randNums;
}

char evalEntry(int entry, int actualVal)
{
	if (entry == actualVal)
	{
		return 'w';
	}
	else if (entry > actualVal)
	{
		return 'h';
	}
	else
	{
		return 'l';
	}
}

void highOrLow()
{

}

int main()
{
	randNumsGen();
}
