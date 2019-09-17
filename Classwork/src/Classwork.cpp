//============================================================================
// Name        : Classwork.cpp
// Author      : Andrew Lam
// Description : Ask the user for their age and prints a statement
//============================================================================

#include <iostream>
using namespace std;
#include <sstream>

int main() {
	string entryStr = "";
	int result = 0;
	int addNum = 0;
	do
	{
		cout << "Enter a number or Done: \n";
		cin >> entryStr;
		stringstream entryNum(entryStr);
		entryNum >> addNum;
		result += addNum;
	} while(entryStr != "Done");

	cout << "Your final sum is: " << result << ". \n";

	system("PAUSE");

	return 0;
}
