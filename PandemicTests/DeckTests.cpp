#include "pch.h"
#include "CppUnitTest.h"
#include "Deck.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PandemicTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(AddCardtest)
		{
			const int32_t population = 1000;
			const std::string cityName = "A";
			const EVirus virusType = EVirus::BlackVirus;
			const int16_t cityId = 1;
			CityCard card(population, cityName, virusType, cityId);
			std::deque<CityCard> CityDeck;
			size_t size = CityDeck.size();
			CityDeck.push_back(card);
			if (size == CityDeck.size())
				Assert::Fail();
		}
		TEST_METHOD(GetTopCardtest)
		{
			std::deque<CityCard> CityDeck;
			const int32_t population = 1000;
			const std::string cityName = "A";
			const EVirus virusType = EVirus::BlackVirus;
			const int16_t cityId = 1;
			CityCard cityCard(population, cityName, virusType, cityId);
			const int32_t population2 = 2000;
			const std::string cityName2 = "B";
			const EVirus virusType2 = EVirus::BlackVirus;
			const int16_t cityId2 = 2;
			CityCard cityCard2(population2, cityName2, virusType2, cityId2);

			CityDeck.push_back(cityCard);
			CityDeck.push_back(cityCard2);
			CityCard cityCardfront = CityDeck.front();
			auto&& intermediary = std::move(CityDeck.front());
			CityDeck.pop_front();
				std::move(intermediary);
				if (cityCardfront.GetCityId() == CityDeck.front().GetCityId())
					Assert::Fail();
		}
	};
}