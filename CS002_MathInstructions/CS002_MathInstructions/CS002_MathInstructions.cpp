/* CS002_MathInstructions.cpp
Functions:
Set a struct containing number
Add numbers, returns if carry, bool carry marker

print equation
print typed instrcutions
*/
#include <iostream>
#include <iomanip>
using namespace std;

char sign = '+';

struct Number {
	int thousands;
	int hundreds;
	int tens;
	int ones;
};

Number getNumber(int n);
void addOnes(Number num1, Number num2, Number& numTotal, int& carry1);
void addTens(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2);
void addHundreds(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2);

void printCarry(int carry1, int carry2);
void printEquation(Number num1, Number num2);
void printTotal(Number numTotal, int i);

void printInstructions(int intNum1, int intNum2);

int main()
{
	int number1 = 0, number2 = 0, carry1 = 0, carry2 = 0;

	cout << "Enter numbers : " << endl;
	cin >> number1 >> number2;

	Number num1 = getNumber(number1);
	Number num2 = getNumber(number2);
	Number numTotal;

	for (int i = 1; i <= 100; i *= 10)
	{
		switch (i)
		{
		case 1:
			addOnes(num1, num2, numTotal, carry1);
			printCarry(carry1, carry2);
			printEquation(num1, num2);
			printTotal(numTotal, i);
			break;
		case 10:
			addTens(num1, num2, numTotal, carry1, carry2);
			printCarry(carry1, carry2);
			printEquation(num1, num2);
			printTotal(numTotal, i);
			break;
		case 100:
			addHundreds(num1, num2, numTotal, carry1, carry2);
			printCarry(carry1, carry2);
			printEquation(num1, num2);
			printTotal(numTotal, i);
			break;
		}
	}
}

Number getNumber(int n)
{
	Number num;
	num.ones = n % 10;
	num.tens = (n / 10) % 10;
	num.hundreds = n / 100;
	num.thousands = 0;

	return num;
}

void addOnes(Number num1, Number num2, Number& numTotal, int& carry1)
{
	int total = num1.ones + num2.ones;
	if (total >= 10)
	{
		carry1++;
	}
	numTotal.ones = total % 10;
}

void addTens(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2)
{
	int total = num1.tens + num2.tens;
	if (carry1 == 1)
	{
		total++;
	}
	if (total >= 10)
	{
		carry2++;
	}
	numTotal.tens = total % 10;
}

void addHundreds(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2)
{
	int total = num1.hundreds + num2.hundreds;
	if (carry2 == 1)
	{
		total++;
	}
	if (total >= 10)
	{
		numTotal.thousands = total / 10;
	}
	else
	{
		numTotal.thousands = 0;
	}
	numTotal.hundreds = total % 10;
}

void printCarry(int carry1, int carry2)
{
	if (carry2 != 0 && carry1 == 0)
	{
		cout << endl << setw(3) << carry2 << endl;
	}
	else if (carry2 != 0 && carry1 != 0)
	{
		cout << endl << setw(3) << carry2 << setw(2) << carry1 << endl;
	}
	else if (carry1 != 0)
	{
		cout << endl << setw(5) << carry1 << endl;
	}
}

void printEquation(Number num1, Number num2)
{
	cout << setw(3) << num1.hundreds << " " << num1.tens << " " << num1.ones << endl;
	cout << sign << " " << num2.hundreds << " " << num2.tens << " " << num2.ones << endl;
	cout << "-------" << endl;
}

void printTotal(Number numTotal, int place)
{
	switch (place)
	{
	case 1:
		cout << setw(7) << numTotal.ones << endl << endl;
		break;
	case 10:
		cout << setw(5) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		break;
	case 100:
		if (numTotal.thousands != 0)
		{
			cout << numTotal.thousands << " " << numTotal.hundreds << setw(2) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		}
		else
		{
			cout << setw(3) << numTotal.hundreds << setw(2) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		}
	}
}