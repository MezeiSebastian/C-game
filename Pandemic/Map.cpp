#include "Map.h"
#include "ParserLinksBetweenCities.h"

#include<fstream>

void Map::InitCities()
{
	for (int index = 0; index < 48; index++)
		if (index <= 11)
			m_cities.push_back(City(ECity(index), EColor::Blue));

		else if (index <= 23)
			m_cities.push_back(City(ECity(index), EColor::Yellow));

		else if (index <= 35)
			m_cities.push_back(City(ECity(index), EColor::Black));

		else if (index <= 47)
			m_cities.push_back(City(ECity(index), EColor::Red));
}

bool Map::AddLinksBeetwenCities(const std::string& linksFilePath)
{
	std::ifstream linksFile(linksFilePath);

	for (int index = 0; index < m_cities.size(); index++)
	{
		std::vector<ECity> neighbouringCities = ParserLinksBetweenCities::Parse(ECity(index), linksFile);
		for(const ECity& city_name:neighbouringCities)
			m_cities[index].AddNeighbouringCity((*this)[city_name]);
	}
}

Map::Map(const std::string& initFilePath)
{
	InitCities();
	AddLinksBeetwenCities(initFilePath);
}

const City& Map::operator[](const ECity& city_name) const
{
	for (int index = 0; index < m_cities.size(); index++)
		if (m_cities[index].GetCity() == city_name)
			return m_cities[index];
}
