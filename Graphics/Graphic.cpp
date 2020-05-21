#include "Graphic.h"

#include "SFML/Window.hpp"
#include "MenuState.h"
#include "SFML/Graphics.hpp"

#include<iostream>

Graphic::Graphic()
{
	initWindow();
	initState();
}

void Graphic::initWindow()
{
	m_window.create(sf::VideoMode::getFullscreenModes()[0], "Pandemic", sf::Style::Fullscreen);
	//m_view.reset(sf::FloatRect(viewStartX, viewStartY, viewWidth, viewHeight));
}

void Graphic::initState()
{
	m_states.push(new MenuState(m_window,m_states));
}

bool Graphic::run()
{
	while (m_window.isOpen())
	{
		updateSFMLEvents();
		update();
		render();
	}

	return true;
}

Graphic::~Graphic()
{

}

void Graphic::render()
{
	m_window.clear();

	//Render
	if (!m_states.empty())
		m_states.top()->render();

	m_window.display();
}

void Graphic::update()
{
	if (!m_states.empty())
		m_states.top()->update();
}

void Graphic::updateSFMLEvents()
{
	m_states.top()->updateSFMLEvents();
}
