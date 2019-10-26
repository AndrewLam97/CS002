#include "test.h"
#include "array_functions.h"
#include <iostream>
using namespace std;

extern const int MAX_SIZE;

/*void test_fill()
{
	cout << "Test fnc";
}

void test_print()
{

}

void test_append()
{
	
}*/



/*
PURPOSE: driver function for testing aray sorting
PARAMETERS: integer array and array size
RETURN VALUES: none, outputs to console
*/
void testFnc(int arr[])
{
	printArray(arr);
	shiftRight(arr, 1);
	printArray(arr);
	fillArrayCons(arr, 0);
	printArray(arr);
	int capacity = 4;

	appendArray(arr, capacity, 1);
	printArray(arr);
	cout << endl;

	//test selection sort
	cout << "Testing Selection Sort...";
	fillArrayRand(arr);
	cout << endl << "Unsorted array: " << endl;
	printArray(arr);
	selectionSort(arr);
	cout << endl << "Sorted array: " << endl;
	printArray(arr);

	//test bubble sort
	cout << endl << endl << "Testing Bubble Sort..." << endl;
	fillArrayRand(arr);
	cout << "Unsorted array: " << endl;
	printArray(arr);
	bubbleSort(arr);
	cout << endl << "Sorted array: " << endl;
	printArray(arr);
}