#include "Pawn.h"

Pawn::Pawn(BoardCity*& city):m_currentCity(city)
{
	InitPawn();
	InitArrow();
}

void Pawn::Rend(sf::RenderTarget& target)
{
	target.draw(m_spritePawn);

	if (m_ItIsTurn == true)
	{
		target.draw(m_arrowSprite);

		for (int index = 0; index <m_cityCards.size(); index++)
			m_cityCards[index]->Rend(target);
	}
}

void Pawn::Update(sf::RenderTarget& target)
{
	m_arrowSprite.setPosition(sf::Vector2f(m_spritePawn.getPosition().x + 5, m_spritePawn.getPosition().y - 5));
}

void Pawn::Move(const sf::Vector2f& position)
{
	m_spritePawn.setPosition(position);
	m_arrowSprite.setPosition(sf::Vector2f(m_spritePawn.getPosition().x + 20, m_spritePawn.getPosition().y - 40));
}

void Pawn::SetTurn(bool turn)
{
	m_ItIsTurn = turn;
}

BoardCity*& Pawn::GetCurrentCity()
{
	return m_currentCity;
}

void Pawn::SetCurrentCity(BoardCity*& city)
{
	m_currentCity = city;
}

void Pawn::AddCards(Card*& cityCard)
{
	if(m_cityCards.size()==0)
		cityCard->SetPosition(sf::Vector2f(750, 900));

	if (m_cityCards.size() != 0)
		cityCard->SetPosition(sf::Vector2f(m_cityCards.back()->GetPosition().x + 100, m_cityCards.back()->GetPosition().y));

	m_cityCards.push_back(cityCard);

	RearangeCards();
}

int Pawn::GetNumberOfCards()
{
	return m_cityCards.size();
}

std::vector<Card*>& Pawn::GetCards()
{
	return m_cityCards;
}

int  Pawn::pressedCard(Card*& aux)
{
	aux = nullptr;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_cityCards.size() > 0)
	{
		int x = sf::Mouse::getPosition().x;
		int y = sf::Mouse::getPosition().y;
		int index = 0;
		for (Card*& card : m_cityCards)
		{
			if (x >= card->GetPosition().x && y >= card->GetPosition().y &&
				x < card->GetPosition().x + 100 && y < card->GetPosition().y + 100)
			{
				aux = card;
				return index;
			}
			index++;
		}
	}

	return -1;
}

bool Pawn::EraseCard(int index)
{
	if (index < m_cityCards.size())
	{
		m_cityCards.erase(m_cityCards.begin() + index);
		return true;
	}

	return false;

	
}



void Pawn::InitPawn()
{
	m_texturePawn.loadFromFile("Res//Pawn//Pawn3.png");

	m_spritePawn.setTexture(m_texturePawn);

	m_spritePawn.setScale(0.1, 0.1);
}

void Pawn::InitArrow()
{
	m_arrowTexture.loadFromFile("Res//Arrow//Arrow10.png");

	m_arrowSprite.setTexture(m_arrowTexture);
	
	m_arrowSprite.setScale(0.05, 0.05);

	m_ItIsTurn = false;
}

void Pawn::RearangeCards()
{
	if (m_cityCards.size())
		m_cityCards[0]->SetPosition(sf::Vector2f(750,900));

	for (int index = 1; index < m_cityCards.size(); index++)
	{
		m_cityCards[index]->SetPosition(sf::Vector2f(m_cityCards[index - 1]->GetPosition().x + 100, 900));
	}
}
