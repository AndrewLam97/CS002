#include "TicTacToe.h"
//sprite.getGlobalBounds().contains(mousePos)	

void TicTacToe::drawTiles()
{
	for (int i = 0; i < tileVec.size(); i++)
	{
		for (int j = 0; j < tileVec[i].size(); j++)
		{
			window.draw(tileVec[i][j].getSprite());
		}
	}
}

void TicTacToe::drawBoard()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		window.draw(left);
		window.draw(right);
		updateBoard(tttBoard); //update tileVec from board
		drawTiles(); //draw tileVec
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //TEST BOARD UPDATE
		{
			Move move{ 1, 1, 'x' };
			tttBoard.addPiece(move);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //TEST BOARD UPDATE
		{
			Move move{ 2, 2, 'o' };
			tttBoard.addPiece(move);
		}
	}
}

void TicTacToe::updateBoard(Board tttBoard) //update tileVec from board
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			tileVec[i][j].setTile(tttBoard.getPiece(i,j));
		}
	}
}

void TicTacToe::init()
{
	Board tttBoard(3, 3, '\0'); //initialize Board 
	BoardScorer tttBS; //initialize BoardScorer

	sf::Vector2u winSize = window.getSize();
	float boxStart = (winSize.x - winSize.y) / 2.f;
	std::cout << "boxStart: " << boxStart << std::endl;
	int spacer = 30;
	std::cout << "spacer: " << spacer << std::endl;
	float boxSize = (winSize.y - (spacer * 2)) / 3.f;
	std::cout << "boxSize: " << boxSize << std::endl;
	
	left.setSize(sf::Vector2f(boxStart, winSize.y));
	left.setPosition(0, 0);
	left.setFillColor(sf::Color::White);
	
	right.setSize(sf::Vector2f(boxStart, winSize.y));
	right.setPosition(winSize.x - boxStart, 0);
	right.setFillColor(sf::Color::White);

	float xPos = 0;
	float yPos = 0;

	//create tileVec
	for (int i = 0; i < 3; i++)
	{
		xPos = boxStart;
		tileVec.push_back(std::vector<Tile>());
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) xPos = boxStart;
			else xPos += (boxSize + spacer);

			Tile tile;
			tile.setPos(xPos, yPos);
			tileVec[i].push_back(tile);
		}
		yPos += (boxSize + spacer);
	}

	////TEST TILE VEC
	//tileVec[0][0].setTile('x');
	//tileVec[0][1].setTile('o');
	//tileVec[0][2].setTile('x');
	//tileVec[1][0].setTile('o');
	//tileVec[1][1].setTile('x');
	//tileVec[1][2].setTile('x');
	//tileVec[2][0].setTile('x');
	//tileVec[2][1].setTile('o');
	//tileVec[2][2].setTile('o');

	drawBoard();
}

TicTacToe::TicTacToe()
	:window(sf::VideoMode(1920, 1080, 32), "Tic Tac Toe")
{
	init();
}
