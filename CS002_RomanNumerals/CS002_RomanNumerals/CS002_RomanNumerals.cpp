// CS002_RomanNumerals.cpp 
//

#include <iostream>
using namespace std;

int  romanConvert(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;
	else return 0;
}

int main()
{
	string entry;

	do
	{
		int sum = 0;

		cout << "Enter roman numeral or done: " << endl;
		cin >> entry;

		for (int i = 0; i < entry.length(); i++)
		{
			if (romanConvert(entry[i]) >= romanConvert(entry[i + 1]))
			{
				sum += romanConvert(entry[i]);
			}
			else
			{
				sum += romanConvert(entry[i + 1]) - romanConvert(entry[i]);
				i++;
			}
		}
		cout << "Your roman numeral is: " << sum << endl;
	} while (entry != "done");
}