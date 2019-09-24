// CS002_IfSwitch.cpp
// Andrew Lam
//

#include <iostream>
using namespace std;

int main()
{
	int gender = 0, age = 0, counter = 10, nonUnder = 0, nonOver = 0, femaleUnder = 0, femaleOver = 0, maleUnder = 0, maleOver = 0;
	while (counter > 0)
	{
		cout << endl << "Enter gender (0 for non binary, 1 for female, and 2 for male) and age. " << endl;
		cin >> gender >> age;
		switch (gender)
		{
		case 0:
			if (age <= 20) nonUnder++;
			else nonOver++;
			counter--;
			break;
		case 1:
			if (age <= 20) femaleUnder++;
			else femaleOver++;
			counter--;
			break;
		case 2:
			if (age <= 20) maleUnder++;
			else maleOver++;
			counter--;
			break;
		}
	}
	cout << endl << "There are " << nonUnder << " non-binary individuals 20 and under.";
	cout << endl << "There are " << nonOver << " non-binary individuals 21 and over.";
	cout << endl << "There are " << femaleUnder << " females 20 and under.";
	cout << endl << "There are " << femaleOver << " females 21 and over.";
	cout << endl << "There are " << maleUnder << " males 20 and under.";
	cout << endl << "There are " << maleOver << " males 21 and over.";


}
