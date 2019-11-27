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
	fillArrayCons(arr, num_used, value);
	cout << "Filled array with " << value << endl;
	printArray(arr,num_used);
	cout << endl;
}

void test_fillArrayRand(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing random fill..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	fillArrayRand(arr, num_used);
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

void test_appendArray(ARRAY_TYPE arr[], int& num_used, ARRAY_TYPE srcArr[], int src_num_used)
{
	cout << "Testing append array..." << endl;
	cout << "Destination array: " << endl;
	fillArrayRand(arr, num_used);
	printArray(arr, num_used);
	cout << "Source array: " << endl;
	fillArrayRand(srcArr, src_num_used);
	printArray(srcArr, src_num_used);
	appendArray(arr, num_used, srcArr, src_num_used);
	cout << "Appended array: " << endl;
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

void test_remove(ARRAY_TYPE arr[], int& num_used, int mark)
{
	cout << "Testing remove..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	remove(arr, num_used, mark);
	cout << "Removed element at index = " << mark << ": " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_insertBefore(ARRAY_TYPE arr[], int& num_used, int item, int mark)
{
	cout << "Testing insert before..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	insert_before(arr, num_used, item, mark);
	cout << "Inserted " << item << " before index = " << mark << ": " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_insertAfter(ARRAY_TYPE arr[], int& num_used, int item, int mark)
{
	cout << "Testing insert after..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	insert_before(arr, num_used, item, mark);
	cout << "Inserted " << item << " after index = " << mark << ": " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_reverse(ARRAY_TYPE arr[], int num_used)
{
	cout << "Testing reverse..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	reverse(arr, num_used);
	cout << "Reversed array: " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_deleteRepeats(ARRAY_TYPE arr[], int& num_used)
{
	cout << "Testing delete repeats..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	cout << "Deleting repeats: " << endl;
	deleteRepeats(arr, num_used);
	printArray(arr, num_used);
	cout << endl;
}

void test_search(ARRAY_TYPE arr[], int& num_used, int value)
{
	cout << "Testing search..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	cout << "Searching array for value: " << value << endl;
	cout << "Found at index: " << search(arr, num_used, value);
	cout << endl << endl;
}

void test_selectionSort(ARRAY_TYPE arr[], int& num_used, bool ascending)
{
	cout << "Testing selectionSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	selectionSort(arr, num_used, true);
	cout << "Sorted array using selection sort: " << endl;
	printArray(arr, num_used);
	cout << endl;
}

void test_bubbleSort(ARRAY_TYPE arr[], int& num_used, bool ascending)
{
	cout << "Testing bubbleSort..." << endl;
	cout << "Original array: " << endl;
	printArray(arr, num_used);
	bubbleSort(arr, num_used, false);
	cout << "Sorted array using bubble sort: " << endl;
	printArray(arr, num_used);
	cout << endl;
}

/*
PURPOSE: driver function for testing functions
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
	test_shiftRight(arr, num_used, 3);

	int srcArr[8];
	int src_num_used = 8;

	test_appendArray(arr, num_used, srcArr, src_num_used);

	test_remove(arr, num_used, 5);

	test_insertBefore(arr, num_used, 12, 4);
	
	test_insertAfter(arr, num_used, 99, 7);

	test_search(arr, num_used, 12);
	
	test_reverse(arr, num_used);

	test_deleteRepeats(arr, num_used);

	test_selectionSort(arr, num_used, true);

	test_bubbleSort(arr, num_used, false);
}