#include "StatsDeckBoard.h"

StatsDeckBoard::StatsDeckBoard(const std::string& pathTexture)
{
	initDeck(pathTexture);
}

void StatsDeckBoard::Render(sf::RenderTarget& target)
{
	target.draw(m_deck);
}

void StatsDeckBoard::SetPosition(const sf::Vector2f& position)
{
	m_deck.setPosition(position);
}

void StatsDeckBoard::Rotate(int angle)
{
	m_deck.rotate(angle);
}

void StatsDeckBoard::initDeck(const std::string& pathTexture)
{
	textureDeck = new sf::Texture();

	textureDeck->loadFromFile(pathTexture);

	m_deck.setTexture(textureDeck);

	m_deck.setSize(sf::Vector2f(100,150));
}
