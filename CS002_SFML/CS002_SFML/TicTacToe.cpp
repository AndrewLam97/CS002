#include "TicTacToe.h"
//#include <iostream>
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

void TicTacToe::drawSprites()
{
	for (int i = 0; i < spriteVec.size(); i++)
	{
		for (int j = 0; j < spriteVec[i].size(); j++)
		{
			window.draw(spriteVec[i][j]);
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
		drawTiles(); //draw tileVec
		//drawSprites();
		window.display();
	}
}

void TicTacToe::init()
{
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
	//tileVec[0][0].setPos(boxStart, 0);
	tileVec[0][0].setTile('x');
	//tileVec[0][1].setPos(boxStart + boxSize + spacer, 0);
	tileVec[0][1].setTile('o');
	//tileVec[0][2].setPos(boxStart + 2 * boxSize + 2 * spacer, 0);
	//tileVec[0][2].setTile('b');
	//tileVec[1][1].setPos(boxStart + boxSize + spacer, boxSize + spacer);
	//tileVec[1][1].setTile('x');


	/*for (int i = 0; i < 3; i++)
	{
		xPos = 0;
		spriteVec.push_back(std::vector<sf::Sprite>());
		for (int j = 0; j < 3; j++)
		{
			xPos += (boxSize + spacer);
			sf::Sprite sprite;
			sprite.setPosition(xPos, yPos);
			spriteVec[i].push_back(sprite);
		}
		yPos += (boxSize + spacer);
	}*/

	drawBoard();
}

TicTacToe::TicTacToe()
	:window(sf::VideoMode(1920, 1080, 32), "Tic Tac Toe")
{
	init();
}
