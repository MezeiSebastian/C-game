#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include<array>
#include"Init.h"
#include"EVirus.h"
#include"City.h"
class BoardData
{
private:
	std::unordered_map<EVirus, int16_t> m_pieces{
		{EVirus::BlackVirus,6},
		{EVirus::BlueVirus,6},
		{EVirus::RedVirus,6},
		{EVirus::YellowVirus,6},
	};
	std::unordered_map<EVirus, int16_t> m_curedMarkers;
	int16_t m_researchStations=6;
	int16_t m_outbreaks = 0;;
	int16_t m_infectionRatePosition=0;
	const std::array<int16_t,8> m_infectionRate{ 2,2,2,2,3,3,4,4 };
	std::array<City,49> m_cities{
	  City{"SanFrancisco",1},
	  City{"Chicago",2},
	  City{"Atlanta",3},
	  City{"Montreal",4},
	  City{"NewYork",5},
	  City{"London",6},
	  City{"Paris",7},
	  City{"StPetersburg",8},
	  City{"Milan",9},
	  City{"Essen",10},
	  City{"Madrid",11},
	  City{"Washington",12},

	  City{"LosAngeles",13},
	  City{"MexicoCity",14},
	  City{"Miami",15},
	  City{"Bogota",16},
	  City{"Lima",17},
	  City{"SaoPaulo",18},
	  City{"BuenosAries",19},
	  City{"Santiago",20},
	  City{"Lagos",21},
	  City{"Khartoum",22},
	  City{"Kinshasa",23},
	  City{"Johannesburg",24},

	  City{"Algiers",25},
	  City{"Istanbul",26},
	  City{"Moscow",27},
	  City{"Cairo",28},
	  City{"Tehran",29},
	  City{"Karachi",30},
	  City{"Kolkata",31},
	  City{"Delhi",32},
	  City{"Mumbai",33},
	  City{"Riyadh",34},
	  City{"Chennai",35},
	  City{"Baghdad",36},
	
	  City{"Bangkok",37},
	  City{"Beijing",38},
	  City{"HoChiMinhCity",39},
	  City{"HongKong",40},
	  City{"Jakarta",41},
	  City{"Manila",42},
	  City{"Manila",43},
	  City{"Osaka",44},
	  City{"Seoul",45},
	  City{"Shanghai",46},
	  City{"Sydney",47},
	  City{"Taipei",48},
	  City{"Tokyo",49}
	};
public: 

	void SetCitiesNeibours();
	City& GetCity(const int16_t index);
	const std::array<City,49>& GetCities()const;
	const int8_t GetOutbreaks() const;
	const int8_t GetInfectionRate() const;
	const int8_t GetPiecies(const EVirus virus) const;
	const int8_t GetNumOfResearchStations() const;
	const int8_t GetCuredMarkers(const EVirus virus) const;
	void GenerateBoard();
	void AdvanceInfectionMarker();
	void AdvanceOutbreaksMarker();
	void AdvanceCuredMarker(const EVirus virus);
	void SetResearchStation();
	void RemovePiece(const EVirus virus);
};

