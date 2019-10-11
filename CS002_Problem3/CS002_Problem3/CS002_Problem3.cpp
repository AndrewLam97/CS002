// CS002_Problem3

#include <iostream>
using namespace std;
/*
NAME: stockValue
PARAMETERS: int stockBase, double stockNumerator, double stockDenominator
			representing the three parts of a stock's price
RETURN VALUES: double containing the value of the price of one share of the stock
*/
double stockValue(int stockBase, double stockNumerator, double stockDenominator)
{
	double value = stockBase + (stockNumerator / stockDenominator);
	return value;
}

int main()
{
	int numShares = 0, stockBase = 0, stockNumerator = 0, stockDenominator = 0;

	cout << "Enter shares: " << endl;
	cin >> numShares;
	cout << "Enter price base number: " << endl;
	cin >> stockBase;
	cout << "Enter price numerator: " << endl;
	cin >> stockNumerator;
	cout << "Enter price denominator: " << endl;
	cin >> stockDenominator;

	cout << endl << "Your stock holdings have a value of: $" << numShares * stockValue(stockBase, stockNumerator, stockDenominator) << endl;
}
