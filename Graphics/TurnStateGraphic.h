#pragma once
#include<SFML/Graphics.hpp>


class TurnStateGraphic
{
public:
	TurnStateGraphic();

	void Render(sf::RenderTarget& target);
	void Update();

	void DecreaseTurn();
	int GetRemainingMovesPosible();
	void Reset();

private:
	sf::Texture m_texture;
	std::vector<std::pair<sf::RectangleShape,bool>> m_Turns;
	sf::Text m_text;
	sf::Font m_font;
private:
	void initTurnStateGraphic();
	void initText();
	void initFont();
	void initTurn();
};