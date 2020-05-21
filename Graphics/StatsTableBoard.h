#pragma once
#include"SFML/Graphics.hpp"

#include"StatsVirusBoard.h"
#include"StatsDeckBoard.h"

#include<map>
#include<string>

class StatsTableBoard
{
public:
	StatsTableBoard();
	void Rend(sf::RenderTarget& target);

	void DecreaseYellowVirus();
	void DecreaseRedVirus();
	void DecreaseBlueVirus();
	void DecreaseBlackVirus();
	void DecreaseResearchStations();

	void AddYellowVirus();
	void AddRedVirus();
	void AddBlueVirus();
	void AddBlackVirus();
	void AddResearchStations();
	int getNumberOFResearchStations();

	void SetYellowEradicated();

	void SetYellowVirusTexture(const std::string& path);
	void SetRedVirusTexture(const std::string& path);
	void SetBlueVirusTexture(const std::string& path);
	void SetBlackVirusTexture(const std::string& path);
private:
	void initYellowVirus();
	void initRedVirus();
	void initBlueVirus();
	void initBlackBox();
	void initGreyVirus();
	void initResearchStation();

	void initDecks();

	void initFont();

	void initInfectionRateText();
private:
	sf::RectangleShape m_blackBoxAddPlayer;

	StatsVirusBoard* m_yellowVirus;
	StatsVirusBoard* m_redVirus;
	StatsVirusBoard* m_blueVirus;
	StatsVirusBoard* m_greyVirus;
	StatsVirusBoard* m_researchStation;

	StatsDeckBoard* m_deck;
	StatsDeckBoard* m_deck2;

	sf::Text m_text_InfectionRate;

	sf::Font m_font;

	int m_numberYellowVirus;
	int m_numberRedVirus;
	int m_numberBlackVirus;
	int m_numberBlueVirus;
	int m_numberOfResearchStations;
};