/*
 * Andrew Lam
 * CS002
 * Midpoint calculator, given 2 sets of starting coordinates
 */

#include <iostream>
using namespace std;

void midpointFormula() {
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	do
	{
		cout << "What are the first set of coordinates?" << endl;
		cin >> x1 >> y1;
		cout << endl << "What are the second set of coordinates>" << endl;
		cin >> x2 >> y2;

		if (cin.fail())
		{
			cout << endl << "You entered an incorrect input" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			cout << "The coordinates of the midpoint are (" << ((x1 + x2) / 2) << "," << ((y1 + y2) / 2) << ").";
			break;
		}
	} while (true);
}

int main()
{
	midpointFormula();
}