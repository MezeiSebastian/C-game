#pragma once
#include"SFML/Graphics.hpp"

class EventCard
{
public:
	EventCard() = default;
	EventCard(const std::string & texturePath);
	void Rend(sf::RenderTarget & target);
	void SetPosition(const sf::Vector2f & position);
	const sf::Vector2f& GetPosition();
private:
	void initEventCard(const std::string & pathTexture);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};