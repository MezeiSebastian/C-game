#include "SelectPlayerState.h"

#include "SelectRoleState.h"

#include "GameState.h"

#include<iostream>

SelectPlayerState::SelectPlayerState(sf::RenderWindow& window,std::vector<State*>& childStates,std::stack<State*>& parentStates):
	State(window),
	m_childStates(childStates),
	m_parentStates(parentStates)
{
	m_begin = std::clock();

	initFont();
	initStartGameButton();
	initAddPlayerButtons();
	initBlackBoxAddPlayer();
}

void SelectPlayerState::update()
{
	UpdateAddPlayerButtons();

	UpdateBlackBoxAddPlayerPosition();

	updateStartGameButton();

	UpdatePositionPlayerStats();

	UpdateStatePlayerStats();
	UpdateTexturePlayers();

	IsPressedSelectRole();
}

void SelectPlayerState::updateSFMLEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
		else if (m_event.type == sf::Event::TextEntered)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
			{
				if(playerName.getSize()>=1)
				playerName.erase(playerName.getSize() - 1);
			}
			else
			{
				playerName += m_event.text.unicode;
			}
		}
	}
}

void SelectPlayerState::render()
{
	rendStartGameButton();

	rendAddPlayerButtons();

	rendBlackBoxAddPlayer();

	RendPlayer();
}

void SelectPlayerState::endState()
{
}


bool SelectPlayerState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
	return true;
}

void SelectPlayerState::initStartGameButton()
{
	m_startGameButton = new Button(sf::Vector2f(100, 100),sf::Vector2f(150,30), "Begin Game", m_font, sf::Color::Blue,5,sf::Color::Cyan);
}

void SelectPlayerState::initAddPlayerButtons()
{
	m_addPlayerButton1 = new AddPlayerButton();
	m_addPlayerButton2 = new AddPlayerButton();
	m_addPlayerButton3 = new AddPlayerButton();
	m_addPlayerButton4 = new AddPlayerButton();
}

void SelectPlayerState::initBlackBoxAddPlayer()
{
	m_blackBoxAddPlayer.first.setSize(sf::Vector2f(800,35));
	m_blackBoxAddPlayer.first.setFillColor(sf::Color::Black);
	m_blackBoxAddPlayer.first.setOutlineColor(sf::Color::Black);

	m_blackBoxAddPlayer.second.setFont(m_font);
	m_blackBoxAddPlayer.second.setString("Add Player");
	m_blackBoxAddPlayer.second.setCharacterSize(25);
	m_blackBoxAddPlayer.second.setColor(sf::Color::White);
}

void SelectPlayerState::initPlayerStats()
{
	m_Player1 = new PlayerStats();
}

void SelectPlayerState::UpdatePositionsAddPlayerButtons()
{
	if (m_addPlayerButton1 != nullptr)
	m_addPlayerButton1->SetPosition(sf::Vector2f(m_window.getView().getCenter().x - 380, m_window.getView().getCenter().y - 50));

	if(m_addPlayerButton2!=nullptr)
	m_addPlayerButton2->SetPosition(sf::Vector2f(m_window.getView().getCenter().x-180,m_window.getView().getCenter().y-50));

	if(m_addPlayerButton3!=nullptr)
	m_addPlayerButton3->SetPosition(sf::Vector2f(m_window.getView().getCenter().x + 20, m_window.getView().getCenter().y - 50));

	if(m_addPlayerButton4!=nullptr)
	m_addPlayerButton4->SetPosition(sf::Vector2f(m_window.getView().getCenter().x + 220, m_window.getView().getCenter().y - 50));
}

void SelectPlayerState::UpdateOutlineAddPlayerButtons()
{
	if(m_addPlayerButton1!=nullptr)
	m_addPlayerButton1->update(m_window);

	if(m_addPlayerButton2!=nullptr)
	m_addPlayerButton2->update(m_window);

	if(m_addPlayerButton3!=nullptr)
	m_addPlayerButton3->update(m_window);

	if(m_addPlayerButton4!=nullptr)
	m_addPlayerButton4->update(m_window);
}

void SelectPlayerState::UpdateAddPlayerButtons()
{
	UpdatePositionsAddPlayerButtons();
	UpdateOutlineAddPlayerButtons();
	UpdateAddPlayerButtonsState();
}

void SelectPlayerState::UpdateAddPlayerButtonsState()
{
	m_end = std::clock();
	if (m_end - m_begin > 500)
	{
		if (m_addPlayerButton1 != nullptr && m_addPlayerButton1->IsPressed(m_window))
		{
			m_addPlayerButton1 = nullptr;
			m_Player1 = new PlayerStats();
			m_Player1->setName("Player1");
		}

		else if (m_addPlayerButton2 != nullptr && m_addPlayerButton2->IsPressed(m_window))
		{
			m_addPlayerButton2 = nullptr;
			m_Player2 = new PlayerStats();
			m_Player2->setName("Player2");
		}

		else if (m_addPlayerButton3 != nullptr && m_addPlayerButton3->IsPressed(m_window))
		{
			m_addPlayerButton3 = nullptr;
			m_Player3 = new PlayerStats();
			m_Player3->setName("Player3");
		}

		else if (m_addPlayerButton4 != nullptr && m_addPlayerButton4->IsPressed(m_window))
		{
			m_addPlayerButton4 = nullptr;
			m_Player4 = new PlayerStats();
			m_Player4->setName("Player4");
		}
	}
}


