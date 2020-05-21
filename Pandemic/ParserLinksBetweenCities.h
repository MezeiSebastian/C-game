#pragma once
#include"City.h"

#include<fstream>

class ParserLinksBetweenCities
{
public:
	ParserLinksBetweenCities() = delete;
	static std::vector<ECity> Parse(const ECity& city_name,std::ifstream& linksCitiesFile);
private:
	static std::vector<ECity> ParseCities(const std::string& line);
};