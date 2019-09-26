// GuessingGame.cpp
// Andrew Lam
//

#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int guesser(int low, int high)
{
	mt19937 mt_rand(time(0));
	uniform_int_distribution<int> gen(low, high);
	int randomNum = gen(mt_rand);
	cout << "guesser guessed " << randomNum << endl;

	return randomNum;
}

int main()
{
	char entry = '\n';
	int low = 1, high = 100, guess = 1;
	cout << "Think of a number between 1 and 100 and press enter to proceed" << endl;
	cin.ignore();

	do
	{
		char entry;
		char lowOrHigh;

		guess = guesser(low, high);

		cout << "I guess " << guess << endl;
		cout << "Did I get it? Y/N" << endl;
		cin >> entry;

		if (entry == 'y' || entry == 'Y')
		{
			cout << "Yay I got it!";
			break;
		}
		else
		{
			cout << "Is it lower than " << guess << "? Y/N" << endl;
			cin >> lowOrHigh;
			if (lowOrHigh == 'y' || lowOrHigh == 'Y')
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

