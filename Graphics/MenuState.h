#pragma once
#include"State.h"
#include"Button.h"

#include<stack>

#include"SelectPlayerState.h"
#include"SelectRoleState.h"
#include"NewGameState.h"

#define viewWidth 800
#define viewHeight 600
#define viewStartX 0
#define viewStartY 0

class MenuState:public State
{
public:
	MenuState(sf::RenderWindow& renderWindow,std::stack<State*>& states);

	void update() override;
	void render() override;
	void endState() override;
	void updateSFMLEvents() override;

private:
	void setView(sf::RenderWindow& renderWindow);
	void moveUpView();
	void moveDownView();
	void moveRightView();
	void moveLeftView();

	//1st Part
	void updateView();
	void updateBackground();

	void rendBackground();
	
	void initNewGameState();
	void initView();
	void initBackground();
	void initLogoPandemic();
	void initFont();
	//final 1st Part

	//SelectRolePart
	void initSelectRoleState();


	//ClearFunction
	void ClearFirstView();
private:

	//1st part
	sf::View m_menuStateView;
	sf::Font m_font;
	bool ok = false;

	//SelectRole Part
	std::vector<State*> m_childStates;
	std::stack<State*>& m_parentStates;
	//SelectRoleStates* m_selectRoleState;
	//SelectPlayerState* m_selectPlayerState;
	//NewGameState* m_newGameState;
};

