#include "BoardTest.h"
#include "Board.h"
#include "BoardTest.h"

void test_fnc()
{
	//test_Constructor();
	test_DefConstructor();
}

void test_Constructor()
{
	cout << "Testing default constructor..." << endl;
	Board board;
	board.print();
}

void test_DefConstructor()
{
	cout << "Testing overloaded constructor..." << endl;
	int ROW_SIZE = 3, COL_SIZE = 3;
	Board board(ROW_SIZE, COL_SIZE, 'X');
	board.setROW_SIZE(ROW_SIZE);
	board.setCOL_SIZE(COL_SIZE);
	board.print();
}
