// CS002_RomanConverter.cpp
// Andrew Lam

#include <iostream>
#include <string>
using namespace std;

struct Number
{
	int thousands;
	int hundreds;
	int tens;
	int ones;
};

/*
PURPOSE: convert certain integers to roman numeral
PARAMETERS: int x
RETURN VALUES: string of equivalent roman numeral
*/
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

/*
PURPOSE: prints roman numeral from struct Number using romanConvert
PARAMETERS: struct Number entryNumber
RETURN VALUES: cout equivalent roman numeral
*/
void romanPrinter(Number& entryNumber)
{
	int tempMulti = 1;
	for (entryNumber.thousands; entryNumber.thousands > 0; entryNumber.thousands--) //handles thousands place
	{
		cout << romanConvert(1000);
	}

	do //handles hundreds place, prints value and decrements by printed amount, repeats until place value is 0
	{
		tempMulti = 100;
		if (entryNumber.hundreds == 9)
		{
			cout << romanConvert(entryNumber.hundreds * tempMulti);
			entryNumber.hundreds -= 9;
		}
		else if (entryNumber.hundreds >= 5)
		{
			cout << romanConvert(5 * tempMulti);
			entryNumber.hundreds -= 5;
		}
		else if (entryNumber.hundreds == 4)
		{
			cout << romanConvert(entryNumber.hundreds * tempMulti);
			entryNumber.hundreds -= 4;
		}
		else if (entryNumber.hundreds < 4 && entryNumber.hundreds > 0)
		{
			cout << romanConvert(tempMulti);
			entryNumber.hundreds -= 1;
		}
		else break;
	} while (entryNumber.hundreds > 0);

	do //handles tens place, prints value and decrements by printed amount, repeats until place value is 0
	{
		tempMulti = 10;
		if (entryNumber.tens == 9)
		{
			cout << romanConvert(entryNumber.tens * tempMulti);
			entryNumber.tens -= 9;
		}
		else if (entryNumber.tens >= 5)
		{
			cout << romanConvert(5 * tempMulti);
			entryNumber.tens -= 5;
		}
		else if (entryNumber.tens == 4)
		{
			cout << romanConvert(entryNumber.tens * tempMulti);
			entryNumber.tens -= 4;
		}
		else if (entryNumber.tens < 4 && entryNumber.tens > 0)
		{
			cout << romanConvert(tempMulti);
			entryNumber.tens -= 1;
		}
		else break;
	} while (entryNumber.tens > 0);

	do //handles ones place, prints value and decrements by printed amount, repeats until place value is 0
	{
		if (entryNumber.ones == 9)
		{
			cout << romanConvert(entryNumber.ones);
			entryNumber.ones -= 9;
		}
		else if (entryNumber.ones >= 5)
		{
			cout << romanConvert(5);
			entryNumber.ones -= 5;
		}
		else if (entryNumber.ones == 4)
		{
			cout << romanConvert(entryNumber.ones);
			entryNumber.ones -= 4;
		}
		else if (entryNumber.ones < 4 && entryNumber.ones > 0)
		{
			cout << romanConvert(1);
			entryNumber.ones -= 1;
		}
		else break;
	} while (entryNumber.ones > 0);
}

int main()
{
	while (true) //repeat converting until entry string = done
	{
		string entry;

		cout << "Enter Arabic numeral or done: ";
		cin >> entry;
		if (entry == "done")
		{
			break;
		}

		int entryNum = stoi(entry);

		Number entryNumber; //constructs struct Number containing place values
		entryNumber.thousands = entryNum / 1000;
		entryNumber.hundreds = (entryNum / 100) % 10;
		entryNumber.tens = (entryNum % 100) / 10;
		entryNumber.ones = entryNum % 10;

		romanPrinter(entryNumber);
		cout << endl;
	}
}