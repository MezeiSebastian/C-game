#include "InfectionCard.h"



InfectionCard::InfectionCard()
{
}

ECity InfectionCard::GetCityName() const
{
	return city;
}

EVirus InfectionCard::GetVirusType() const
{
	return virusType;
}


InfectionCard::~InfectionCard()
{
}
