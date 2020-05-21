#include "ParserLinksBetweenCities.h"

#include<sstream>

std::vector<ECity> ParserLinksBetweenCities::Parse(const ECity& city_name,std::ifstream& linksCitiesFile)
{
	std::vector<ECity> cities;

	linksCitiesFile.seekg(linksCitiesFile.beg);

	std::string line;
	while (std::getline(linksCitiesFile, line))
	{
		if (ProvideStringFromECity(city_name) == line)
		{
			std::getline(linksCitiesFile, line);
			cities=ParseCities(line);
			return cities;
		}
	}

	return cities;
}

std::vector<ECity> ParserLinksBetweenCities::ParseCities(const std::string& line)
{
	std::vector<ECity> cities;

	std::stringstream streamLine(line);

	std::string token;
	while (std::getline(streamLine, token, ','))
	{
		ECity city = ProvideECityFromString(token);
		if (city != ECity::None)
			cities.push_back(city);
	}

	return cities;
}
