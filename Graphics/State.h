#pragma once
#include"SFML/Graphics.hpp"

#include<memory>
#include<vector>
#include<map>
#include<string>

class State
{
public:
	State(sf::RenderWindow& window);
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void endState() = 0;
	virtual void updateSFMLEvents() = 0;

public:
	std::map<std::string,sf::Texture> m_textures;
	std::map<std::string,sf::Sprite>m_sprites;
	sf::RenderWindow& m_window;
	sf::Event m_event;
};

