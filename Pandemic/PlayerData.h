#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"EVirus.h"
#include"City.h"
#include"CityCard.h"
#include"EventCard.h"

class PlayerData
{

private:
	std::string m_playerName;
	int16_t m_playerNumber;
	int16_t m_actions;
	int16_t m_playerRole;
	City* m_currentCity = nullptr;
	std::vector<CityCard> m_cityCards;
	std::vector<EventCard> m_eventCards;
public:
	
	PlayerData(const std::string playerName,const int16_t playerNumber,City& originalCity,int16_t playerRole);
	PlayerData(const PlayerData&) = delete;
	const PlayerData& operator=(const PlayerData& other) = delete;
	PlayerData(PlayerData&&) = default;

	const int GetPlayerRole();
	const std::string GetPlayerName() const;
	const int16_t GetPlayerNumber() const;
	const int16_t GetNumOfActions() const;
	City& GetCurentCity() const;
	const size_t GetNumOfCityCards() const;
	void SetActions(int16_t actions);
	void SetCity(City& city);
	void AddCityCard(CityCard&& cityCard);
	void AddCityCard(const CityCard& cityCard);
	const CityCard& GetCard(int index) const;
	void AddEventCard(EventCard&& eventCard);
	const EventCard GetEventCard(int CardNumber) const;
	void DeleteCard(const CityCard& Card);
	const bool DiscardCard(const City& cityCard);
};

