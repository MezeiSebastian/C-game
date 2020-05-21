#include "Deck.h"
#include<vector>
#include <ctime>
#include <algorithm>
#include<string>
#include <random>
#include <array>
#include <chrono>

const int16_t Deck::ChooseCardToDraw() 
{
	auto numberOfChoices = m_CityDeck.size() + m_numberOfEventCards + m_numberOfEpidemicCards;
	srand(time(NULL));
	auto typeToDraw = rand() % numberOfChoices;
	enum CardType {
		CITYCARD,
		EVENTCARD,
		EPIDEMICCARD
	};
	if (typeToDraw < m_CityDeck.size()) {
		return CardType::CITYCARD;
	}
	else if (typeToDraw < m_CityDeck.size() + m_numberOfEventCards) {
		--m_numberOfEventCards;
		return CardType::EVENTCARD;
		
	}
	else {
		--m_numberOfEpidemicCards;
		return CardType::EPIDEMICCARD;
	}
}

void Deck::GenerateDeck() {
	srand(time(NULL));
	const std::array<std::string,49> cityNames
	{ "SanFrancisco",
	 "Chicago",
	 "Atlanta",
	 "Montreal",
	 "NewYork",
	 "London",
	 "Paris",
	 "StPetersburg",
	 "Milan",
	 "Essen",
	 "Madrid",
	 "Washington",

	 "LosAngeles",
	 "MexicoCity",
	 "Miami",
	 "Bogota",
	 "Lima",
	 "SaoPaulo",
	 "BuenosAries",
	 "Santiago",
	 "Lagos",
	 "Khartoum",
	 "Kinshasa",
	 "Johannesburg",

	 "Algiers",
	 "Istanbul",
	 "Moscow",
	 "Cairo",
	 "Tehran",
	 "Karachi",
	 "Kolkata",
	 "Delhi",
	 "Mumbai",
	 "Riyadh",
	 "Chennai",
	 "Baghdad",


	 "Bangkok",
	 "Beijing",
	 "HoChiMinhCity",
	 "HongKong",
	 "Jakarta",
	 "Manila",
	 "Osaka",
	 "Seoul",
	 "Shanghai",
	 "Sydney",
	 "Taipei",
	 "Tokyo",
	};
	auto intermediaryVirus = EVirus::BlackVirus;
	for (int i = 0; i < 48;++i) {
		auto population = 1000000 + rand() % 10000000;
		m_CityDeck.emplace_back(CityCard(population,cityNames[i],intermediaryVirus,i));
		if (i/12==1) {
			intermediaryVirus = EVirus::BlueVirus;
		}
		if(i/24==1) {
			intermediaryVirus = EVirus::RedVirus;
		}
		if (i/32==1) {
			intermediaryVirus = EVirus::YellowVirus;
		}
	}
	
}
void Deck::SetNumberOfEpidemicCards(int16_t numberOfEpidemicCards)
{
	m_numberOfEpidemicCards = numberOfEpidemicCards;
}
void Deck::AddCard(const CityCard& card)
{
	m_CityDeck.push_back(card);
}
CityCard&& Deck::GetTopCard()
{
	auto&& intermediary = std::move(m_CityDeck.front());
	m_CityDeck.pop_front();
	return std::move(intermediary);
}
void Deck::ShuffleTheDeck()
{
	srand(time(NULL));
	auto size = m_CityDeck.size();
	
	std::random_shuffle(m_CityDeck.begin(), m_CityDeck.end());
	
}
const size_t Deck::GetNumberOfCards() const {
	return m_CityDeck.size();
}