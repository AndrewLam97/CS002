#pragma once
#include <SFML/Graphics.hpp>

class TicTacToe
{
protected:
private:
	sf::RectangleShape squares[9], left, right;
	sf::RenderWindow window;

	sf::Texture texture;

public:
	void init();
	TicTacToe();
};

