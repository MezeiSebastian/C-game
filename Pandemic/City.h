#pragma once
#include<string>
#include<unordered_map>
#include<vector>
#include<memory>
#include"EVirus.h"
class City {
private:
	bool m_isResearchStation=false;
	int16_t m_cityId;
	std::string m_cityName; 
	std::unordered_map<EVirus, int16_t> m_viruses;
	std::vector<std::shared_ptr<City>> m_neibouringCities;
public:
	City()=default;
	City(const std::string cityName, int16_t cityId);
	const int16_t GetCityId() const;
	const std::string GetCityName() const;
	bool FindNeibours(const City& city) const;
	int16_t GetNumberOfViruses(const EVirus virus) const;
	bool GetResearchStationStatus() const;
	const City& GetNeibours(const int8_t i) const;

	void ReduceDiseases(const EVirus virus);
	void SetDisease(const EVirus virus, const int16_t numberOfViruses);
	void AddNeibouringCities(City& city);
	void SetResearchStation(const bool status);






};