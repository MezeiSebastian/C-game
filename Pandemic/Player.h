#pragma once

#include"PlayerData.h"
#include<algorithm>
#include"Input.h"

class Player:public PlayerData
{
public:
	Player(const std::string playerName, const int16_t playerNumber, City& originalCity,int playerRole) :
		PlayerData(playerName, playerNumber, originalCity,playerRole)
	{}
	
	bool FerryMove(City& nextCity);
	bool FlightMove(City& nextCity);
	bool CharterMove(City& nextCity);
	bool ShuttleMove(City& nextCity);
	bool BuildResearchStation();
	bool TreatDesease(const EVirus virus);
	bool ShareKnowledge(const Player& p2,CityCard&& c1);
	bool DiscoverCure(EVirus virus);
	
};

