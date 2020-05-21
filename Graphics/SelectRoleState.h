#pragma once
#include"State.h"

class SelectRoleStates: public State
{
public:
	SelectRoleStates(sf::RenderWindow& window,std::vector<State*>& states,sf::Texture*& texture);

	void update();
	void render();
	void endState();
	void updateSFMLEvents();
private:
	void initSpritesWithRoles();

	void initDoctor();
	void initSoldier();
	void initDispatcher();
	void initResearcher();
	void initOperationsExpert();
	void initContingencyPlanner();
	void initQuarantineSpecialist();

	void updatePositionRectShapes();

	void updatePositionDoctor();
	void updatePositionSoldier();
	void updatePositionDispatcher();
	void updatePoistionResearcher();
	void updatePositionOperationsExpert();
	void updatePositionPlanner();
	void updatePositionQuarantineSpecialist();

	void updateOutlineColorShapes();
	void updateStatesShapes();
	
	bool IsMouseOnTab(const std::pair<sf::RectangleShape, sf::Texture*>& roleTab);

private:
	std::vector<std::pair<sf::RectangleShape, sf::Texture*>> m_rolesTabs;
	std::vector<State*>& m_states;
	sf::Texture*& m_sendedTexture;
};