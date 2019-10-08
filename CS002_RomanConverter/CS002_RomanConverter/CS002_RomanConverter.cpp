// CS002_RomanConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string romanConvert(int x)
{
	if (x == 1)
		return "I";
	if (x == 4)
		return "IV";
	if (x == 5)
		return "V";
	if (x == 9)
		return "IX";
	if (x == 10)
		return "X";
	if (x == 40)
		return "XL";
	if (x == 50)
		return "L";
	if (x == 90)
		return "XC";
	if (x == 100)
		return "C";
	if (x == 400)
		return "CD";
	if (x == 500)
		return "D";
	if (x == 900)
		return "CM";
	if (x == 1000)
		return "M";
}

int main()
{
	
	string entry;
	/*
	struct arabicNum
	{
		int thousands;
		int hundreds;
		int tens;
		int ones;
	};

	while(true)
	{
		string result = ""; */
		cout << "Enter Arabic numeral or done: ";
		cin >> entry; 
		if (entry == "done")
		{
			exit;
		}

		int entryNum = stoi(entry);
		/*
		arabicNum num;

		for (int i = 0; i < entry.length(); i++)
		{
			result += romanConvert(entry[i]);
		}

		cout << "Your Roman Numeral is: " << result << endl;

	}*/


	for (int i = 12; i > 0; i--)
	{
		while (entryNum > 0)
		{

		}
	}
}