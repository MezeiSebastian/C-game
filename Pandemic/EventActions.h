#pragma once
#include"Deck.h"
#include"Player.h"
#include"BoardData.h"
class EventActions
{

/*"Draw, look at, and rearrange the top 6 cards of the infection deck.Put them back on top."
"Remove any 1 card in the infection discard pile from the game.You may play this between the infect and intensify steps of an epidemic."
"Move any 1 pawn to any city.Get permission before moving another players's pawn."
"Add 1 research station to any city(no city card needed)."
"Skip the next infect cities step(do not flip over any infection cards)."*/

public:
	static void Event1(Deck& infectionDeck);
	static void Event2(Deck& discardedDeck);
	static void Event3(std::vector<Player>& allPlayers,BoardData& board);
	static void Event4(BoardData& board);
	static void Event5();
};


