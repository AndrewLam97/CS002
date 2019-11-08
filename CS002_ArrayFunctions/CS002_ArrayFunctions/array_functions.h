#pragma once
typedef int ARRAY_TYPE;

void fillArrayRand(ARRAY_TYPE array[], int& num_used);  //fills each element in the array with random integers
void fillArrayCons(ARRAY_TYPE array[], int& num_used, int value); //fills each element in the array with value
void printArray(ARRAY_TYPE array[],int num_used); //print all indexed variables in my array
void append(ARRAY_TYPE array[], int &capacity, int value); //appends value to end of array
void appendArray(ARRAY_TYPE array[], int& num_used, ARRAY_TYPE sourceArray[], int src_num_used);
void copyArray(ARRAY_TYPE array[], int num_used, ARRAY_TYPE array2[]); //copies the content of array1 into array2
int search(ARRAY_TYPE array[], int num_used, int value); //return the index of the value sent

void shiftLeft(ARRAY_TYPE array[], int& num_used, int mark);
void shiftRight(ARRAY_TYPE array[], int& num_used, int mark);

void insert_before(ARRAY_TYPE array[], int& num_used, int item, int mark);
void insert_after(ARRAY_TYPE array[], int& num_used, int item, int mark);
void remove(ARRAY_TYPE array[], int& num_used, int mark);
void reverse(ARRAY_TYPE array[], int num_used);
void deleteRepeats(ARRAY_TYPE array[], int& num_used);

void swap(ARRAY_TYPE array[], int pos1, int pos2);
void selectionSort(ARRAY_TYPE array[], int num_used, bool ascending);
void bubbleSort(ARRAY_TYPE array[], int num_used, bool ascending);

