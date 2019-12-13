#include "TicTacToe.h"
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
	while (window.isOpen() && gameRunning == true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			//else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			//{
			//	if (mode == 1)
			//	{
			//		if (player == true)
			//		{
			//			Move move = getClick();
			//			move.piece = 'x';
			//			tttBoard.addPiece(move);
			//			turn++;
			//			player = false;
			//		}
			//	}
			//	if (mode == 2)
			//	{
			//		Move move = getClick();
			//		if (tttBoard.isValidMove(move))
			//		{
			//			if (player == true)
			//			{
			//				move.piece = 'x';
			//			}
			//			else if (player == false)
			//			{
			//				move.piece = 'o';
			//			}
			//			player = !player;
			//			tttBoard.addPiece(move);
			//			turn++;
			//		}
			//	}
			//}
			//if (mode == 1)
			//{
			//	if (player == false)
			//	{
			//		Move move = aiP.AIturn(tttBoard);
			//		tttBoard.addPiece(move);
			//		turn++;
			//		player = true;
			//	}
			//}
		}
		if (mode == 1)
		{
			if (player == false)
			{
				Move move = aiP.AIturn(tttBoard);
				tttBoard.addPiece(move);
				turn++;
				player = true;
			}
		}
		if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			Move move = getClick();

			if (mode == 1 && player == true && tttBoard.isValidMove(move))
			{
				move.piece = 'x';
				tttBoard.addPiece(move);
				turn++;
				player = false;
			}
			if (mode == 2 && tttBoard.isValidMove(move))
			{
				if (player == true)
				{
					move.piece = 'x';
				}
				else if (player == false)
				{
					move.piece = 'o';
				}
				player = !player;
				tttBoard.addPiece(move);
				turn++;
			}
		}
		switch (gameState())
		{
		case 1:
			std::cout << "x wins!" << endl;
			gameRunning = false;
			break;
		case 2:
			std::cout << "o wins!" << endl;
			gameRunning = false;
			break;
		case 3:
			std::cout << "Tie!" << endl;
			gameRunning = false;
			break;
		}

		window.clear(sf::Color::Black);
		window.draw(left);
		window.draw(right);
		updateBoard(tttBoard); //update tileVec from board
		drawTiles(); //draw tileVec
		window.display();
	}
}

int TicTacToe::gameState()
{
	if (tttBS.countAll(tttBoard, 'o') == 3)
		return 2;
	if (tttBS.countAll(tttBoard, 'x') == 3)
		return 1;
	if (turn == 9) //tie
		return 3;
	else
		return 0;
}

void TicTacToe::updateBoard(Board tttBoard) //update tileVec from board
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			tileVec[i][j].setTile(tttBoard.getPiece(i, j));
		}
	}
}

Move TicTacToe::getClick()
{
	Move move{};
	auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
	auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (tileVec[i][j].getSprite().getGlobalBounds().contains(translated_pos)) //check if sprite contains mouse coords
				move = { i, j, 'x' };
		}
	}
	return move;
}

void TicTacToe::init()
{
	std::cout << "Enter 1 for single player or 2 for two player: " << endl;
	char input;
	std::cin >> input;
	if (input == '1')
	{
		mode = 1;
	}
	if (input == '2')
	{
		mode = 2;
	}

	Board tttBoard(3, 3, '\0'); //initialize Board 
	BoardScorer tttBS; //initialize BoardScorer
	AI aiP;

	std::cout << "Starting game!" << endl;
	//window.setKeyRepeatEnabled(false);
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

	drawBoard();
}

TicTacToe::TicTacToe()
	:window(sf::VideoMode(1920, 1080, 32), "Tic Tac Toe")
{
	init();
}
