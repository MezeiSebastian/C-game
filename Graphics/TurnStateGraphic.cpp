#include "TurnStateGraphic.h"

TurnStateGraphic::TurnStateGraphic()
{
	initFont();
	initText();
	initTurn();
}

void TurnStateGraphic::Render(sf::RenderTarget& target)
{
	target.draw(m_text);

	for (int index = 0; index < 4; index++)
		target.draw(m_Turns[index].first);
}

void TurnStateGraphic::Update()
{
	for (int index = 0; index < 4; index++)
		if (!m_Turns[index].second)
			m_Turns[index].first.setFillColor(sf::Color::White);
		else m_Turns[index].first.setFillColor(sf::Color::Green);
}

void TurnStateGraphic::DecreaseTurn()
{
	for (int index = 3; index >= 0; index--)
		if (m_Turns[index].second == true)
		{
			m_Turns[index].second = false;
			break;
		}
}

int TurnStateGraphic::GetRemainingMovesPosible()
{
	int movesRemaining = 0;
	for (int index = 0; index < m_Turns.size(); index++)
		if (m_Turns[index].second == true)
			movesRemaining++;

	return movesRemaining;
}

void TurnStateGraphic::Reset()
{
	for (int index = 0; index < m_Turns.size(); index++)
		m_Turns[index].second = true;
}

void TurnStateGraphic::initText()
{
	m_text.setFont(m_font);
	m_text.setString("Turn Remains:");
	m_text.setColor(sf::Color::White);
	m_text.setCharacterSize(25);
	m_text.setPosition(100,1000);
}

void TurnStateGraphic::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void TurnStateGraphic::initTurn()
{
	sf::RectangleShape m_shape;

	m_shape.setSize(sf::Vector2f(15,30));
	m_shape.setOutlineThickness(5);
	m_shape.setOutlineColor(sf::Color::Blue);
	m_shape.setFillColor(sf::Color::Green);
	m_shape.setPosition(m_text.getPosition().x + 15,m_text.getPosition().y+35);

	m_Turns.push_back(std::make_pair(m_shape, true));

	m_shape.setPosition(m_shape.getPosition().x + 35, m_shape.getPosition().y);

	m_Turns.push_back(std::make_pair(m_shape, true));

	m_shape.setPosition(m_shape.getPosition().x + 35, m_shape.getPosition().y);

	m_Turns.push_back(std::make_pair(m_shape, true));
	
	m_shape.setPosition(m_shape.getPosition().x + 35, m_shape.getPosition().y);

	m_Turns.push_back(std::make_pair(m_shape, true));
}
