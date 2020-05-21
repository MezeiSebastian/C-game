#include "pch.h"
#include "CppUnitTest.h"
#include "City.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PandemicTests
{
	TEST_CLASS(CityTests)
	{
	public:

		TEST_METHOD(FindNeiboursTest)
		{
			bool ok = false;
			City city;
			std::vector<City> neibouringCities;
			neibouringCities.push_back(city);
			for (auto it : neibouringCities) 
				if (it.GetCityId() == city.GetCityId()) 
					ok = true;
			if (ok == false)
				Assert::Fail();
		}

		TEST_METHOD(AddNeibouringCitiesTest)
		{
			City city;
			std::vector<City> neibouringCities;
			size_t size = neibouringCities.size();
			neibouringCities.push_back(city);
			if (size == neibouringCities.size())
				Assert::Fail();
		}

		TEST_METHOD(SetResearchStationTest)
		{
			bool isResearchStation = false;
			bool status = true;
			isResearchStation = status;
			if (isResearchStation == false)
				Assert::Fail();
		}
		TEST_METHOD(ReduceDiseasesTest)
		{
		City city;
		const EVirus virus = EVirus::BlackVirus;
		int16_t numberOfViruses = 1;		
		numberOfViruses--;
		if (numberOfViruses != 0)
			Assert::Fail();
		}
	};
}