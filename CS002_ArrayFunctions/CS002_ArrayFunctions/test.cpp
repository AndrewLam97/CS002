#include "test.h"
#include "array_functions.h"
#include <iostream>
using namespace std;

extern const int MAX_SIZE;
typedef int ARRAY_TYPE;

/*void test_fill()
{
	cout << "Test fnc";
}

void test_print()
{

}
*/

void test_append(ARRAY_TYPE arr[])
{
	cout << "Testing append..." << endl;
	cout << "Original array: " << endl;
	printArray(arr);
	int capacity = 3, value = 42;
	appendArray(arr, capacity, 42);
	cout << "Appended " << value << " at capacity " << capacity;
	printArray(arr);
}

void test_shiftLeft(ARRAY_TYPE arr[], int index)
{
	cout << "Testing shiftLeft..." << endl;
	cout << "Original array: " << endl;
	printArray(arr);
	shiftLeft(arr, index);
	cout << "Shifted array at index = " << index << ": " << endl;
	printArray(arr);
}

void test_shiftRight(ARRAY_TYPE arr[], int index)
{
	cout << "Testing shiftRight..." << endl;
	cout << "Original array: " << endl;
	printArray(arr);
	shiftRight(arr, index);
	cout << "Shifted array at index = " << index << ": " << endl;
	printArray(arr);
}

void test_selectionSort(ARRAY_TYPE arr[])
{
	cout << "Testing selectionSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr);
	selectionSort(arr);
	cout << "Sorted array using selection sort: " << endl;
	printArray(arr);
}

void test_bubbleSort(ARRAY_TYPE arr[])
{
	cout << "Testing bubbleSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr);
	bubbleSort(arr);
	cout << "Sorted array using bubble sort: " << endl;
	printArray(arr);
}

/*
PURPOSE: driver function for testing aray sorting
PARAMETERS: integer array and array size
RETURN VALUES: none, outputs to console
*/
void testFnc(ARRAY_TYPE arr[])
{
	////test shiftLeft
	test_shiftLeft(arr, 2);
	////test shiftRight
	test_shiftRight(arr, 2);

	
}