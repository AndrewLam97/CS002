#include "test.h"
#include "array_functions.h"
#include <iostream>
using namespace std;

extern const int MAX_SIZE;
typedef int ARRAY_TYPE;

void test_fillArrayCons(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing constant fill..." << endl;
	cout << "Original array: " << endl;
	printArray(arr,num_used);
	int value = 7;
	fillArrayCons(arr, value);
	cout << "Filled array with " << value << endl;
	printArray(arr,num_used);
	cout << endl;
}

void test_fillArrayRand(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing random fill..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	fillArrayRand(arr);
	cout << "Filled array with random values" << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_append(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing append..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	int capacity = 3, value = 42;
	append(arr, capacity, 42);
	cout << "Appended " << value << " at capacity " << capacity << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_shiftLeft(ARRAY_TYPE arr[], int& num_used, int mark)
{
	cout << "Testing shiftLeft..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	shiftLeft(arr, num_used, mark);
	cout << "Shifted array at index = " << mark << ": " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_shiftRight(ARRAY_TYPE arr[], int& num_used, int mark)
{
	cout << "Testing shiftRight..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	shiftRight(arr, num_used, mark);
	cout << "Shifted array at index = " << mark << ": " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_selectionSort(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing selectionSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	selectionSort(arr);
	cout << "Sorted array using selection sort: " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_bubbleSort(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing bubbleSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	bubbleSort(arr);
	cout << "Sorted array using bubble sort: " << endl;
	printArray(arr, num_used);
	cout << endl;
}

/*
PURPOSE: driver function for testing aray sorting
PARAMETERS: integer array and array size
RETURN VALUES: none, outputs to console
*/
void testFnc(ARRAY_TYPE arr[], int& num_used)
{
	test_fillArrayCons(arr, num_used);
	test_fillArrayRand(arr, num_used);
	////test shiftLeft
	test_shiftLeft(arr, num_used, 2);
	////test shiftRight
	test_shiftRight(arr, num_used, 6);
	

	
}