#pragma once
#include"SFML/Graphics.hpp"

class Card
{
public:
	Card() = default;
	Card(const std::string& texturePath,bool isEpidemicCard=false,bool isEventCard=false);
	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2f& position);
	const sf::Vector2f& GetPosition();
	void Move(const sf::Vector2f& pos);
	void SetScale(const sf::Vector2f& offset);
	const sf::Vector2f& GetScale();

	void SetIsEpidemicCard(bool isEpidemicCard = true);

	bool IsEpidemicCard();

	bool IsEventCard();

	bool IsDrewCard();

	void SetDrew(bool drew=true);


private:
	void initCityCard(const std::string& pathTexture);
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	bool m_IsEventCard;
	bool m_IsEpidemicCard;
	bool IsDrew;
};