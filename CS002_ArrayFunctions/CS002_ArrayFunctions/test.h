#pragma once
typedef int ARRAY_TYPE;

void test_fillArrayCons(ARRAY_TYPE arr[], int& num_used);
void test_fillArrayRand(ARRAY_TYPE arr[], int& num_used);
//void test_print();

void test_append(ARRAY_TYPE arr[], int& num_used);

void test_shiftLeft(ARRAY_TYPE arr[], int& num_used, int mark);
void test_shiftRight(ARRAY_TYPE arr[], int& num_used, int mark);

void test_selectionSort(ARRAY_TYPE arr[], int& num_used);
void test_bubbleSort(ARRAY_TYPE arr[], int& num_used);

void testFnc(ARRAY_TYPE arr[], int& num_used);