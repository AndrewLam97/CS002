#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CS002
{	
private:
	vector<string> results; //holds results in string vector
public:
	vector<string> split(string& target, char token); 
	vector<string> split(string& target, string delimiter);
	
	void printVector();
};

/*
PURPOSE: splits target string using delimiter string
PARAMETERS: target string and delimiter string
RETURN VALUES: string vector containing separated string
*/
vector<string> CS002::split(string& target, string delimiter)
{
	if (target == delimiter || target == "") //base case for recursion
	{
		return results;
	}
	
	size_t found = target.find(delimiter); //find index of delimiter string in target string
	if (found != string::npos) //if delimiter string found
	{
		if (target.substr(0, found) != "")//check if substring empty
		{
			results.push_back(target.substr(0, found)); //add substring to results vector
		}
		
		target.erase(target.begin(), target.begin() + found + delimiter.size()); //erase substring and delimiter from target string
		if (target != "" && target != delimiter)
		{
			split(target, delimiter); //call function again with modified target string
		}
	}
	else //if delimiter not found 
		results.push_back(target); //add target string to results
	return results;
}

/*
PURPOSE: splits target string using token char
PARAMETERS: target string and token char
RETURN VALUES: string vector containing separated string
*/
vector<string> CS002::split(string& target, char token)
{
	string delimiter(1, token); //convert token to string
	return split(target, delimiter); //call overloaded split
}

/*
PURPOSE: prints results vector
PARAMETERS: none
RETURN VALUES: none, couts vector to console
*/
void CS002::printVector()
{
	cout << "[ ";
	for (auto str : results) //iterate through results vector
	{
		cout << str << " ";
	}
	cout << "]" << endl;
}

/*
PURPOSE: Driver function for testing inputs
PARAMETERS: none, takes inputs via console
RETURN VALUES: none, outputs results to console
*/
void testFncString()
{
	string input;
	do {
		CS002 lab;
		string test = "";
		string delimiter = "";
		char token;
		
		cout << "Enter a string: " << endl;
		getline(cin, test);
		
		cout << "Enter a delimiter string or token char: " << endl;
		getline(cin,delimiter);
		if (delimiter.size() == 1) //if string size == 1, convert delimiter string to token char
		{
			token = delimiter[0];
			lab.split(test, token); //call overloaded split with token
			lab.printVector();
		}
		else {
			lab.split(test, delimiter); //call overloaded split with string
			lab.printVector();
		}
		cout << endl << "Go again? y/n" << endl;
		cin >> input;
		cin.ignore(1000, '\n');
	} while (input == "y");
}

int main()
{
	/*CS002 lab;
	string test = "10ab20ab30ab40";
	string delimiter = "ab";
	lab.split(test, delimiter);
	lab.printVector();

	CS002 lab1;
	test = "10ab20ab30ab40";
	char token = 'a';
	lab1.split(test, token);
	lab1.printVector();*/

	testFncString();
}
