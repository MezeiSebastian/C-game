#include "Lines.h"

Line::Line(const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color):
	m_start(start),
	m_end(end),
	m_color(color)
{
}

void Line::Rend(sf::RenderTarget& target)
{
	sf::RectangleShape fit(sf::Vector2f(m_end.x-m_start.x,5));
	fit.setOutlineColor(m_color);
	fit.setFillColor(m_color);

	sf::Vector2f position;
	position.x = m_start.x + 15;
	position.y = m_start.y + 15;
	fit.setPosition(position);
	//fit.setRotation(5);

	sf::Vertex line[] = {
		sf::Vertex(m_start,m_color),
		sf::Vertex(m_end,m_color)
	};
	target.draw(fit);
}
