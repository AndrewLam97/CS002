// CS002_Lab_Arrays.cpp
//

#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

/*
PURPOSE: creates file numbers.txt containing 20 random numbers from 1 to 1000
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
PURPOSE: opens the file numbers.txt and puts ints into an array. Outputs the array to console/
PARAMETERS: None, opens numbers.txt
RETURN VALUES: None, couts arrays
*/
void outputNums()
{
	ifstream in;
	int temp = 0;
	in.open("numbers.txt");
	int arr[20];
	for (int i = 0; i < 20; i++) //iterates through file
	{
		in >> temp; //store int to temp
		arr[i] = temp;
	}
	in.close();

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	createNums();
	outputNums();
}

