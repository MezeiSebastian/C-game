#include "SelectRoleState.h"

#include<thread>

SelectRoleStates::SelectRoleStates(sf::RenderWindow& window,std::vector<State*>& states,sf::Texture*& texture):
	State(window),
	m_states(states),
	m_sendedTexture(texture)
{
	initSpritesWithRoles();
}

void SelectRoleStates::update()
{
	updatePositionRectShapes();
	updateOutlineColorShapes();
	updateStatesShapes();
}

void SelectRoleStates::render()
{
	for (int index = 0; index < m_rolesTabs.size(); index++)
	m_window.draw(m_rolesTabs[index].first);
}

void SelectRoleStates::endState()
{
}

void SelectRoleStates::updateSFMLEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
	}
}

void SelectRoleStates::initSpritesWithRoles()
{
	
	std::thread t1([this] {this->initDoctor(); });
	std::thread t2([this] {this->initSoldier(); });
	std::thread t3([this] {this->initDispatcher(); });
	std::thread t4([this] {this->initResearcher(); });
	std::thread t5([this] {this->initOperationsExpert(); });
	std::thread t6([this] {this->initContingencyPlanner();});
	std::thread t7([this] {this->initQuarantineSpecialist(); });
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
}

void SelectRoleStates::initDoctor()
{
	sf::Texture* textureDoctor;
	textureDoctor = new sf::Texture();
	textureDoctor->loadFromFile("Res//Roles//Adi_Roles//RoleCard_3_Medic.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureDoctor);

	m_rolesTabs.push_back(std::make_pair(shape, textureDoctor));
}

void SelectRoleStates::initSoldier()
{
	sf::Texture* textureDoctor;
	textureDoctor = new sf::Texture();
	textureDoctor->loadFromFile("Res//Roles//Adi_Roles//RoleCard_4_OperationExpert.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureDoctor);

	m_rolesTabs.push_back(std::make_pair(shape, textureDoctor));
}

void SelectRoleStates::initDispatcher()
{
	sf::Texture* textureDispatcher;
	textureDispatcher = new sf::Texture();
	textureDispatcher->loadFromFile("Res//Roles//Adi_Roles//RoleCard_2_Dispatcher.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureDispatcher);

	m_rolesTabs.push_back(std::make_pair(shape,textureDispatcher));
}

void SelectRoleStates::initResearcher()
{
	sf::Texture* textureResearcher;
	textureResearcher = new sf::Texture();
	textureResearcher->loadFromFile("Res//Roles//Adi_Roles//RoleCard_6_Researcher.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureResearcher);

	m_rolesTabs.push_back(std::make_pair(shape, textureResearcher));
}

void SelectRoleStates::initOperationsExpert()
{
	sf::Texture* textureOperationsExpert;
	textureOperationsExpert = new sf::Texture();
	textureOperationsExpert->loadFromFile("Res//Roles//Adi_Roles//RoleCard_7_Scientist.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureOperationsExpert);

	m_rolesTabs.push_back(std::make_pair(shape, textureOperationsExpert));
}

void SelectRoleStates::initContingencyPlanner()
{
	sf::Texture* texturePlanner;
	texturePlanner = new sf::Texture();
	texturePlanner->loadFromFile("Res//Roles//Adi_Roles//RoleCard_1_ContingencyPlanner.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(texturePlanner);

	m_rolesTabs.push_back(std::make_pair(shape, texturePlanner));
}

void SelectRoleStates::initQuarantineSpecialist()
{
	sf::Texture* textureQuarantineSpecialist;
	textureQuarantineSpecialist = new sf::Texture();
	textureQuarantineSpecialist->loadFromFile("Res//Roles//Adi_Roles//RoleCard_5_QuarantineSpecialist.png");

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(textureQuarantineSpecialist);

	m_rolesTabs.push_back(std::make_pair(shape, textureQuarantineSpecialist));
}

void SelectRoleStates::updatePositionRectShapes()
{
	updatePositionDoctor();
	updatePositionSoldier();
	updatePositionDispatcher();
	updatePoistionResearcher();
	updatePositionOperationsExpert();
	updatePositionPlanner();
	updatePositionQuarantineSpecialist();
}

void SelectRoleStates::updatePositionDoctor()
{
	sf::Vector2f position;
	position.x = m_window.getView().getCenter().x-300;
	position.y = m_window.getView().getCenter().y - 250;
	m_rolesTabs[0].first.setPosition(position);
}

void SelectRoleStates::updatePositionSoldier()
{
	sf::Vector2f position = m_rolesTabs[0].first.getPosition();
	position.y += 120;
	m_rolesTabs[1].first.setPosition(position);
}

void SelectRoleStates::updatePositionDispatcher()
{
	sf::Vector2f position = m_rolesTabs[1].first.getPosition();

	position.y += 120;

	m_rolesTabs[2].first.setPosition(position);
}

void SelectRoleStates::updatePoistionResearcher()
{
	sf::Vector2f position = m_rolesTabs[2].first.getPosition();

	position.y += 120;

	m_rolesTabs[3].first.setPosition(position);
}

void SelectRoleStates::updatePositionOperationsExpert()
{
	sf::Vector2f position = m_rolesTabs[0].first.getPosition();

	position.x += 300;

	m_rolesTabs[4].first.setPosition(position);
}

void SelectRoleStates::updatePositionPlanner()
{
	sf::Vector2f position = m_rolesTabs[4].first.getPosition();

	position.y += 120;

	m_rolesTabs[5].first.setPosition(position);
}

void SelectRoleStates::updatePositionQuarantineSpecialist()
{
	sf::Vector2f position = m_rolesTabs[5].first.getPosition();

	position.y += 120;

	m_rolesTabs[6].first.setPosition(position);
}

void SelectRoleStates::updateOutlineColorShapes()
{

	for (int index = 0; index < m_rolesTabs.size(); index++)
	{
		if(IsMouseOnTab(m_rolesTabs[index]))
			m_rolesTabs[index].first.setOutlineColor(sf::Color::Black);
		else m_rolesTabs[index].first.setOutlineColor(sf::Color::Cyan);
	}
}

void SelectRoleStates::updateStatesShapes()
{
	for (int index = 0; index < m_rolesTabs.size(); index++)
		if (IsMouseOnTab(m_rolesTabs[index]) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_sendedTexture = m_rolesTabs[index].second;
			m_states.pop_back();
			return;
		}
}

bool SelectRoleStates::IsMouseOnTab(const std::pair<sf::RectangleShape, sf::Texture*>& roleTab)
{
	sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

	sf::Vector2f rectShapePositionTopLeft;
	rectShapePositionTopLeft.x = roleTab.first.getPosition().x;
	rectShapePositionTopLeft.y = roleTab.first.getPosition().y;

	sf::Vector2f rectShapePositionDownRight;
	rectShapePositionDownRight.x = roleTab.first.getPosition().x + roleTab.first.getSize().x;
	rectShapePositionDownRight.y = roleTab.first.getPosition().y + roleTab.first.getSize().y;

	return mousePos.x >= rectShapePositionTopLeft.x && mousePos.x <= rectShapePositionDownRight.x
		&& mousePos.y >= rectShapePositionTopLeft.y && mousePos.y <= rectShapePositionDownRight.y;
}
