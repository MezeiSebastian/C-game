#include "NewGameState.h"
#include "SelectPlayerState.h"

NewGameState::NewGameState(sf::RenderWindow& window, std::vector<State*>& childStates,std::stack<State*>& parentStates):
	State(window),
	m_childStates(childStates),
	m_parentStates(parentStates)
{
	initNewGameState();
}

void NewGameState::render()
{
	rendPandemicLogo();
	rendStartGameButton();
}

void NewGameState::update()
{
	updateStartGameButton();
	updatePandemicLogo();
}

void NewGameState::endState()
{
}

void NewGameState::updateSFMLEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
	}
}

void NewGameState::initNewGameState()
{
	initFont();
	initStartGameButton();
	initPandemicLogo();
}

void NewGameState::initStartGameButton()
{
	sf::Color colorBlue(0, 0, 255, 255);
	m_startGameButton = new Button(sf::Vector2f(100, 100), sf::Vector2f(300, 40), "New Game", m_font,
		colorBlue, 3, sf::Color::Cyan);
}

void NewGameState::initPandemicLogo()
{
	sf::Texture logoPandemicTexture;

	if (!logoPandemicTexture.loadFromFile("Res//Pandemic.png"))
		throw("could not load logoPandemic");

	m_textures["pandemicLogo"] = logoPandemicTexture;

	sf::Sprite logoPandemicSprite(m_textures["pandemicLogo"]);
	logoPandemicSprite.setScale(0.3, 0.3);

	m_sprites["pandemicLogo"] = logoPandemicSprite;
}

void NewGameState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void NewGameState::updateStartGameButton()
{
	updatePositionStartGameButton();
	updateStateStartGameButton();
}

void NewGameState::updatePositionStartGameButton()
{
	sf::Vector2f position;
	position.x = m_window.getView().getCenter().x - m_startGameButton->GetShapeSize().x / 2;
	position.y = m_window.getView().getCenter().y;

	m_startGameButton->UpdatePosition(position);
}

void NewGameState::updateStateStartGameButton()
{
	m_startGameButton->UpdateState(m_window);

	if (m_startGameButton->IsPressed())
		m_childStates.push_back(new SelectPlayerState(m_window,m_childStates,m_parentStates));
}

void NewGameState::updatePandemicLogo()
{
	updatePositionPandemicLogo();
}

void NewGameState::updatePositionPandemicLogo()
{
	m_sprites["pandemicLogo"].setPosition(m_window.getView().getCenter().x - m_sprites["pandemicLogo"].getGlobalBounds().width / 2,
		m_window.getView().getCenter().y - m_sprites["pandemicLogo"].getGlobalBounds().height);
}

void NewGameState::rendStartGameButton()
{
	m_startGameButton->Rend(m_window);
}

void NewGameState::rendPandemicLogo()
{
	m_window.draw(m_sprites["pandemicLogo"]);
}
