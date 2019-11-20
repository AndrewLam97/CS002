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
	int ROWS = 6, COLS = 7;
	Board board(ROWS, COLS, 'X');
	board.setROWS(ROWS);
	board.setCOLS(COLS);
	board.print();
}
