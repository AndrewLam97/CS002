#include <iostream>
#include <random>
using namespace std;

void fillArray(int array[], int size);
void printArray(int array[], int size);
void swap(int array[], int pos1, int pos2);
void selectionSort(int array[], int size);
void bubbleSort(int array[], int size);
void testFnc(int array[], int size);

int main() {
	const int size = 5;
	int array[size];

	testFnc(array, size);

	return 0;
}

/*
PURPOSE: Fills an integer with random integers ranging from 1 to 100
PARAMETERS: integer array, array size
RETURN VALUES: none, array modified in place
*/
void fillArray(int array[], int size)
{
	for (int i = 0; i < size; i++) //fills each index in array with random int
	{
		random_device device;
		mt19937 generator(device());
		uniform_int_distribution<int> dis(0,100);
		int rand = dis(generator);

		array[i] = rand;
	}
}

/*
PURPOSE: Prints an array to console
PARAMETERS: integer array, size of array
RETURN VALUES: none, outputs to console
*/
void printArray(int array[], int size)
{
	cout << "[ ";
	for (int i = 0; i < size; i++) //iterate through array
	{
		cout << array[i] << " "; //print integer at current index
	}
	cout << "]";
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

/*
PURPOSE: sorts an array of integers using selection sort
PARAMETERS: integer array and size of array
RETURN VALUES: none, swaps performed in place
*/
void selectionSort(int array[], int size)
{
	int lowestPos;
	for (int i = 0; i < size-1; i++) //iterate starting point
	{
		lowestPos = i;
		for (int j = i + 1; j < size; j++) //iterate secondary index
		{
			if (array[j] < array[lowestPos]) //find index of lowest element
			{
				lowestPos = j;
			}
		}
		swap(array, i, lowestPos); //swap lowest to starting point
	}
}

/*
PURPOSE: sorts an array of integers using bubble sort
PARAMETERS: integer array and size of array
RETURN VALUES: none, swaps performed in place
*/
void bubbleSort(int array[], int size)
{
	bool swapped = true; //swapped flag
	for (int i = 0; i < size - 1 && swapped; i++) //iterate through array until maximum swaps (n^2) reached or no swaps performed amongst 1 pass
	{
		swapped = false;
		for (int j = 0; j < size - 1 - i; j++) //iterate starting point
		{
			if (array[j] > array[j + 1]) //compare current index to index + 1
			{
				swap(array, j, j + 1); 
				swapped = true; //swapped flag
			}
		}
	}
}

/*
PURPOSE: driver function for testing aray sorting 
PARAMETERS: integer array and array size
RETURN VALUES: none, outputs to console
*/
void testFnc(int array[], int size)
{
	//test selection sort
	cout << "Testing Selection Sort";
	fillArray(array, size);
	cout << endl << "Unsorted array: " << endl;
	printArray(array, size);
	selectionSort(array, size);
	cout << endl<< "Sorted array: " << endl;
	printArray(array, size);
	
	//test bubble sort
	cout << endl << endl << "Testing Bubble Sort..." << endl;
	fillArray(array, size);
	cout << "Unsorted array: " << endl;
	printArray(array, size);
	bubbleSort(array, size);
	cout << endl << "Sorted array: " << endl;
	printArray(array, size);
}