// CS002_Lab_IO.cpp

#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

/*
PURPOSE: Creates file numbers.txt containing 20 random numbers from 1 to 1000
PARAMETERS: None
RETURN VALUES: None, creates a file numbers.txt
*/
void createNums()
{
	ofstream out;
	out.open("numbers.txt");
	for (int i = 0; i < 20; i++) //create 20 random numbers delineated by a newline
	{
		random_device device; //generate random number between 1 and 1000
		mt19937 generator(device());
		uniform_int_distribution<int> dis(0, 1000);
		int rand = dis(generator);
		out << rand << endl;
	}
	out.close();
}

/*
PURPOSE: Opens the file numbers.txt and outputs the numbers to console with a numerical indicator. Outputs the maximum integer in the file
PARAMETERS: None, opens numbers.txt
RETURN VALUES: None, couts output
*/
void outputNums()
{
	ifstream in;
	int max = 0, temp = 0;
	in.open("numbers.txt");
	for (int i = 1; i <= 20; i++) //iterates through file
	{
		in >> temp; //store int to temp
		cout << i << ": " << temp << endl;
		if (temp > max) //compare temp to stored max value
		{
			max = temp;
		}
	}
	in.close();
	cout << "Max int is: " << max;
}
int main()
{
	createNums();
	outputNums();
}