void SelectPlayerState::updateStartGameButtonPosition()
{
	sf::Vector2f position;
	position.x = m_window.getView().getCenter().x + 200;
	position.y = m_window.getView().getCenter().y + 200;

	if (m_startGameButton != nullptr)
		m_startGameButton->UpdatePosition(position);
}

void SelectPlayerState::updateStartGameButtonState()
{
	m_startGameButton->UpdateState(m_window);

	if (m_startGameButton->IsPressed())
	{
		m_childStates.clear();
		m_parentStates.push(new GameState(m_window));
	}
}

void SelectPlayerState::updateStartGameButton()
{
	updateStartGameButtonPosition();
	updateStartGameButtonState();
}

void SelectPlayerState::UpdateBlackBoxAddPlayerPosition()
{
	m_blackBoxAddPlayer.first.setPosition(m_window.getView().getCenter().x-400, m_window.getView().getCenter().y-250);

	m_blackBoxAddPlayer.second.setPosition(m_window.getView().getCenter().x-60,m_blackBoxAddPlayer.first.getPosition().y);
}

void SelectPlayerState::UpdatePositionPlayerStats()
{
	if(m_Player1!=nullptr)
	m_Player1->setPosition(sf::Vector2f(m_window.getView().getCenter().x-380,m_window.getView().getCenter().y-50));

	if (m_Player2 != nullptr)
		m_Player2->setPosition(sf::Vector2f(m_window.getView().getCenter().x - 180, m_window.getView().getCenter().y - 50));

	if (m_Player3 != nullptr)
		m_Player3->setPosition(sf::Vector2f(m_window.getView().getCenter().x + 20, m_window.getView().getCenter().y - 50));

	if (m_Player4 != nullptr)
		m_Player4->setPosition(sf::Vector2f(m_window.getView().getCenter().x + 220, m_window.getView().getCenter().y - 50));
}

void SelectPlayerState::UpdateStatePlayerStats()
{
	if (m_Player1 != nullptr)
		m_Player1->update(m_window);

	if (m_Player2 != nullptr)
		m_Player2->update(m_window);

	if (m_Player3 != nullptr)
		m_Player3->update(m_window);

	if (m_Player4 != nullptr)
		m_Player4->update(m_window);
}

void SelectPlayerState::IsPressedSelectRole()
{
	if (m_Player1 != nullptr && m_Player1->isPressedSelectRole())
		m_childStates.push_back(new SelectRoleStates(m_window,m_childStates, m_Player1->getTexture()));

	else if (m_Player2 != nullptr && m_Player2->isPressedSelectRole())
		m_childStates.push_back(new SelectRoleStates(m_window, m_childStates, m_Player2->getTexture()));

	if (m_Player3 != nullptr && m_Player3->isPressedSelectRole())
		m_childStates.push_back(new SelectRoleStates(m_window, m_childStates, m_Player3->getTexture()));

	if (m_Player4 != nullptr && m_Player4->isPressedSelectRole())
		m_childStates.push_back(new SelectRoleStates(m_window, m_childStates, m_Player4->getTexture()));
}

void SelectPlayerState::UpdateTexturePlayers()
{
	  if(m_Player1!=nullptr)
	    m_Player1->setTexture(m_Player1->getTexture());
	 
	if (m_Player2 != nullptr)
		m_Player2->setTexture(m_Player2->getTexture());

	if (m_Player3 != nullptr)
		m_Player3->setTexture(m_Player3->getTexture());

	if (m_Player4 != nullptr)
		m_Player4->setTexture(m_Player4->getTexture());
}

void SelectPlayerState::RendPlayer()
{
	if(m_Player1!=nullptr)
	m_Player1->render(m_window);

	if (m_Player2 != nullptr)
		m_Player2->render(m_window);

	if (m_Player3 != nullptr)
		m_Player3->render(m_window);

	if (m_Player4 != nullptr)
		m_Player4->render(m_window);
}

void SelectPlayerState::rendStartGameButton()
{
	m_startGameButton->Rend(m_window);
}

void SelectPlayerState::rendAddPlayerButtons()
{
	if(m_addPlayerButton1!=nullptr)
	m_addPlayerButton1->render(m_window);

	if(m_addPlayerButton2!=nullptr)
	m_addPlayerButton2->render(m_window);

	if(m_addPlayerButton3!=nullptr)
	m_addPlayerButton3->render(m_window);

	if(m_addPlayerButton4!=nullptr)
	m_addPlayerButton4->render(m_window);
}

void SelectPlayerState::rendBlackBoxAddPlayer()
{
	m_window.draw(m_blackBoxAddPlayer.first);
	m_window.draw(m_blackBoxAddPlayer.second);
}
