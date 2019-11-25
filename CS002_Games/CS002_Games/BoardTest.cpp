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
	int ROWS = 10, COLS = 10;
	Board board(ROWS, COLS, '\0');
	board.setROWS(ROWS);
	board.setCOLS(COLS);
	board.print();
}
