#include "PlayerStats.h"

PlayerStats::PlayerStats()
{
	initPlayerStats();
}

void PlayerStats::render(sf::RenderWindow& window)
{
	m_selectRoleButton->Rend(window);

	window.draw(m_textBoxName.first);

	window.draw(m_textBoxName.second);

	window.draw(m_texturePlayer.first);
}

void PlayerStats::update(sf::RenderWindow& target)
{
	m_selectRoleButton->UpdateState(target);
}

void PlayerStats::setPosition(const sf::Vector2f& position)
{
	m_texturePlayer.first.setPosition(position);

	m_textBoxName.first.setPosition(m_texturePlayer.first.getPosition().x + 100, m_texturePlayer.first.getPosition().y + 50);

	m_textBoxName.second.setPosition(m_texturePlayer.first.getPosition().x + 100, m_texturePlayer.first.getPosition().y + 50);

	m_selectRoleButton->UpdatePosition(sf::Vector2f(m_texturePlayer.first.getPosition().x + 100, m_texturePlayer.first.getPosition().y));
}

void PlayerStats::setTexture(sf::Texture*& texture)
{
	m_texturePlayer.first.setTexture(texture, true);
}

void PlayerStats::setName(const std::string& name)
{
	m_textBoxName.second.setString(name);
}

bool PlayerStats::isPressedSelectRole()
{
	return m_selectRoleButton->IsPressed();
}

sf::Texture*& PlayerStats::getTexture()
{
	return m_texturePlayer.second;
}

void PlayerStats::initPlayerStats()
{
	initFont();
	initPersonTab();
	initButton();
	initPlayerTabsName();
}

void PlayerStats::initPersonTab()
{
	sf::Texture* anonymousPersonTexture;
	anonymousPersonTexture = new sf::Texture();
	anonymousPersonTexture->loadFromFile("Res//Anonymous.png");

	m_texturePlayer.second = anonymousPersonTexture;

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(80, 100));
	shape.setTexture(m_texturePlayer.second);

	m_texturePlayer.first = shape;
}

void PlayerStats::initButton()
{
	m_selectRoleButton=new Button(sf::Vector2f(0, 0), sf::Vector2f(85, 30), "select role", m_font, sf::Color::Blue,
		3, sf::Color::Cyan);
}

bool PlayerStats::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
	return true;
}

void PlayerStats::initPlayerTabsName()
{
	sf::RectangleShape tabName1(sf::Vector2f(85, 30));
	sf::RectangleShape tabName2(sf::Vector2f(100, 30));

	tabName1.setOutlineThickness(5);
	tabName1.setOutlineColor(sf::Color::Cyan);

	tabName2.setOutlineThickness(5);
	tabName2.setOutlineColor(sf::Color::Cyan);

	sf::Text text1;
	text1.setFont(m_font);
	text1.setString("mama");
	text1.setCharacterSize(15);
	text1.setColor(sf::Color::Black);
	sf::Text text2;

	m_textBoxName=std::make_pair(tabName1, text1);
}
