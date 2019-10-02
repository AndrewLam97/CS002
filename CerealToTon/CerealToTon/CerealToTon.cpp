/*
 * Andrew Lam
 * 9-18-19
 * CS002 Classwork
 * This program prompts the user for the weight, in ounces, of a cereal box and outputs box weight in metric tons and how many boxes would be needed to yield 1 metric ton.
 */

#include <iostream>
using namespace std;

void boxToTon() {
	double entry = 0;
	do
	{
		cout << "What is the weight, in ounces, of one cereal box?" << endl;
		cin >> entry;
		if (cin.fail())
		{
			cout << endl << "You entered an incorrect input" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Your box is " << entry / 36273.92 << " metric tons." << endl;
			if (entry >= 36273.92)
			{
				cout << "You would need 1 cereal box to yield at least 1 metric ton.";
			}
			else 
			{
				cout << "You would need " << int(36273.92 / entry) << " cereal boxes to yield 1 metric ton.";
			}
			break;
		}
	} while (true);
}

int main()
{
	boxToTon();
}
