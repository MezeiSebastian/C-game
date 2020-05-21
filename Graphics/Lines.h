#pragma once
#include"SFML/Graphics.hpp"

class Line
{
public:
	Line(const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color);
	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2f& start, const sf::Vector2f& end);
private:
	sf::Vector2f m_start;
	sf::Vector2f m_end;
	sf::Color m_color;
};