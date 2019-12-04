#include "TicTacToe.h"
//#include <iostream>

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

	for(int i = 0; i < 3;)

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
		window.display();
	}
}

TicTacToe::TicTacToe()
	:window(sf::VideoMode(1920, 1080, 32), "Tic Tac Toe")
{
	init();
}
