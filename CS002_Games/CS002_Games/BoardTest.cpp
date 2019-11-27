#include "BoardTest.h"
#include "Board.h"
#include "BoardScorer.h"

void test_fnc()
{
	//test_Constructor();
	//test_DefConstructor();
	//test_Pieces();
	//test_Horizontal();
	//test_Vertical();
	//test_Diagonal();
	//test_Diagonal1();
	//test_Diagonal2();
	//test_DiagonalAlt();
	test_DiagonalAlt1();
	test_DiagonalAlt2();
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
	cout << endl << "Removing piece at (0,2)" << endl;
	board.removePiece(move);
	board.print();
}

void test_Horizontal()
{
	cout << "Testing horizontal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 5; i++)
	{
		Move move = { 0,i,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Horizontal count for " << p1 << ": " << bscore.countHorizontal(board, 0, p1) << endl << endl;
	cout << "Removing piece at (0,3)..." << endl;
	Move move = { 0,3,'x' };
	board.removePiece(move);
	board.print();
	cout << "Horizontal count for " << p1 << ": " << bscore.countHorizontal(board, 0, p1) << endl;
}

void test_Vertical()
{
	cout << "Testing vertical counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 10; i++)
	{
		Move move = { i,9,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Vertical count for " << p1 << ": " << bscore.countVertical(board, 9, p1) << endl << endl;
	cout << "Removing piece at (7,9)..." << endl;
	Move move = { 7,9,'x' };
	board.removePiece(move);
	board.print();
	cout << "Vertical count for " << p1 << ": " << bscore.countVertical(board, 9, p1) << endl;
	cout << "Removing piece at (2,9)..." << endl;
	move = { 2,9,'x' };
	board.removePiece(move);
	board.print();
	cout << "Vertical count for " << p1 << ": " << bscore.countVertical(board, 9, p1) << endl;
}

void test_Diagonal()
{
	cout << "Testing TLBR diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 10; i++)
	{
		Move move = { i,i,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 0, 0, p1) << endl << endl;
	Move move = { 3,3,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 0, 0, p1) << endl << endl;
}

void test_Diagonal1()
{
	cout << "Testing TLBR diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 2; i < 10; i++)
	{
		int j = i - 2;
		Move move = { i,j,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 4, 2, p1) << endl << endl;
	cout << "Removing piece at (4,2)..." << endl;
	Move move = { 4,2,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 9, 7, p1) << endl << endl;
}

void test_Diagonal2()
{
	cout << "Testing TLBR diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 8; i++)
	{
		int j = i + 2;
		Move move = { i,j,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 7, 9, p1) << endl << endl;
	cout << "Removing piece at (3,5)..." << endl;
	Move move = { 3,5,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonal(board, 7, 9, p1) << endl << endl;
}

void test_DiagonalAlt()
{
	cout << "Testing TRBL diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 10; i++)
	{
		int j = 9 - i;
		Move move = { i,j,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 0, 9, p1) << endl << endl;
	cout << "Removing piece at (5,4)..." << endl;
	Move move = { 5,4,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 0, 9, p1) << endl << endl;
}

void test_DiagonalAlt1()
{
	cout << "Testing TRBL diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 0; i < 9; i++)
	{
		int j = 8 - i;
		Move move = { i,j,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 8, 0, p1) << endl << endl;
	cout << "Removing piece at (6,2)..." << endl;
	Move move = { 6,2,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 0, 8, p1) << endl << endl;
}

void test_DiagonalAlt2()
{
	cout << "Testing TRBL diagonal counter..." << endl;
	int ROWS = 10, COLS = 10;
	char p1 = 'x';
	Board board(ROWS, COLS, '\0');
	for (int i = 4; i < 10; i++)
	{
		int j = 12 - i;
		Move move = { i,j,p1 };
		board.addPiece(move);
	}
	board.print();
	BoardScorer bscore;
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 5, 7, p1) << endl << endl;
	cout << "Removing piece at (8,4)..." << endl;
	Move move = { 8,4,'x' };
	board.removePiece(move);
	board.print();
	cout << "Diagonal count for " << p1 << ": " << bscore.countDiagonalAlt(board, 9, 3, p1) << endl << endl;
}