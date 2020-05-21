#include "DrawLoseClass.h"

DrawLoseClass::DrawLoseClass()
{
	initDrawLoseClass();
}

void DrawLoseClass::Rend(sf::RenderTarget& target)
{
	target.draw(m_blackBox);
	target.draw(m_text);
}

void DrawLoseClass::initDrawLoseClass()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");

	m_blackBox.setFillColor(sf::Color::Black);

	m_blackBox.setOutlineColor(sf::Color::White);

	m_blackBox.setOutlineThickness(5);

	m_blackBox.setSize(sf::Vector2f(1940,80));

	m_blackBox.setPosition(sf::Vector2f(0,500));

	m_text.setFont(m_font);

	m_text.setCharacterSize(30);

	m_text.setString("LOSE");

	m_text.setPosition(sf::Vector2f(900, 520));

	m_text.setColor(sf::Color::White);
}
