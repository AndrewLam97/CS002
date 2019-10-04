/*
NAME: Andrew Lam
DATE: 10-3-19
PURPOSE: Takes initial size of crud in pounds and number of days
		 Outputs number of pounds of crud after that many days
		 Crud multiplies every 5th day.
*/

#include <iostream>
using namespace std;
/*
NAME: fibonacci
PURPOSE: returns value of fibonacci's sequence at requested iteration
PARAMETERS: startNum is base number for the sequence, maxIterations is the iteration requested
RETURN VALUES: integer of fibonacci's sequence at requested iteration
*/
int fibonacci(int startNum, int maxIterations)
{
	int firstNum = 0, temp = 0, secondNum = startNum, maxVal = 0;

	for (int i = 0; i < maxIterations; i++) //calculates fibonacci's # on a per iteration basis
	{
		maxVal = firstNum;
		//swaps and addition
		temp = firstNum + secondNum;
		firstNum = secondNum;
		secondNum = temp;
	}
	return maxVal;
}

int main()
{
	int startNum = 0;
	int maxIterations = 0;

	cout << "Enter starting weight of crud in pounds: " << endl;
	cin >> startNum;
	cout << endl << "How many days? " << endl;
	cin >> maxIterations;
	cout << endl;

	maxIterations /= 5; //iterates only every 5th day
	maxIterations += 2; //accounts for first 2 given #s in the sequence

	cout << "Resulting weight is: " << fibonacci(startNum, maxIterations) << " pounds." << endl;

	return 0;
}


