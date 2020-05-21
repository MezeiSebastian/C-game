#include "StatsInfectionRate.h"

StatsInfectionRate::StatsInfectionRate()
{
	numberOfOutbreaks = 0;
	initFont();
	initTitle();
	initInfectionRates();
	initInfectionRateValue();
	initOutbreaks();
}

void StatsInfectionRate::render(sf::RenderTarget& target)
{
	target.draw(m_title);
	target.draw(m_title2);

	for (int index = 0; index < m_infectionRates.size(); index++)
	{
		target.draw(m_infectionRates[index].first);
		target.draw(m_infectionRates[index].second);
	}

	for (int index = 0; index < m_outbreaks.size(); index++)
	{
		target.draw(m_outbreaks[index]);
		target.draw(m_outbreaks[index]);
	}
}

void StatsInfectionRate::updateInfectionRate()
{
	posInfectionRate++;
	if (posInfectionRate < 7)
	{
		m_infectionRates[posInfectionRate-1].first.setFillColor(sf::Color::White);
		m_infectionRates[posInfectionRate].first.setFillColor(sf::Color::Green);
	}
	else
		posInfectionRate--;
}

void StatsInfectionRate::updateOutbreaksMarker()
{
	numberOfOutbreaks++;
	if (numberOfOutbreaks < 8)
		m_outbreaks[numberOfOutbreaks - 1].setFillColor(sf::Color::Red);
}

int StatsInfectionRate::GetInfectionRateValue()
{
	if (posInfectionRate < 7)
	return m_infectionRateValue[posInfectionRate];
}

int StatsInfectionRate::GetOutbreaksNumber()
{
	return numberOfOutbreaks;
}

void StatsInfectionRate::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void StatsInfectionRate::initTitle()
{
	m_title.setFont(m_font);

	m_title.setString("Infection Rate");

	m_title.setPosition(870, 50);

	m_title.setColor(sf::Color::Green);

	m_title.setCharacterSize(25);


	m_title2.setFont(m_font);

	m_title2.setString("Number of outbreaks");

	m_title2.setPosition(825, 120);

	m_title2.setColor(sf::Color::Red);

	m_title2.setCharacterSize(25);
}

void StatsInfectionRate::initInfectionRates()
{

	sf::CircleShape circleShape;
	sf::Text text;

	circleShape.setRadius(15);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(825,80);

	text.setFont(m_font);
	text.setCharacterSize(15);
	text.setColor(sf::Color::Black);
	text.setPosition(circleShape.getPosition().x+10,circleShape.getPosition().y+6);

	text.setString("2");

	m_infectionRates.push_back(std::make_pair(circleShape, text));
	m_infectionRates[0].first.setFillColor(sf::Color::Green);

	posInfectionRate = 0;

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));

	text.setString("3");

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));

	text.setString("4");

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	text.setPosition(circleShape.getPosition().x + 10, circleShape.getPosition().y + 6);
	m_infectionRates.push_back(std::make_pair(circleShape, text));
}

void StatsInfectionRate::initOutbreaks()
{
	sf::CircleShape circleShape;
	sf::Text text;

	circleShape.setRadius(15);
	circleShape.setFillColor(sf::Color::White);
	circleShape.setPosition(825,150);

	m_outbreaks.push_back(circleShape);

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);

	text.setString("3");

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);

	circleShape.setPosition(circleShape.getPosition().x + 40, circleShape.getPosition().y);
	m_outbreaks.push_back(circleShape);
}

void StatsInfectionRate::initInfectionRateValue()
{
	m_infectionRateValue.push_back(2);
	m_infectionRateValue.push_back(2);
	m_infectionRateValue.push_back(2);
	m_infectionRateValue.push_back(3);
	m_infectionRateValue.push_back(3);
	m_infectionRateValue.push_back(4);
	m_infectionRateValue.push_back(4);
}
