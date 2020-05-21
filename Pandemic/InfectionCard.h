#pragma once
#include "Card.h"
#include "ECity.h"
#include "EVirus.h"
class InfectionCard:public Card
{
private:
	ECity city;
	EVirus virusType;
public:
	InfectionCard();
	ECity GetCityName() const;
	EVirus GetVirusType() const;
	~InfectionCard();
};

