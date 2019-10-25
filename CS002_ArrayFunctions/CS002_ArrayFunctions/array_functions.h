#pragma once

void fillArrayRand(int array[]);  //fills each element in the array with random integers
void fillArrayCons(int array[], int value); //fills each element in the array with value
void printArray(int array[]); //print all indexed variables in my array
void appendArray(int array[], int &capacity, int value); //appends value to end of array
void copyArray(int array[], int array2[]); //copies the content of array1 into array2
//int search(int array[], int value); //return the index of the value sent

void shiftRight(int array[], int index);
void shiftLeft(int array[], int index);

void swap(int array[], int pos1, int pos2);
void selectionSort(int array[]);
void bubbleSort(int array[]);

