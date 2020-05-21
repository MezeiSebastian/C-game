#pragma once

#include"State.h"
#include"Button.h"

#include<stack>

class NewGameState :public State
{
public:
	NewGameState(sf::RenderWindow& window,std::vector<State*>& childStates,std::stack<State*>& parentStates);
	void render();
	void update();
	void endState();
	void updateSFMLEvents();
private:
	void initNewGameState();
	void initStartGameButton();
	void initPandemicLogo();
	void initFont();

	void updateStartGameButton();
	void updatePositionStartGameButton();
	void updateStateStartGameButton();

	void updatePandemicLogo();
	void updatePositionPandemicLogo();

	void rendStartGameButton();
	void rendPandemicLogo();

private:
	Button* m_startGameButton;
	sf::Font m_font;
	std::vector<State*>& m_childStates;
	std::stack<State*>& m_parentStates;
};