// GuessingGame.cpp
// Andrew Lam
//

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

//takes lower and upper bounds and returns a random number inclusive
int guesser(int low, int high)
{
	mt19937 mt_rand(time(0));
	uniform_int_distribution<int> gen(low, high);
	int randomNum = gen(mt_rand);
	//cout << "guesser guessed " << randomNum << endl;
	return randomNum;
}

int main()
{
	char entry = '\n';
	int low = 1, high = 100, guess = 1;
	cout << "Think of a number between 1 and 100 and press enter to proceed" << endl;
	cin.ignore();
	//Takes user input until program receives a 'y' by guessing the right number
	do
	{
		char entry;
		char lowOrHigh;

		guess = guesser(low, high);

		cout << "I guess " << guess << endl;
		cout << "Did I get it? Y/N" << endl;
		cin >> entry;

		if (entry == 'y' || entry == 'Y') //guessed correctly
		{
			cout << "Yay I got it!";
			break;
		}
		else //guessed incorrectly
		{
			cout << "Is it lower than " << guess << "? Y/N" << endl; //evaluates higher or lower than guess
			cin >> lowOrHigh;
			if (lowOrHigh == 'y' || lowOrHigh == 'Y')//updates boundaries depending if response was higher/lower
			{
				high = guess - 1;
			}
			else
			{
				low = guess + 1;
			}
		}

	} while (true);

}
