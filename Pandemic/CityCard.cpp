#include "CityCard.h"




CityCard::CityCard(const int32_t population,const std::string cityName,const EVirus virusType,const int16_t cityId):
	m_population(population),
	m_cityName(cityName),
	m_virusType(virusType),
	m_cityId(cityId)
{}

CityCard::CityCard(CityCard&& other) noexcept
{
	this->m_cityName = other.m_cityName;
	this->m_population = other.m_population;
	this->m_virusType = other.m_virusType;
	this->m_cityId = other.m_cityId;
	
}

const CityCard& CityCard::operator=(CityCard&& other) noexcept
{

	this->m_cityName = other.m_cityName;
	this->m_population = other.m_population;
	this->m_virusType = other.m_virusType;
	this->m_cityId = other.m_cityId;
	
	return *this;
}

const int16_t CityCard::GetCityId()
{
	return m_cityId;
}

const EVirus CityCard::GetVirus() const
{
	return m_virusType;
}

const std::string& CityCard::GetCityName() const {
	return m_cityName;
}

const int32_t CityCard::GetPopulation() const {
	return m_population;
}
