#pragma once
#include"SFML/Graphics.hpp"

class DrawLoseClass
{
public:
	DrawLoseClass();
	void Rend(sf::RenderTarget& target);
private:
	void initDrawLoseClass();
private:
	sf::RectangleShape m_blackBox;
	sf::Text m_text;
	sf::Font m_font;
};