#pragma once
#include"SFML/Graphics.hpp"

#include"Button.h"

class PlayerStats
{
public:
	PlayerStats();

	void render(sf::RenderWindow& window);
	void update(sf::RenderWindow& target);

	void setPosition(const sf::Vector2f& position);
	void setTexture(sf::Texture*& texture);
	void setName(const std::string& name);

	bool isPressedSelectRole();

	sf::Texture*& getTexture();
private:
	void initPlayerStats();
	void initPersonTab();
	void initButton();
	bool initFont();
	void initPlayerTabsName();
private:
	std::pair<sf::RectangleShape,sf::Texture*>  m_texturePlayer;

	Button* m_selectRoleButton;

	std::pair<sf::RectangleShape,sf::Text> m_textBoxName;

	sf::Font m_font;
};