#include <iostream>
using namespace std;

bool behaviorCheck()
{
	char behaveEntry;
	cout << "Are kids behaving? y/n \n";
	cin >> behaveEntry;
	if (behaveEntry == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void giveCandy()
{
	cout << "Gave candy to imps \n";
}

int main() {
	do
	{
		giveCandy();
	} while (behaviorCheck() == true);

	cout << "No more candy";
	return 0;
}