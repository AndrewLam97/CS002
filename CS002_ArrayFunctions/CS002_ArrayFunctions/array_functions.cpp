#include "array_functions.h"
#include <iostream>
#include <random>
using namespace std;

const int MAX_SIZE = 5;

/*
PURPOSE: Fills an array with random integers ranging from 1 to 100
PARAMETERS: integer array, array size
RETURN VALUES: none, array modified in place
*/
void fillArrayRand(int array[])
{
	for (int i = 0; i < MAX_SIZE; i++) //fills each index in array with random int
	{
		random_device device;
		mt19937 generator(device());
		uniform_int_distribution<int> dis(0, 100);
		int rand = dis(generator);

		array[i] = rand;
	}
}
/*
PURPOSE: Fills an array with the same integer
PARAMETERS: integer array, array size, desired value
RETURN VALUES: none, array modified in place
*/
void fillArrayCons(int array[], int value)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i] = value;
	}
}

/*
PURPOSE: Prints an array to console
PARAMETERS: integer array, size of array
RETURN VALUES: none, outputs to console
*/
void printArray(int array[])
{
	cout << "[ ";
	for (int i = 0; i < MAX_SIZE; i++) //iterate through array
	{
		cout << array[i] << " "; //print integer at current index
	}
	cout << "]";
}

/*
PURPOSE: Appends an integer value to an integer array at index capacity
PARAMETERS: integer array, integer capacity by reference, integer value
RETURN VALUES: none, array modified in place
*/
void appendArray(int array[], int& capacity, int value)
{
	if (capacity < MAX_SIZE)
	{
		array[capacity++] = value;
	}
	//for (int i = 0; i < MAX_SIZE; i++)
}

/*
PURPOSE: Copies contents of first array to second array
PARAMETERS: first and second integer array
RETURN VALUES: none, modified in place
*/
void copyArray(int array[], int array2[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array2[i] = array[i];
	}
}

/*
PURPOSE: Swaps two elements in an array
PARAMETERS: integer array, indexes of 2 elements to be swapped
RETURN VALUES: none, swaps performed in place
*/
void swap(int array[], int pos1, int pos2)
{
	int temp = array[pos1]; //save integer at pos1
	array[pos1] = array[pos2]; //swap integer at pos2 to pos1
	array[pos2] = temp; //replace integer at pos2 with saved pos1 
}

void shiftRight(int array[], int index)
{
	for (int i = index + 1; i < MAX_SIZE; i++)
	{
		swap(array, index, i);
	}
}

/*
PURPOSE: sorts an array of integers using selection sort
PARAMETERS: integer array and size of array
RETURN VALUES: none, swaps performed in place
*/
void selectionSort(int array[])
{
	int lowestPos;
	for (int i = 0; i < MAX_SIZE - 1; i++) //iterate starting point
	{
		lowestPos = i;
		for (int j = i + 1; j < MAX_SIZE; j++) //iterate secondary index
		{
			if (array[j] < array[lowestPos]) //find index of lowest element
			{
				lowestPos = j;
			}
		}
		swap(array, i, lowestPos); //swap lowest to current starting point
	}
}

/*
PURPOSE: sorts an array of integers using bubble sort
PARAMETERS: integer array and size of array
RETURN VALUES: none, swaps performed in place
*/
void bubbleSort(int array[])
{
	bool swapped = true; //swapped flag
	for (int i = 0; i < MAX_SIZE - 1 && swapped; i++) //iterate through array until maximum swaps (n^2) reached or no swaps performed amongst 1 pass
	{
		swapped = false;
		for (int j = 0; j < MAX_SIZE - 1 - i; j++) //iterate starting point
		{
			if (array[j] > array[j + 1]) //compare current index to index + 1
			{
				swap(array, j, j + 1);
				swapped = true; //swapped flag
			}
		}
	}
}

