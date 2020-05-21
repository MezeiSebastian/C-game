#pragma once
#include<SFML/Graphics.hpp>

#include<vector>

class StatsInfectionRate
{
public:
	StatsInfectionRate();

	void render(sf::RenderTarget& target);

	void updateInfectionRate();
	void updateOutbreaksMarker();

	int GetInfectionRateValue();
	int GetOutbreaksNumber();
private:
	void initFont();
	void initTitle();
	void initInfectionRates();
	void initOutbreaks();
	void initInfectionRateValue();
private:
	sf::Font m_font;

	std::vector<std::pair<sf::CircleShape, sf::Text>> m_infectionRates;
	std::vector<sf::CircleShape> m_outbreaks;

	int posInfectionRate;
	int numberOfOutbreaks;

	std::vector<int> m_infectionRateValue;

	sf::Text m_title;
	sf::Text m_title2;
};