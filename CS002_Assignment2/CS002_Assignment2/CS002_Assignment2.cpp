/* CS002_Assignment2
 * Andrew Lam
 * Purpose: High/Low Guessing Game
 * Constraints: 10 guesses
 */

#include <iostream>
using namespace std;
#include <ctime>

int* randNumsGen(int actualVal)
{
	static int randNums[3];
	//introduce pseudo-random variance to expand range around given value
	randNums[0] = actualVal - (rand() % 15) - (rand() % 17);
	randNums[1] = actualVal;
	randNums[2] = actualVal + (rand() % 15) + (rand() % 17);

	return randNums;
}

bool evalEntry(int entry, int actualVal)
{
	if (entry == actualVal)
	{
		cout << endl << "You got the correct answer!" << endl;
		return true;
	}
	else if (entry > actualVal)
	{
		cout << endl << "Your guess is too high, guess lower." << endl;
		return false;
	}
	else
	{
		cout << endl << "Your guess is too low, guess higher." << endl;
		return false;
	}
}

int main()
{
	int entry = 0, guesses = 10;
	srand((unsigned)time(NULL)); // set seed for rand
	int actualVal = rand() % 100; //set computer's value

	int* lowAndHigh = randNumsGen(actualVal);
	/*for (int i = 0; i < 3; i++) {
		cout << lowAndHigh[i] << endl;
	}*/

	do
	{
		cout << endl << "Guess the number between the range " << lowAndHigh[0] << " and " << lowAndHigh[2] << "." << endl;
		cin >> entry;
		guesses--;
		if (guesses == 0) {
			cout << endl << "You ran out of guesses :(" << endl;
			break;
		}
	} while ((evalEntry(entry, actualVal) == false) && (guesses != 0));
}
