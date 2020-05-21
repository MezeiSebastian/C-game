#pragma once
#include"SFML/Graphics.hpp"

class StatsDeckBoard
{
public:
	StatsDeckBoard(const std::string& path);

	void Render(sf::RenderTarget& target);

	void SetPosition(const sf::Vector2f& position);

	void Rotate(int angle);
private:
	void initDeck(const std::string& path);
private:
	sf::RectangleShape m_deck;

	sf::Texture* textureDeck;
};