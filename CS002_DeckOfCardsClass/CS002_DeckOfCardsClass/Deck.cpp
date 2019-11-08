#include "Deck.h"
#include "Card.h"

bool Deck::deckFull()
{
	return uniqueCards == 52 ? 1 : 0;
}