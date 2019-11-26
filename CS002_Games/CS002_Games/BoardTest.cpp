#include "BoardTest.h"
#include "Board.h"
#include "BoardTest.h"

void test_fnc()
{
	//test_Constructor();
	//test_DefConstructor();
	test_Pieces();
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
	board.print();
}

void test_Pieces()
{
	cout << "Testing piece manipulation..." << endl;
	int ROWS = 10, COLS = 10;
	Board board(ROWS, COLS, '\0');
	Move move = { 0,0, 'x' };
	board.addPiece(move);
	move = { 0,1, 'x' };
	board.addPiece(move);
	move = { 0,2, 'x' };
	board.addPiece(move);
	board.print();
	cout << endl << "Removing move at (0,2)" << endl;
	board.removePiece(move);
	board.print();
}
