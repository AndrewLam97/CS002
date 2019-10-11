// CS002_Swap.cpp 
//

#include <iostream>
using namespace std;

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;

}

int main()
{
	int x = 1;
	int y = 2;

	cout << "x:" << x << " and y:" << y << endl;

	swap(x, y);

	cout << "Swapping" << endl;

	cout << "x:" << x << " and y:" << y << endl;

	return 0;

}

