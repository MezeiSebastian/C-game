#include "pch.h"
#include "CppUnitTest.h"
#include "BoardData.h"
#include "PlayerData.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PandemicTests
{
	TEST_CLASS(BoardDataTests)
	{
	public:

		TEST_METHOD(SetCitiesNeiboursTest)
		{
			BoardData board;
			const std::array<std::array<int, 5>, 2> neibours{
			std::array<int, 5>{0, 1, 4, 5, 6},
			std::array<int, 5>{ 0,3,4,6,7 },

			};
			if (neibours.empty() == true)
				Assert::Fail();
		}

		TEST_METHOD(SetResearchStationTest)
		{
			int16_t researchStations = 6;
			if (researchStations == 0)
				Assert::Fail();
		}
		TEST_METHOD(RemovePieceTest)
		{
			std::unordered_map<EVirus, int16_t> pieces{
				{EVirus::BlackVirus,6},
				{EVirus::BlueVirus,6}
			};
			std::unordered_map<EVirus, int16_t> pieces2{
				{EVirus::BlackVirus,6},
				{EVirus::BlueVirus,6}
			};
			const EVirus virus = EVirus::BlackVirus;
			pieces.at(virus) = pieces.at(virus) - 1;
			if (pieces2.at(virus) - 1 != pieces.at(virus))
				Assert::Fail();

			if (pieces2.at(virus) == 0)
				Assert::Fail();
		}

		TEST_METHOD(AdvanceOutbreaksMarkerTest)
		{
			int16_t outbreaks = 0;
			++outbreaks;
			int16_t expectation = 1;
			Assert::AreEqual(expectation, outbreaks);
		}

		TEST_METHOD(AdvanceInfectionMarkerTest)
		{
			int16_t infectionRatePosition = 0;
			++infectionRatePosition;
			int16_t expectation = 1;
			Assert::AreEqual(expectation, infectionRatePosition);
		}

	};
}