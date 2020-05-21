#include "EventActions.h"
#include"CityCard.h"
#include<vector>
#include<algorithm>

void EventActions::Event1(Deck& infectionDeck)
{
	auto size = 6;
	auto intermediary = std::vector<CityCard>{};
	auto cardsOrder = std::vector<int>{};
	if (infectionDeck.GetNumberOfCards() < 6) {
		size = infectionDeck.GetNumberOfCards();
	}
	for (auto i = 0; i < size; ++i) {
		auto intermediar = 0;
		std::cout << "The order of cards is:";
		std::cin >> intermediar;
		cardsOrder.push_back(intermediar);
	}
	for (auto i = 0; i < size; ++i) {
		intermediary.push_back(infectionDeck.GetTopCard());
		infectionDeck.AddCard(intermediary.at(cardsOrder[i]));
	}

}

void EventActions::Event2(Deck& discardedDeck)
{
	auto cardId = 0;
	std::cout << "Id carti este";
	std::cin >> cardId;
	auto intermediary = std::vector<CityCard>{};
	auto size = discardedDeck.GetNumberOfCards();
	for (auto i = 0; i < size; ++i) {
		intermediary.push_back(discardedDeck.GetTopCard());
	}
	std::remove_if(intermediary.begin(), intermediary.end(), [cardId](CityCard& card) {return card.GetCityId() == cardId; });
	for (auto i = 0; i < size; ++i) {
		discardedDeck.AddCard(intermediary.at(i));
	}
}

void EventActions::Event3(std::vector<Player>& allPlayers,BoardData& board)
{
	auto playerId = 0;
	auto cityId = 0;
	std::cout << "The pawn you want to move is:";
	std::cin >> playerId;
	std::cout << "The city number is:";
	std::cin >> cityId;
	allPlayers.at(playerId).SetCity(board.GetCity(cityId));

}

void EventActions::Event4(BoardData& board)
{
	auto cityId = 0;
	std::cout << "The city number is:";
	std::cin >> cityId;
	board.GetCity(cityId).SetResearchStation(true);

}

void EventActions::Event5()
{

}
