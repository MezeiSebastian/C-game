#pragma once
#include<iostream>
#include"City.h"
#include"BoardData.h"
#include"Player.h"
#include"CityCard.h"
#include<vector>
class Input
{
private:
	int16_t m_action=0;
	int16_t m_playerNumber=0;
	std::vector<int> playerRole;
	int16_t m_inputCity ;
	int16_t m_numberOfPlayers;
	static int16_t m_infectioRate;
	int16_t m_selectedCard;
	EVirus m_selectedVirus;
public:
	
	const int16_t GetPlayerRole(int index) {return playerRole[index];}
	const int16_t GetNumberOfPlayers() { return m_numberOfPlayers; }
	const int16_t GetCard() const { return m_selectedCard; }
	const EVirus GetVirus() const;
	City& GetCity(BoardData& board);
	static void SetInfectionRate(int16_t infectionRate) { m_infectioRate = infectionRate; }
	void AddPlayerRole(int inputPlayerRole) { playerRole.push_back(inputPlayerRole); }
	void SetNumberOfPlayers(int16_t numberOfPlayers) { m_numberOfPlayers = numberOfPlayers; }
	void SetVirus();
	void SetPlayerNumber();
	void SetCard();
	void ChooseInput();
	void SetPlayerRole(int16_t playerRole);
	int16_t GetAction() const { return m_action; }
	int16_t GetPlayerNumber() const { return m_playerNumber; }
	int16_t GetInputCity() const { return m_inputCity; }
	void PrintInput()const ;
};

