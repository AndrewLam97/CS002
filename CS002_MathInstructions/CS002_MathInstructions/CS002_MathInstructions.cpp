/*
CS002_MathInstructions.cpp
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Number {
	int thousands;
	int hundreds;
	int tens;
	int ones;
};
Number getNumber(int n);

void addition();

void addOnes(Number num1, Number num2, Number& numTotal, int& carry1);
void addTens(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2);
void addHundreds(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2);

void printCarry(int carry1, int carry2);
void printEquation(Number num1, Number num2, char sign);
void printTotal(Number numTotal, int i);
void printInstructions(Number Num1, Number Num2, int carry1, int carry2, char sign, int i);

int main()
{
	string entry;
	cout << "Enter + for addition or - for subtraction: " << endl;
	cin >> entry;
	if (entry == "+") {
		addition();
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

void addition()
{
	int number1 = 0, number2 = 0, carry1 = 0, carry2 = 0;
	char sign = '+';

	cout << "Enter numbers : " << endl;
	cin >> number1 >> number2;

	Number num1 = getNumber(number1);
	Number num2 = getNumber(number2);
	Number numTotal;

	printEquation(num1, num2, sign);
	cout << endl << endl;

	for (int i = 1; i <= 100; i *= 10)
	{
		switch (i) {
		case 1:
			addOnes(num1, num2, numTotal, carry1);
			printInstructions(num1, num2, carry1, carry2, sign, i);
			printCarry(carry1, carry2);
			printEquation(num1, num2, sign);
			printTotal(numTotal, i);
			break;
		case 10:
			addTens(num1, num2, numTotal, carry1, carry2);
			printInstructions(num1, num2, carry1, carry2, sign, i);
			printCarry(carry1, carry2);
			printEquation(num1, num2, sign);
			printTotal(numTotal, i);
			break;
		case 100:
			addHundreds(num1, num2, numTotal, carry1, carry2);
			printInstructions(num1, num2, carry1, carry2, sign, i);
			printCarry(carry1, carry2);
			printEquation(num1, num2, sign);
			printTotal(numTotal, i);
			break;
		}
	}
}

void addOnes(Number num1, Number num2, Number& numTotal, int& carry1)
{
	int total = num1.ones + num2.ones;
	if (total >= 10) {
		carry1++;
	}
	numTotal.ones = total % 10;
}

void addTens(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2)
{
	int total = num1.tens + num2.tens;
	if (carry1 == 1) {
		total++;
	}
	if (total >= 10) {
		carry2++;
	}
	numTotal.tens = total % 10;
}

void addHundreds(Number num1, Number num2, Number& numTotal, int& carry1, int& carry2)
{
	int total = num1.hundreds + num2.hundreds;
	if (carry2 == 1) {
		total++;
	}
	if (total >= 10) {
		numTotal.thousands = total / 10;
	}
	else {
		numTotal.thousands = 0;
	}
	numTotal.hundreds = total % 10;
}

void printCarry(int carry1, int carry2)
{
	if (carry2 != 0 && carry1 == 0) {
		cout << endl << setw(3) << carry2 << endl;
	}
	else if (carry2 != 0 && carry1 != 0) {
		cout << endl << setw(3) << carry2 << setw(2) << carry1 << endl;
	}
	else if (carry1 != 0) {
		cout << endl << setw(5) << carry1 << endl;
	}
}

void printEquation(Number num1, Number num2, char sign)
{
	cout << setw(3) << num1.hundreds << " " << num1.tens << " " << num1.ones << endl;
	cout << sign << " " << num2.hundreds << " " << num2.tens << " " << num2.ones << endl;
	cout << "-------" << endl;
}

void printTotal(Number numTotal, int place)
{
	switch (place) {
	case 1:
		cout << setw(7) << numTotal.ones << endl << endl;
		break;
	case 10:
		cout << setw(5) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		break;
	case 100:
		if (numTotal.thousands != 0) {
			cout << numTotal.thousands << " " << numTotal.hundreds << setw(2) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		}
		else {
			cout << setw(3) << numTotal.hundreds << setw(2) << numTotal.tens << setw(2) << numTotal.ones << endl << endl;
		}
	}
}

void printInstructions(Number num1, Number num2, int carry1, int carry2, char sign, int i)
{
	switch (sign) {
	case '+':
		switch (i) {
		case 1:
			cout << "In the ones column, adding " << num1.ones << " and " << num2.ones << " gives you " << num1.ones + num2.ones << "." << endl;
			if (carry1 != 0) {
				cout << "Bring down the " << (num1.ones + num2.ones) % 10 << " and carry the 1." << endl;
			}
			break;

		case 10:
			if (carry1 != 0) {//if carry1
				cout << "In the tens column, adding " << carry1 << ", " << num1.tens << ", and " << num2.tens << " gives you " << carry1 + num1.tens + num2.tens << "." << endl;
			}
			else { //no carry1
				cout << "In the tens column, adding " << num1.tens << " and " << num2.tens << " gives you " << num1.tens + num2.tens << "." << endl;
			}
			if (carry2 != 0) {//if carry2
				cout << "Bring down the " << (num1.tens + num2.tens + carry1) % 10 << " and carry the 1." << endl;
			}
			break;

		case 100:
			if (carry2 != 0) {
				cout << "Finally, in the hundreds column, adding " << carry2 << ", " << num1.hundreds << ", and " << num2.hundreds << " gives you " << carry2 + num1.hundreds + num2.hundreds << "." << endl;
			}
			else {
				cout << "Finally, in the hundreds column, adding " << num1.hundreds << " and " << num2.hundreds << " gives you " << num1.hundreds + num2.hundreds << "." << endl;
			}
			break;
		}
	}
}
