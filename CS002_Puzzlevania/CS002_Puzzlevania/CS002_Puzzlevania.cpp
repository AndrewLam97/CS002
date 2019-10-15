/*
CS002_Puzzlevania.cpp

Hit Chance:
Aaron = 1/3
Bob = 1/2
Charlie = 1

Order:
Aaron - Bob - Charlie

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
		for (int i = 0; i < 100000; i++)
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

void shoot(bool& targetAlive, double accuracy)
{
	random_device device;
	mt19937 generator(device());
	uniform_real_distribution<double> dis(0.0, 1.0);
	double rand = dis(generator);

	if (targetAlive == true && rand < accuracy)
	{
		targetAlive = false;
	}
}

char startDuel()
{
	bool Aaron = true, Bob = true, Charlie = true;

	shoot(Charlie, aaronAcc);

	if (Charlie)
	{
		shoot(Charlie, bobAcc);

		if (Charlie)
		{
			shoot(Bob, charlieAcc);
			shoot(Charlie, aaronAcc);
			if (Charlie)
			{
				shoot(Aaron, charlieAcc);
			}
		}
		else
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
	else
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

char startAltDuel()
{
	bool Aaron = true, Bob = true, Charlie = true;

	shoot(Charlie, 0);

	if (Charlie)
	{
		shoot(Charlie, bobAcc);

		if (Charlie)
		{
			shoot(Bob, charlieAcc);
			shoot(Charlie, aaronAcc);
			if (Charlie)
			{
				shoot(Aaron, charlieAcc);
			}
		}
		else
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
	else
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
