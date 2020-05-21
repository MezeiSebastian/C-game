#pragma once
#include"City.h"

class Map
{
public:
	Map(const std::string& initFilePath);
	const City& operator[](const ECity& city_name) const;
private:
	void InitCities();
	bool AddLinksBeetwenCities(const std::string& linkFilePath);
private:
	std::vector<City> m_cities;
};