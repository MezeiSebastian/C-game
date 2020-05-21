#pragma once
#include<iostream>
#include <string>
#include"EVirus.h"
class CityCard
{
private:
	int32_t m_population;
	std::string m_cityName;
	EVirus m_virusType;
	int16_t m_cityId;
public:
	CityCard(const int32_t population, const std::string cityName, const EVirus virusType, const int16_t cityId);
	CityCard(const CityCard& other) = default;
	
	const CityCard(CityCard&& other) noexcept;
	const CityCard& operator=(CityCard&& other) noexcept;
	const int16_t GetCityId();
	const EVirus GetVirus() const;
	const std::string& GetCityName() const;
	const int32_t GetPopulation() const;
};

