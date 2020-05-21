#pragma once
#include"SFML/Graphics.hpp"

#include"State.h"
#include"Logger.h"

#include"SFML/Audio.hpp"

#include<memory>
#include<stack>

class Graphic
{
public:
	Graphic();
	~Graphic();

	bool run();
private:
	void initWindow();
	void initState();

	void updateSFMLEvents();
	void render();
	void update();
private:
	sf::RenderWindow m_window;
	std::stack<State*> m_states;
	sf::Event m_event;
	sf::View m_view;

	Logger m_logger;
};