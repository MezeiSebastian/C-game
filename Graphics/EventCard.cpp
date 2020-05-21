#include "EventCard.h"

EventCard::EventCard(const std::string& texturePath)
{
	initEventCard(texturePath);
}

void EventCard::Rend(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}

void EventCard::SetPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

const sf::Vector2f& EventCard::GetPosition()
{
	return m_sprite.getPosition();
}

void EventCard::initEventCard(const std::string& pathTexture)
{
	m_texture.loadFromFile(pathTexture);

	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(sf::Vector2f(900, 900));
}
