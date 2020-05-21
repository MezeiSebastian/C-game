#pragma once
#include"Input.h"
#include"Player.h"
#include"BoardData.h"
#include"Init.h"
#include"Deck.h"
#include"ConsoleGraphics.h"
#include"EventCard.h"
#include<vector>

class Gameplay
{ 
private:

public:

	void InitializeGame(std::vector<Player>& allPlayers, Deck& playerDeck, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board, Input& userInput);

	template <typename Arg, typename... Args>
	void SystemOut(Arg&& arg, Args&&... args)
	{
		std::cout << std::forward<Arg>(arg);
		using expander = int[];
		(void)expander {
			0, (void(std::cout << ',' << std::forward<Args>(args)), 0)...
		};
	}

	void GeneratePlayers(int16_t numberOfPlayers, std::vector<Player>& allPlayers, BoardData& board,Input playerRole);
	void CardDraw(int playerNumber, Deck& playerDeck, std::vector<Player>& allPlayers, int& k, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board);
	bool EventCardHandler(std::vector<Player>& allPlayers, int16_t playerNumber, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board);
	bool SelectAction(Player& player, Input& userInput, BoardData& board, std::vector<Player>& allPlayers);
	void SplitPlayerCards(std::vector<Player>& allPlayers, Deck& playerDeck);
	void InfectCities(Deck& infectionDeck, Deck& DiscardedInfectionDeck, BoardData& board);
	void InfectionCardActions(BoardData& board, Deck& infectionDeck, Deck& DiscardedInfectionDeck);
	void ChoseEventActions(EventCard eCard, std::vector<Player>& allPlayers, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board);
	void StartGame();
	void LossingConditions( BoardData& board, Deck& infectionDeck) const ;
	const bool WiningCondition(BoardData& board) const;
};


