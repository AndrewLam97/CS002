/*
	Assignment 4 - Blackjack
	Andrew Lam
	9-30-19
	PURPOSE: Blackjack
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

/*
NAME: scoreHand
PURPOSE: scores a hand of cards
PARAMETERS: pCard or dCard, vector containing card values
RETURN VALUES: integer of summed values
*/
int scoreHand(vector<int> card)
{
	int score = 0;
	for (int i = 0; i < card.size(); i++) //loops through vector summing numbers
	{
		score += card[i];
	}
	return score;
}

/*
NAME: dealCard
PURPOSE: deals a random card valued between 2-11 
PARAMETERS: none
RETURN VALUES: integer of card value dealt
*/
int dealCard() //deals a card valued at 2-11
{
	random_device rd; 
	mt19937 mt_rand(rd()); //seeds generator
	uniform_int_distribution<int> gen(2, 11); //generate number between 2 and 11
	int cardVal = gen(mt_rand);
	//cout << "Dealt card: " << cardVal << endl;
	return cardVal;
}

/*
NAME: evalScore
PURPOSE: scores final hands and determines game outcome, win, loss, or draw. cout's game outcome.
PARAMETERS: pScore and dScore, players' hand values
RETURN VALUES: 0 upon completion
*/
int evalScore(int pScore, int dScore)
{
	if (pScore == dScore)
	{
		cout << "Draw!" << endl;
		return 0;
	}
	if (pScore == 21)
	{
		cout << "Player wins!" << endl;
		return 0;
	}
	if (dScore == 21)
	{
		cout << "Dealer wins!" << endl;
		return 0;
	}
	if (pScore > 21)
	{
		cout << "Player busts!" << endl;
		cout << "Dealer wins!" << endl;
		return 0;
	}
	if (dScore > 21)
	{
		cout << "Dealer busts!" << endl;
		cout << "Player wins!" << endl;
		return 0;
	}
	if (pScore > dScore)
	{
		cout << "Player wins!" << endl;
		return 0;
	}
	else
	{
		cout << "Dealer wins!" << endl;
		return 0;
	}
}

int main()
{
	int pScore = 0, dScore = 0;
	vector<int> pCard;
	vector<int> dCard;

	pCard.emplace_back(dealCard()); //initial hands
	pCard.emplace_back(dealCard());
	dCard.emplace_back(dealCard());
	dCard.emplace_back(dealCard());

	pScore = scoreHand(pCard); //calculate initial hand scores
	dScore = scoreHand(dCard);

	if (pScore > 21)pScore -= 10; //handles double aces
	if (dScore > 21)dScore -= 10; //end initial hands

	cout << "Dealing initial hand..." << endl;
	cout << "Player score is: " << pScore << "\t" << "Dealer score is: " << dScore << endl;

	while (pScore < 21 && dScore < 21 && true) //loops player and dealer hit options until a bust occurs or both player stand
	{
		if (pScore < 21) { //player hit option y/n
			char entry;
			cout << "Player hit? y/n" << endl;
			cin >> entry;

			if (entry == 'y') //player hits
			{
				int dealtCard = dealCard();
				if (dealtCard == 11) //handles ace causing player to bust
				{
					if (pScore + dealtCard > 21) 
					{
						dealtCard = 1;
					}
				}
				pCard.emplace_back(dealtCard); //updates player hand vector
				cout << "Dealt " << dealtCard << " to player." << endl;
				pScore = scoreHand(pCard);
				cout << "Player's hand is: " << pScore << endl;
				if (pScore > 21)
				{
					//cout << "Player busts!" << endl;
					break;
				}
			}
			else
			{
				if (dScore < 17) //dealer hits if 16 or below
				{
					int dealtCard = dealCard();
					if (dealtCard == 11) //handles ace
					{
						if (dScore + dealtCard < 21 && dScore + dealtCard > 17)
						{
							dealtCard = 1;
						}
					}
					dCard.emplace_back(dealtCard); //update dealer hand vector
					cout << "Dealt " << dealtCard << " to dealer." << endl;
					dScore = scoreHand(dCard);
					cout << "Dealer's hand is: " << dScore << endl;
					if (dScore > 21)
					{
						//cout << "Dealer busts!" << endl;
						break;
					}
				}
				break;
			}
		}
		if (dScore < 17) //dealer hit if player stands
		{
			int dealtCard = dealCard();
			if (dealtCard == 11)
			{
				if (dScore + dealtCard < 21 && dScore + dealtCard > 17)
				{
					dealtCard = 1;
				}
			}
			dCard.emplace_back(dealtCard);
			cout << "Dealt " << dealtCard << " to dealer." << endl;
			dScore = scoreHand(dCard);
			cout << "Dealer's hand is: " << dScore << endl;
		}
	}
	//cout << "EVAL" << pScore << "\t" << dScore << endl;
	cout << endl;
	evalScore(pScore, dScore); //evaluate player and dealer scores

}