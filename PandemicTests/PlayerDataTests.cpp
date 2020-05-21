#include "pch.h"
#include "CppUnitTest.h"
#include "PlayerData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PandemicTests
{
	TEST_CLASS(PlayerDataTests)
	{
	public:

		TEST_METHOD(DeleteCardTest)
		{
			const int32_t population = 1000;
			const std::string cityName = "A";
			const EVirus virusType = EVirus::BlackVirus;
			const int16_t cityId = 1;
			CityCard card(population, cityName, virusType, cityId);
			EVirus virus = card.GetVirus();
			std::vector<CityCard> cityCards;
			std::remove_if(cityCards.begin(), cityCards.end(), [&](CityCard& card) 
			{ return card.GetVirus() == card.GetVirus(); });
			if (virus != card.GetVirus())
				Assert::Fail();
		}

		TEST_METHOD(DiscardCardtest)
		{
			std::vector<CityCard> cityCards;
			City city;
			size_t size = cityCards.size();
			auto pred = [city](CityCard& intermediary) {return intermediary.GetCityName() == city.GetCityName(); };
			auto newEnd = std::remove_if(cityCards.begin(), cityCards.end(), pred);
			cityCards.erase(newEnd, cityCards.end());
			Assert::AreEqual(size, cityCards.size());
		}

		TEST_METHOD(AddEventCardtest)
		{
			int eventCardID = 1;
			EventCard eventCard(eventCardID);			
			std::vector<EventCard> eventCards;
			size_t size = eventCards.size();
			eventCards.emplace_back(eventCard);
			if (size == eventCards.size())
				Assert::Fail();
		}

		TEST_METHOD(AddCityCardtest)
		{
			const int32_t population = 1000;
			const std::string cityName = "A";
			const EVirus virusType = EVirus::BlackVirus;
			const int16_t cityId = 1;
			CityCard cityCard(population, cityName, virusType, cityId);
			std::vector<CityCard> cityCards;
			size_t size = cityCards.size();
			cityCards.emplace_back(cityCard);
			if (size == cityCards.size())
				Assert::Fail();
		}
	};
}