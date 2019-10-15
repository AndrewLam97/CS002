/* CS002_MathInstructions.cpp
Functions:
Set a struct containing number
Add numbers, returns if carry, bool carry marker

print equation
print typed instrcutions


*/
#include <iostream>
using namespace std;

struct Number {
	int hundreds;
	int tens;
	int ones;
};

void printEquation(Number num1, Number num2, bool carry1, bool carry2); //
void printNumber(Number num);
void printInstructions(int intNum1, int intNum2);
int toInt(Number num);
Number adder(Number num1, Number num2, int place, bool carry1, bool carry2);

int main()
{
    cout << "Hello World!\n";
}

void printEquation()
{
	
}