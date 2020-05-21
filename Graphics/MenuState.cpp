#include "MenuState.h"

#include<iostream>
#include<stack>

MenuState::MenuState(sf::RenderWindow& renderWindow,std::stack<State*>& states):
	State(renderWindow),
	m_parentStates(states)
{
	try
	{
		initFont();
		initBackground();
		initLogoPandemic();
		initView();
		initNewGameState();
		setView(m_window);
	}
	catch(const std::string& error)
	{
		std::cout << error;
	}
}

void MenuState::update()
{
	updateView();
	updateBackground();

	m_childStates.back()->update();
}

void MenuState::render()
{
	rendBackground();

	m_childStates.back()->render();

	//rendLogoPandemic();
}

void MenuState::endState()
{

}

void MenuState::updateSFMLEvents()
{
	m_childStates.back()->updateSFMLEvents();
}

void MenuState::initNewGameState()
{
	m_childStates.push_back(new NewGameState(m_window,m_childStates,m_parentStates));
}

void MenuState::initView()
{
	m_menuStateView.reset(sf::FloatRect(viewStartX, viewStartY, viewWidth, viewHeight));
}

void MenuState::setView(sf::RenderWindow& renderWindow)
{
	renderWindow.setView(m_menuStateView);
}

void MenuState::moveUpView()
{
	m_menuStateView.move(sf::Vector2f(0,-0.5));
}

void MenuState::moveDownView()
{
	m_menuStateView.move(0,0.5);
}

void MenuState::moveRightView()
{
	m_menuStateView.move(0.5, 0);
}

void MenuState::moveLeftView()
{
	m_menuStateView.move(-0.1, 0);
}


void MenuState::updateView()
{
	if (m_menuStateView.getCenter().y - m_menuStateView.getSize().y/2 <= 0)
		ok = true;
	else if (m_menuStateView.getCenter().y + m_menuStateView.getSize().y/2 >= m_textures["background"].getSize().y)
		ok = false;
		if(!ok)
		moveUpView();
	else moveDownView();
	moveRightView();
	m_window.setView(m_menuStateView);
}

void MenuState::updateBackground()
{
	if (m_menuStateView.getCenter().x + m_menuStateView.getSize().x / 2 ==
		m_sprites["backgroundLeft"].getPosition().x + m_sprites["backgroundLeft"].getTexture()->getSize().x)

		m_sprites["backgroundRight"].setPosition(m_menuStateView.getCenter().x + m_menuStateView.getSize().x / 2, 0);

	if (m_menuStateView.getCenter().x + m_menuStateView.getSize().x / 2 ==
		m_sprites["backgroundRight"].getPosition().x + m_sprites["backgroundRight"].getTexture()->getSize().x)

		m_sprites["backgroundLeft"].setPosition(m_menuStateView.getCenter().x + m_menuStateView.getSize().x / 2, 0);
}

void MenuState::rendBackground()
{
    m_window.draw(m_sprites["backgroundLeft"]);
	m_window.draw(m_sprites["backgroundRight"]);
}

 
void MenuState::initBackground()
{
	sf::Texture backgroundTexture;

	if (!backgroundTexture.loadFromFile("Res//Background.png"))
		throw("could not load background");

	m_textures["background"] = backgroundTexture;

	sf::Sprite backgroundSpriteLeft(m_textures["background"]);
	sf::Sprite backgroundSpriteRight(m_textures["background"]);

	m_sprites["backgroundLeft"] = backgroundSpriteLeft;
	m_sprites["backgroundRight"] = backgroundSpriteRight;
}

void MenuState::initLogoPandemic()
{
}


void MenuState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void MenuState::initSelectRoleState()
{
}

