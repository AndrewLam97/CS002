#include "array_functions.h"
#include <iostream>
#include <random>
using namespace std;

const int MAX_SIZE = 20;
typedef int ARRAY_TYPE;

/*
PURPOSE: Fills an array with random integers ranging from 1 to 100
PARAMETERS: integer array, array size
RETURN VALUES: none, array modified in place
*/
void fillArrayRand(ARRAY_TYPE array[])
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
void fillArrayCons(ARRAY_TYPE array[], int value)
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
void printArray(ARRAY_TYPE array[], int num_used)
{
	cout << "[ ";
	for (int i = 0; i < num_used; i++) //iterate through array
	{
		cout << array[i] << " "; //print integer at current index
	}
	cout << "]" << endl;
}

/*
PURPOSE: Appends an integer value to an integer array at index capacity
PARAMETERS: integer array, integer capacity by reference, integer value
RETURN VALUES: none, array modified in place
*/
void append(ARRAY_TYPE array[], int& num_used, int item)
{
	if (num_used < MAX_SIZE-1)
	{
		array[num_used++] = item;
	}
}

void appendArray(ARRAY_TYPE array[], int destinationIndex, ARRAY_TYPE sourceArray[], int sourceIndex)
{

}

/*
PURPOSE: Copies contents of first array to second array
PARAMETERS: first and second integer array
RETURN VALUES: none, modified in place
*/
void copyArray(ARRAY_TYPE array[], int array2[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array2[i] = array[i];
	}
}

/*
PURPOSE: Searches an integer array for an integer value and returns the index of that value
PARAMETERS: integer array,  integer desired search value
RETURN VALUES: integer index of searched value
*/
int search(ARRAY_TYPE array[], int value)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if(array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

/*
PURPOSE: Swaps two elements in an array
PARAMETERS: integer array, indexes of 2 elements to be swapped
RETURN VALUES: none, swaps performed in place
*/
void swap(ARRAY_TYPE array[], int pos1, int pos2)
{
	int temp = array[pos1]; //save integer at pos1
	array[pos1] = array[pos2]; //swap integer at pos2 to pos1
	array[pos2] = temp; //replace integer at pos2 with saved pos1 
}

void shiftLeft(ARRAY_TYPE array[], int& num_used, int mark)
{
	for (int i = mark - 1; i >= 0; i--)
	{
		swap(array, mark, i);
	}
	num_used--;
}

/*
PURPOSE: shifts an integer array to the right starting at index
PARAMETERS: integer array and integer index
RETURN VALUES: none, array modified in place
*/
void shiftRight(ARRAY_TYPE array[], int& num_used, int mark)
{
	for (int i = mark + 1; i < MAX_SIZE; i++)
	{
		swap(array, mark, i);
	}
	num_used++;
}

void insert_before(ARRAY_TYPE array[], int& num_used, int item, int mark)
{
	shiftRight(array, num_used, mark);
	array[mark] = item;
}
void insert_after(ARRAY_TYPE array[], int& num_used, int item, int mark)
{
	shiftRight(array, num_used, mark+1);
	array[mark + 1] = item;
}

void remove(int array[], int& num_used, int mark)
{
	shiftLeft(array, num_used, mark);
	num_used--;
}

/*
PURPOSE: sorts an array of integers using selection sort
PARAMETERS: integer array and size of array
RETURN VALUES: none, swaps performed in place
*/
void selectionSort(ARRAY_TYPE array[])
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
void bubbleSort(ARRAY_TYPE array[])
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

