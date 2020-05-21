#include "TeamInfo.h"

TeamInfo::TeamInfo()
{
	initFont();
	initBlackBox();
	initText();
}

void TeamInfo::Render(sf::RenderTarget& target)
{
	target.draw(m_blackBox);
	target.draw(m_text);

	if(m_blackBox.getSize().y>=500)
	for (int index = 0; index < m_players.size(); index++)
		m_players[index]->Rend(target);
}

void TeamInfo::Update()
{
	UpdateTextColor();

	if (IsMouseOnBlackBox() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_blackBox.setSize(sf::Vector2f(500, 500));
		m_text.setString("");
	}
}

void TeamInfo::AddPlayer(StatsTeamPlayer*& player)
{
	if (m_players.size() == 0)
		player->SetPosition(sf::Vector2f(this->m_blackBox.getPosition().x+10,this->m_blackBox.getPosition().y+50));

	m_players.push_back(player);
}

void TeamInfo::initText()
{
	m_text.setFont(m_font);
	m_text.setString("TEAM INFO");
	m_text.setCharacterSize(20);
	m_text.setPosition(m_blackBox.getPosition().x+10,m_blackBox.getPosition().y+20);
	m_text.setFillColor(sf::Color::White);
}

void TeamInfo::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void TeamInfo::initBlackBox()
{
	m_blackBox.setSize(sf::Vector2f(130,50));
	m_blackBox.setPosition(sf::Vector2f(1700,0));
	m_blackBox.setFillColor(sf::Color::Black);
	m_blackBox.setOutlineColor(sf::Color::White);
	m_blackBox.setOutlineThickness(5);
}

bool TeamInfo::IsMouseOnBlackBox()
{
	sf::Vector2i position = sf::Mouse::getPosition();
	if (m_blackBox.getPosition().x <= position.x && m_blackBox.getPosition().x + m_blackBox.getSize().x >= position.x
		&& m_blackBox.getPosition().y <= position.y && m_blackBox.getPosition().y + m_blackBox.getSize().y >= position.y)
		return true;
	return false;
}

void TeamInfo::UpdateTextColor()
{
	if (IsMouseOnBlackBox())
		m_text.setColor(sf::Color::Yellow);
	else m_text.setColor(sf::Color::White);
}


StatsTeamCity::StatsTeamCity(const std::string& cityName, const sf::Color& color)
{
	initFont();
	initShape(color);
	initText(cityName);
}

void StatsTeamCity::Rend(sf::RenderTarget& target)
{
	target.draw(m_rectShape);
	target.draw(m_text);
}

void StatsTeamCity::SetPosition(const sf::Vector2f& position)
{
	m_rectShape.setPosition(position);
	m_text.setPosition(position.x + 30 ,position.y);
}

void StatsTeamCity::initText(const std::string& string)
{
	m_text.setFont(m_font);
	m_text.setCharacterSize(25);
	m_text.setColor(sf::Color::White);
	m_text.setPosition(m_rectShape.getPosition().x + 10 , m_rectShape.getPosition().y);
	m_text.setString(string);
}

void StatsTeamCity::initShape(const sf::Color& color)
{
	m_rectShape.setPosition(100, 100);
	m_rectShape.setFillColor(color);
	m_rectShape.setSize(sf::Vector2f(10,20));
}

void StatsTeamCity::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void StatsTeamPlayer::Rend(sf::RenderTarget& target)
{
	for (int index = 0; index < m_statsTeamCities.size(); index++)
		m_statsTeamCities[index]->Rend(target);
}

void StatsTeamPlayer::AddCity(StatsTeamCity*& statsTeamCity)
{
	if (m_statsTeamCities.size() == 0)
		statsTeamCity->SetPosition(sf::Vector2f(m_position.x,m_position.y));

	m_statsTeamCities.push_back(statsTeamCity);
}

void StatsTeamPlayer::SetPosition(const sf::Vector2f& position)
{
	m_position = position;
}
