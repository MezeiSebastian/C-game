#pragma once
#include<array>
#include<vector>


#include"CityCard.h"
#include"EpidemicCard.h"
#include"EventCard.h"
#include"ELevel.h"


class PlayerDeck
{
public:

	PlayerDeck(const ELevel level);
	constexpr void GeneratePlayerDeck(const ELevel& level);
public:
	std::array<CityCard,48> m_cityCards;
	std::vector<EpidemicCard> m_epidemicCards;
	std::array<EventCard,5> m_eventCards;
};