#include "TicTacToe.h"
//#include <iostream>

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
		//window.draw(tile.getSprite()); //test tile
		drawTiles(); //draw tileVec
		window.display();
	}
}

void TicTacToe::init()
{
	sf::Vector2u winSize = window.getSize();
	float boxStart = (winSize.x - winSize.y) / 2.f;
	int spacer = 30;
	float boxSize = (winSize.y - (spacer * 2)) / 3.f;
	
	left.setSize(sf::Vector2f(boxStart, winSize.y));
	left.setPosition(0, 0);
	left.setFillColor(sf::Color::White);
	
	right.setSize(sf::Vector2f(boxStart, winSize.y));
	right.setPosition(winSize.x - boxStart, 0);
	right.setFillColor(sf::Color::White);

	//create tileVec
	for (int i = 0; i < 3; i++)
	{
		tileVec.push_back(std::vector<Tile>());
		for (int j = 0; j < 3; j++)
		{
			Tile tile;
			tileVec[i].push_back(tile);
		}
	}

	//test tiles
	tile.setTile('x');
	tile.setPos(boxStart, 0);

	tileVec[0][0].setPos(boxStart, 0);
	tileVec[0][0].setTile('x');
	tileVec[0][1].setPos(boxStart + boxSize + spacer, 0);
	tileVec[0][1].setTile('x');
	tileVec[1][1].setPos(boxStart + boxSize + spacer, boxSize + spacer);
	tileVec[1][1].setTile('x');


	drawBoard();
}

TicTacToe::TicTacToe()
	:window(sf::VideoMode(1920, 1080, 32), "Tic Tac Toe")
{
	init();
}
