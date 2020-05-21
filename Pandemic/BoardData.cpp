#include "BoardData.h"


void BoardData::SetCitiesNeibours()
{
	const std::array<std::array<int,5>,49> neibours{
		    std::array<int, 5>{0, 1, 4, 5, 6},
		 	std::array<int, 5>{ 0,3,4,6,7 },
			std::array<int, 5>{ 0,4,5,-1,-1 },
			std::array<int, 5>{ 2,3,5,6,-1 },
			std::array<int, 5>{ 1,3,4,5,6 },
			std::array<int, 5>{ 2,4,5,-1,-1 },
			std::array<int, 5>{ 1,3,4,-1,-1 },
			std::array<int, 5>{ 4,9,10,11,12 },
			std::array<int, 5>{ 5,6,7,10,11 },
			std::array<int, 5>{ 7,8,9,11,-1 },
			std::array<int, 5>{ 10,11,-1,-1,-1 },
			std::array<int, 5>{ 12,13,15,16,17 },
			std::array<int, 5>{ 9,13,14,16,-1 },
			std::array<int, 5>{ 7,11,13,14,15 },
			std::array<int, 5>{ 8,9,12,-1,-1 },
			std::array<int, 5>{ 10,11,14,15,18 },
			std::array<int, 5>{ 12,13,16,-1,-1 },
			std::array<int, 5>{ 14,15,16,17,-1 },
			std::array<int, 5>{ 11,14,15,17,19 },
			std::array<int, 5>{ 15,16,17,-1,-1 },
			std::array<int, 5>{ 16,19,20,21,17 },
			std::array<int, 5>{ 17,19,20,21,-1 },
			std::array<int, 5>{ 14,16,18,19,20 },
			std::array<int, 5>{ 22,23,25,-1,-1 },
			std::array<int, 5>{ 23,24,26,27,-1 },
			std::array<int, 5>{ 23,27,28,29,-1 },
			std::array<int, 5>{ 23,25,26,-1,-1 },
			std::array<int, 5>{ 24,26,27,28,29 },
			std::array<int, 5>{ 25,26,28,29,-1 },
			std::array<int, 5>{ 26,27,29,30,31 },
			std::array<int, 5>{ 28,29,33,-1,-1 },
			std::array<int, 5>{ 29,30,33,35,-1 },
			std::array<int, 5>{ 31,33,34,35,36 },
			std::array<int, 5>{ 32,33,35,-1,-1 },
			std::array<int, 5>{ 32,33,36,37,-1 },
			std::array<int, 5>{ 33,34,36,37,38 },
			std::array<int, 5>{ 34,35,36,-1,-1 },
			std::array<int, 5>{ 34,36,37,38,-1 },
			std::array<int, 5>{ 34,35,38,39,40 },
			std::array<int, 5>{ 35,36,37,-1,-1 },
			std::array<int, 5>{ 36,37,39,40,-1 },
			std::array<int, 5>{ 37,39,40,41,42 },
			std::array<int, 5>{ 39,40,41,-1,-1 },
			std::array<int, 5>{ 40,41,42,44,-1 },
			std::array<int, 5>{ 40,42,44,-1,-1 },
			std::array<int, 5>{ 40,41,45,46,-1 },
			std::array<int, 5>{ 42,43,44,45,-1 },
			std::array<int, 5>{ 43,45,46,-1,-1 },
			
	};
	for (int i = 0; i < 49; i++) {
		for (int j = 0; j < 5; j++) {
			if(neibours[i][j]!=-1)
			m_cities[i].AddNeibouringCities(m_cities[neibours[i][j]]);
		}
	}
}

City& BoardData::GetCity(const int16_t index)
{
	return m_cities[index];
}

const std::array<City,49>& BoardData::GetCities() const
{
	return m_cities;
}


const int8_t BoardData::GetOutbreaks() const
{
	return m_outbreaks;
}

const int8_t BoardData::GetInfectionRate() const
{
	return m_infectionRate[m_infectionRatePosition];
}

const int8_t BoardData::GetPiecies(const EVirus virus) const
{
	return m_pieces.at(virus);
}

const int8_t BoardData::GetNumOfResearchStations() const
{
	return m_researchStations;
}

const int8_t BoardData::GetCuredMarkers(const EVirus virus) const
{
	return m_curedMarkers.at(virus);
}

void BoardData::GenerateBoard()
{
	

	m_curedMarkers.insert({ EVirus::BlackVirus, 0 });
	m_curedMarkers.insert({ EVirus::BlueVirus,0 });
	m_curedMarkers.insert({ EVirus::RedVirus,0 });
	m_curedMarkers.insert({ EVirus::YellowVirus,0 });
}

void BoardData::AdvanceInfectionMarker()
{
	++m_infectionRatePosition;
}

void BoardData::AdvanceOutbreaksMarker()
{
	++m_outbreaks;
}

void BoardData::AdvanceCuredMarker(const EVirus virus)
{
	m_curedMarkers.at(virus)++;
}


void BoardData::SetResearchStation()
{
	--m_researchStations;
}

void BoardData::RemovePiece(const EVirus virus)
{
	m_pieces.at(virus) = m_pieces.at(virus) - 1;
}

