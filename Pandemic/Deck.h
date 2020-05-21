#pragma once
#include"CityCard.h"
#include<deque>
#include<vector>
class Deck
{
private:
	std::deque<CityCard> m_CityDeck;
	int16_t m_numberOfEventCards = 6;
	int16_t m_numberOfEpidemicCards;
public:
	const int16_t ChooseCardToDraw() ;
	void GenerateDeck();
	void SetNumberOfEpidemicCards(int16_t numberOfEpidemicCards);
	void AddCard(const CityCard& card);
	CityCard&& GetTopCard() ;
	void ShuffleTheDeck();
	const size_t GetNumberOfCards() const;



};

