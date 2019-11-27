#pragma once
typedef int ARRAY_TYPE;

void test_fillArrayCons(ARRAY_TYPE arr[], int& num_used);
void test_fillArrayRand(ARRAY_TYPE arr[], int& num_used);

void test_append(ARRAY_TYPE arr[], int& num_used);
void appendArray(ARRAY_TYPE arr[], int& num_used, ARRAY_TYPE srcArr[], int src_num_used);

void test_remove(ARRAY_TYPE arr[], int& num_used, int mark);

void test_shiftLeft(ARRAY_TYPE arr[], int& num_used, int mark);
void test_shiftRight(ARRAY_TYPE arr[], int& num_used, int mark);

void test_insertBefore(ARRAY_TYPE arr[], int& num_used, int item, int mark);
void test_insertAfter(ARRAY_TYPE arr[], int& num_used, int item, int mark);
void test_search(ARRAY_TYPE arr[], int& num_used, int value);

void test_reverse(ARRAY_TYPE arr[], int num_used);
void test_deleteRepeats(ARRAY_TYPE arr[], int& num_used);

void test_selectionSort(ARRAY_TYPE arr[], int& num_used, bool ascending);
void test_bubbleSort(ARRAY_TYPE arr[], int& num_used, bool ascending);

void testFnc(ARRAY_TYPE arr[], int& num_used);