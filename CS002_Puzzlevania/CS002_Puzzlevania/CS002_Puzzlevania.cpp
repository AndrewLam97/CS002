/*
CS002_Puzzlevania.cpp
DUE: 10/15/19
PURPOSE: Truel problem, three duelists with hit accuracies of 33%, 50%, 100%. Every individual shoots at the person alive with the most accuracy.
	Last man standing wins.
*/

#include <iostream>
#include <random>
using namespace std;

const double  aaronAcc = 1.0 / 3.0;
const double bobAcc = 0.5;
const double charlieAcc = 1;

void shoot(bool& targetAlive, double accuracy);
char startDuel();
char startAltDuel();

int main()
{
	int aCount = 0, bCount = 0, cCount = 0;

	int entry = 0;

	cout << "Enter 1 for normal duel, 2 for alt duel: " << endl;
	cin >> entry;
	
	if (entry == 1) { 
		for (int i = 0; i < 100000; i++) //100000 duels, count winners
		{
			switch (startDuel())
			{
			case 'a':
				aCount++;
				break;
			case 'b':
				bCount++;
				break;
			case 'c':
				cCount++;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 100000; i++)
		{
			switch (startAltDuel())
			{
			case 'a':
				aCount++;
				break;
			case 'b':
				bCount++;
				break;
			case 'c':
				cCount++;
				break;
			}
		}
	}
	cout << "Aaron won: " << aCount << " times." << endl;
	cout << "Bob won: " << bCount << " times." << endl;
	cout << "Charlie won: " << cCount << " times." << endl;
}

/*
PURPOSE: simulates a singular shot, shoots at targetAlive with given accuracy and uses a random number to determine if target is hit
PARAMETERS: bool targetAlive with the current value of target, double accuracy containing shooter's hit percentage
RETURN VALUES: none, targetAlive passed by reference and modified in function
*/
void shoot(bool& targetAlive, double accuracy)
{   //generate random number between 0 and 1
	random_device device; 
	mt19937 generator(device());
	uniform_real_distribution<double> dis(0.0, 1.0); 
	double rand = dis(generator);

	if (targetAlive == true && rand < accuracy) //target hit given random number less than accuracy
	{
		targetAlive = false;
	}
}

/*
PURPOSE: Starts a duel with each person shooting at the person with the highest accuracy that's alive.
PARAMETERS: none
RETURN VALUES: char representing winner
*/
char startDuel()
{
	bool Aaron = true, Bob = true, Charlie = true; //all individuals alive

	shoot(Charlie, aaronAcc); //first shot set

	if (Charlie) //start Charlie alive branch
	{
		shoot(Charlie, bobAcc);

		if (Charlie)
		{
			shoot(Bob, charlieAcc);
			shoot(Charlie, aaronAcc);
			if (Charlie)
			{
				shoot(Aaron, charlieAcc); //end of Charlie alive path
			}
		}
		else //Charlie killed by Bob path
		{
			while (Aaron && Bob) //Aaron and Bob duel until one dies
			{
				shoot(Bob, aaronAcc);
				if (Bob == false)
				{
					break;
				}
				shoot(Aaron, bobAcc);
				if (Aaron == false)
				{
					break;
				}
			}
		}
	}
	else //Charlie killed by Aaron path
	{
		while (Aaron && Bob) //Aaron and Bob duel until one dies
		{
			shoot(Aaron, bobAcc);
			if (Aaron == false)
			{
				break;
			}
			shoot(Bob, aaronAcc);
			if (Bob == false)
			{
				break;
			}
		}
	}

	if (Aaron)
	{
		return 'a';
	}
	if (Bob)
	{
		return 'b';
	}
	if (Charlie)
	{
		return 'c';
	}
}

/*
PURPOSE: Starts a duel with each person shooting at the person with the highest accuracy that's alive. However, Aaron intentionally misses his first shot
PARAMETERS: none
RETURN VALUES: char representing winner
*/
char startAltDuel()
{
	bool Aaron = true, Bob = true, Charlie = true;

	shoot(Charlie, 0); //Aaron intentionally misses

	if (Charlie) //start Charlie alive branch
	{
		shoot(Charlie, bobAcc);

		if (Charlie)
		{
			shoot(Bob, charlieAcc);
			shoot(Charlie, aaronAcc);
			if (Charlie)
			{
				shoot(Aaron, charlieAcc); //end Charlie alive path
			}
		}
		else //Charlie killed by Bob
		{
			while (Aaron && Bob)
			{
				shoot(Bob, aaronAcc);
				if (Bob == false)
				{
					break;
				}
				shoot(Aaron, bobAcc);
				if (Aaron == false)
				{
					break;
				}
			}
		}
	}
	else //Charlie killed by Aaron
	{
		while (Aaron && Bob)
		{
			shoot(Aaron, bobAcc);
			if (Aaron == false)
			{
				break;
			}
			shoot(Bob, aaronAcc);
			if (Bob == false)
			{
				break;
			}
		}
	}

	if (Aaron)
	{
		return 'a';
	}
	if (Bob)
	{
		return 'b';
	}
	if (Charlie)
	{
		return 'c';
	}
}
