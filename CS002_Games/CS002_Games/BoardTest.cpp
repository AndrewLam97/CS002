#include "BoardTest.h"
#include "Board.h"
#include "BoardTest.h"

void test_fnc()
{
	
}

void test_Constructor()
{
	Board board;
}

void test_DefConstructor()
{
	Board board(10, 10, 'X');
}

void test_Print()
{
	cout << "Testing default constructor..." << endl;
	test_Constructor();
	print();
}