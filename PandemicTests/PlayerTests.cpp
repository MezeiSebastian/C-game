#include "pch.h"
#include "CppUnitTest.h"
#include "Player.h"
#include "PlayerData.h"
#include <string>
#include "EVirus.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PandemicTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(FerryMoveTest)
		{
			City city;
			City nextCity;

			if (city.FindNeibours(nextCity))
				nextCity = city;
			Assert::AreEqual(city.GetCityName(), nextCity.GetCityName());
		}

		TEST_METHOD(FlightMovetest)
		{
			const std::string playerName = "player1";
			const int16_t playerNumber = 1;
			City originalCity;
			PlayerData player(playerName, playerNumber, originalCity);

			City city;
			City nextCity;
			if (player.DiscardCard(nextCity))
				city = nextCity;
			Assert::AreEqual(city.GetCityName(), nextCity.GetCityName());
		}

		TEST_METHOD(ShuttleMovetest)
		{

			City city;
			City nextCity;
			if (city.GetResearchStationStatus() && nextCity.GetResearchStationStatus())
				nextCity = city;
			Assert::AreEqual(city.GetCityName(), nextCity.GetCityName());

		}

		TEST_METHOD(CharterMovetest)
		{
			const std::string playerName = "player1";			
			const int16_t playerNumber = 1;
			City originalCity;
			PlayerData player(playerName, playerNumber, originalCity);
			City city;
			City nextCity;

			if (player.DiscardCard(city)) 
				city = nextCity;
			Assert::AreEqual(city.GetCityName(), nextCity.GetCityName());
		}

		TEST_METHOD(BuildResearchStationtest)
		{
			const std::string playerName = "player1";
			const int16_t playerNumber = 1;
			City originalCity;
			PlayerData player(playerName, playerNumber, originalCity);
			City city;
			bool status = true;
			if (player.DiscardCard(city))
			{
				status = true;
				city.SetResearchStation(status);
			}
			if (status == false)
				Assert::Fail();
		}
		};
}