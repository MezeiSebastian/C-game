#pragma once
#include"State.h"
#include"BoardCity.h"
#include"Lines.h"
#include"StatsTableBoard.h"
#include"ActionBoard.h"
#include"StatsInfectionRate.h"

#include"GameplayGraphics.h"

#include<time.h>
#include<map>

class GameState :public State
{
public:
	GameState(sf::RenderWindow& window);

	void update() override;
	void render() override;
	void endState() override;
	void updateSFMLEvents() override;
private:
	bool initBackground();
	bool initBlueRound();
	bool initRedRound();
	bool initYellowRound();
	bool initBlackRound();
	bool initCities();
	void initCityConnections();
	bool initLines();
	bool initFont();
	void initMapCities();
private:
	void rendBackground();
	void rendBlueRound();
	void rendRedRound();
	void rendYellowRound();
	void rendCities();
	void rendLines();
	void rendStatsTableBoard();
	void rendActionBoard();
	void rendCityConnections();
private:
	void updateBlueRounds();
	void updateActionBoard();
private:
	std::map<std::string, sf::Sprite> m_rounds;
	sf::Font m_font;
	std::map<std::string, sf::Text>m_texts;

	StatsTableBoard m_statsTableBoard;
	ActionBoard m_actionBoard;
	StatsInfectionRate m_infectionRateBoard;
	GamePlayGraphics* m_gamePlay;

	std::vector<BoardCity> m_cities;
	std::map<std::string, BoardCity> m_mapCities;
	std::vector<sf::VertexArray> m_lines;

	std::clock_t m_begin;
	std::clock_t m_end;
};