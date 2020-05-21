#include "PlayerDeck.h"

#include<time.h>

PlayerDeck::PlayerDeck(const ELevel level)
{
	if (level == ELevel::Easy)
		m_epidemicCards.resize(4);
	else if (level == ELevel::Medium)
		m_epidemicCards.resize(5);
	else m_epidemicCards.resize(6);
}

constexpr void PlayerDeck::GeneratePlayerDeck(const ELevel& level)
{
	for (int index = 0; index < 48; index++)
	{
		std::srand(time(NULL));
		int population = 10000000 + rand() % 20000000;
		m_cityCards[index] = CityCard(population, ECity(index));
	}
}
