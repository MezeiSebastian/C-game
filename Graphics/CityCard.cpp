#include "CityCard.h"

Card::Card(const std::string& pathTexture,bool isEpidemicCard,bool isEventCard)
{
	m_IsEpidemicCard = isEpidemicCard;

	m_IsEventCard = isEventCard;

	initCityCard(pathTexture);

	IsDrew = false;
}

void Card::Rend(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(m_sprite);
}

void Card::SetPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

const sf::Vector2f& Card::GetPosition()
{
	return m_sprite.getPosition();
}

void Card::Move(const sf::Vector2f& pos)
{
	m_sprite.move(pos.x, pos.y);
}

void Card::SetScale(const sf::Vector2f& offset)
{
	m_sprite.setScale(offset);
}

const sf::Vector2f& Card::GetScale()
{
	return m_sprite.getScale();
}

void Card::SetIsEpidemicCard(bool isEpidemicCard)
{
	m_IsEpidemicCard = isEpidemicCard;
}

bool Card::IsEpidemicCard()
{
	return m_IsEpidemicCard;
}

bool Card::IsEventCard()
{
	return m_IsEventCard;
}

bool Card::IsDrewCard()
{
	return IsDrew;
}

void Card::SetDrew(bool drew)
{
	IsDrew = drew;
}

void Card::initCityCard(const std::string& pathTexture)
{
	m_texture.loadFromFile(pathTexture);

	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(sf::Vector2f(0,100));

	m_sprite.setScale(0.0001,0.0001);
}
