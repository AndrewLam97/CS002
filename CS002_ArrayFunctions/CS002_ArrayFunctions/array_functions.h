#pragma once
typedef int ARRAY_TYPE;

void fillArrayRand(ARRAY_TYPE array[]);  //fills each element in the array with random integers
void fillArrayCons(ARRAY_TYPE array[], int value); //fills each element in the array with value
void printArray(ARRAY_TYPE array[]); //print all indexed variables in my array
void appendArray(ARRAY_TYPE array[], int &capacity, int value); //appends value to end of array
void copyArray(ARRAY_TYPE array[], int array2[]); //copies the content of array1 into array2
int search(ARRAY_TYPE array[], int value); //return the index of the value sent

void shiftLeft(ARRAY_TYPE array[], int index);
void shiftRight(ARRAY_TYPE array[], int index);


void swap(ARRAY_TYPE array[], int pos1, int pos2);
void selectionSort(ARRAY_TYPE array[]);
void bubbleSort(ARRAY_TYPE array[]);

