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

string modToString(string place, int value)
{
	return 0;
}

int main()
{
	while (true)
	{
		string entry;
		string result = "";

		cout << "Enter Arabic numeral or done: ";
		cin >> entry;
		if (entry == "done")
		{
			break;
		}

		int entryNum = stoi(entry);

		while (entryNum > 0)
		{
			for (int thousands = entryNum / 1000; thousands > 0; thousands--)
			{
				cout << romanConvert(1000);
				entryNum -= 1000;
			}

			int hundreds = entryNum / 100;
			entryNum -= hundreds * 100;
			do
			{
				if (hundreds == 9)
				{
					cout << romanConvert(900);
					hundreds -= 9;
				}
				else if (hundreds >= 5)
				{
					cout << romanConvert(500);
					hundreds -= 5;
				}
				else if (hundreds == 4)
				{
					cout << romanConvert(400);
					hundreds -= 4;
				}
				else if (hundreds < 4 && hundreds > 0)
				{
					cout << romanConvert(100);
					hundreds -= 1;
				}
				else break;
			}while(hundreds > 0);

			int tens = entryNum / 10;
			entryNum -= tens * 10;
			do
			{
				if (tens == 9)
				{
					cout << romanConvert(90);
					tens -= 9;
				}
				else if (tens >= 5)
				{
					cout << romanConvert(50);
					tens -= 5;
				}
				else if (tens == 4)
				{
					cout << romanConvert(40);
					tens -= 4;
				}
				else if (tens < 4 && tens > 0)
				{
					cout << romanConvert(10);
					tens -= 1;
				}
				else break;
			} while (tens > 0);

			int ones = entryNum / 1;
			entryNum -= ones;
			do
			{
				if (ones == 9)
				{
					cout << romanConvert(9);
					ones -= 9;
				}
				else if (ones >= 5)
				{
					cout << romanConvert(5);
					ones -= 5;
				}
				else if (ones == 4)
				{
					cout << romanConvert(4);
					ones -= 4;
				}
				else if (ones < 4 && ones > 0)
				{
					cout << romanConvert(1);
					ones -= 1;
				}
				else break;
			} while (ones > 0);
		}
		cout << endl;
	}
}