#include "City.h"

City::City(std::string cityName, int16_t cityId):
	m_cityName(cityName),
	m_cityId(cityId),
	m_isResearchStation(false)
{
	m_viruses.insert({ EVirus::BlackVirus,0 });
	m_viruses.insert({ EVirus::BlueVirus,0 });
	m_viruses.insert({ EVirus::RedVirus,0 });
	m_viruses.insert({ EVirus::YellowVirus,0 });
}

const int16_t City::GetCityId() const {
	return m_cityId;

}

bool City::FindNeibours(const City& city) const {

	for (auto it : m_neibouringCities) {
		if (it->m_cityId == city.m_cityId) {
			return true;
		}
	}
	return false;
}

int16_t City::GetNumberOfViruses(const EVirus virus) const {
	return m_viruses.at(virus);
}

bool City::GetResearchStationStatus() const {
	return m_isResearchStation;
}

const City& City::GetNeibours(const int8_t i) const
{
	return *m_neibouringCities[i];
}

void City::AddNeibouringCities(City& city) {
	
	m_neibouringCities.emplace_back(&city);
}

void City::SetResearchStation(const bool status) {
	m_isResearchStation = status;
}

const std::string City::GetCityName() const {
	return m_cityName;
}

void City::ReduceDiseases(const EVirus virus) {
	m_viruses.at(virus) -= 1;
}

void City::SetDisease(const EVirus virus, const int16_t numberOfViruses)
{
	m_viruses.at(virus) = numberOfViruses;
}

