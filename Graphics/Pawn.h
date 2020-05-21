#pragma once
#include "BoardCity.h"
#include "CityCard.h"
#include "EventCard.h"

#include"SFML/Graphics.hpp"

class Pawn
{
public:
	Pawn(BoardCity*& city);

	void Rend(sf::RenderTarget& target);
	void Update(sf::RenderTarget& target);
	void Move(const sf::Vector2f& position);
	void SetTurn(bool turn = true);

	BoardCity*& GetCurrentCity();
	void SetCurrentCity(BoardCity*& city);

	void AddCards(Card*& cityCard);

	int GetNumberOfCards();

	std::vector<Card*>& GetCards();

	int pressedCard(Card*& aux);

	bool EraseCard(int index);

	void RearangeCards();
private:
	void InitPawn();
	void InitArrow();

	bool m_ItIsTurn;
private:
	sf::Sprite m_spritePawn;
	sf::Texture m_texturePawn;

	sf::Texture m_arrowTexture;
	sf::Sprite m_arrowSprite;

	BoardCity* m_currentCity;

	std::vector<Card*> m_cityCards;

	bool m_isCityCardLast;
	bool m_isEventCardLast;
};
