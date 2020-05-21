#pragma once
#include"SFML/Graphics.hpp"

class  Build
{
public:
	Build();
	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2f& position);
private:
	void InitBuildSprite();
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};
