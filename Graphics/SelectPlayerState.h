#pragma once
#include"State.h"

#include"AddPlayerButton.h"
#include"PlayerStats.h"

#include<stack>
#include<time.h>

class SelectPlayerState :public State
{
public:
	SelectPlayerState(sf::RenderWindow& window,std::vector<State*>& childStates,std::stack<State*>& parentStates);
	void update();
	void updateSFMLEvents();
	void render();
	void endState();
private:

	//InitFunction
	bool initFont();
	void initStartGameButton();

	void initAddPlayerButtons();
	void initBlackBoxAddPlayer();

	void initPlayerStats();

	//Update
	void updateStartGameButtonPosition();
	void updateStartGameButtonState();
	void updateStartGameButton();

	void UpdatePositionsAddPlayerButtons();
	void UpdateOutlineAddPlayerButtons();
	void UpdateAddPlayerButtons();
	void UpdateAddPlayerButtonsState();

	void UpdateBlackBoxAddPlayerPosition();

	void UpdatePositionPlayerStats();

	void UpdateStatePlayerStats();

	void IsPressedSelectRole();
	void UpdateTexturePlayers();
	//Rend
	void RendPlayer();

	void rendStartGameButton();
	void rendAddPlayerButtons();

	void rendBlackBoxAddPlayer();
private:
	std::vector<std::pair<sf::RectangleShape, sf::Texture*>> m_playerTabsTexture;
	std::vector<std::pair<sf::RectangleShape, sf::Text>> m_playerTabsName;

	std::vector<Button*> m_selectRoleButtons;
	sf::Font m_font;
	std::vector<State*>& m_childStates;
	std::stack<State*>& m_parentStates;
	sf::String playerName;
	Button* m_startGameButton;

	AddPlayerButton *m_addPlayerButton1;
	AddPlayerButton *m_addPlayerButton2;
	AddPlayerButton *m_addPlayerButton3;
	AddPlayerButton *m_addPlayerButton4;

	PlayerStats* m_Player1;
	PlayerStats* m_Player2;
	PlayerStats* m_Player3;
	PlayerStats* m_Player4;

	std::pair<sf::RectangleShape, sf::Text> m_blackBoxAddPlayer;
	std::clock_t m_begin;
	std::clock_t m_end;
};