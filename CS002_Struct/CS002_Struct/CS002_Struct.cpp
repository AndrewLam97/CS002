// CS002_Struct
// Andrew Lam

#include <iostream>
#include <string>
using namespace std;

struct Contact
{
	string firstName;
	string lastName;
	string phoneNumber;
};

/*
Purpose: creates a struct Contact c from user input
Parameters: none
Return Values: Contact c
*/
Contact getContact()
{
	Contact c;
	cout << "Enter first name: " << endl;
	cin >> c.firstName;

	cout << endl << "Enter last name: " << endl;
	cin >> c.lastName;

	cout << endl << "Enter phone number: " << endl;
	cin >> c.phoneNumber;

	return c;
}

/*
Purpose: prints the contents of struct Contact
Paramteters: Contact c
Return Values: none
*/
void printContact(Contact c)
{
	cout << endl << "Your contact info: " << endl;
	cout << "Name: " << c.firstName << " " << c.lastName << ", Phone number: " << c.phoneNumber << endl;
}

int main()
{
	Contact c = getContact();
	printContact(c);

	return 0;
}
