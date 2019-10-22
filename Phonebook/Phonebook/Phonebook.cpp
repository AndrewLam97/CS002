/*
Phonebook.cpp
10/21/19
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
PURPOSE: Finds phone number value stored to key containing string name
PARAMETERS: Hash map phonebook containing names and phone numbers, and targetName string
OUTPUTS: Returns phone number of targetName
*/
string lookupName(map<string, string> phonebook, string targetName)
{
	return phonebook[targetName];
}

/*
PURPOSE: Fills map with strings names and phone numbers
PARAMETERS: Hash map phonebook containing names and phone numbers
OUTPUTS: None, map passed by reference
*/
void fillMap(map<string, string>& phonebook)
{
	phonebook["Michael Myers"] = "333-8000";
	phonebook["Ash Williams"] = "3333-2323";
	phonebook["Jack Torrance"] = "333-6150";
	phonebook["Freddy Krueger"] = "333-7970";
}

int main() {
	map<string, string> phonebook; //creates and fills map
	fillMap(phonebook);

	string targetName, targetPhone;
	char c = 'y';

	do
	{
		cout << "Enter a name to find the " << "corresponding phone number." << endl;
		getline(cin, targetName); //get string containing target name
		targetPhone = lookupName(phonebook, targetName); //store phone number to variable
		if (targetPhone.length() > 0)
		{
			cout << "The number is: " << targetPhone << endl;
		}
		else
		{
			cout << "Name not found. " << endl;
		}
		cout << "Look up another name? (y/n)" << endl;
		cin >> c;
		cin.ignore(); //clear buffer containing prev input
	} while (c == 'y'); //loop until user done
	return 0;
}
