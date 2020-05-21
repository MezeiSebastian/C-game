#include "BoardCity.h"

BoardCity::BoardCity(sf::Sprite& circle, sf::Text& text,sf::Color colorCity):m_circle(circle),m_text(text)
{
	m_build.second = false;

	m_build.first = nullptr;

	m_ColorCity = colorCity;

	m_circle.setOrigin(sf::Vector2f(0, 0));
	normalColor = sf::Color::White;
	hoverColor = sf::Color::Yellow;
}

void BoardCity::Rend(sf::RenderTarget& target)
{
	target.draw(m_text);
	target.draw(m_circle);

	for (int index = 0; index < m_Virus.size(); index++)
		target.draw(m_Virus[index].second);

	if (m_build.second == true)
		m_build.first->Rend(target);
}

void BoardCity::SetPosition(const sf::Vector2i& pos)
{
	m_circle.setPosition(pos.x,pos.y);

	int x = m_circle.getScale().y * m_circle.getTexture()->getSize().y;

	m_text.setPosition(pos.x,pos.y+x);
}

void BoardCity::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition().x >= m_circle.getPosition().x && sf::Mouse::getPosition().x<=m_circle.getPosition().x+m_circle.getScale().x*m_circle.getTexture()->getSize().x &&
		sf::Mouse::getPosition().y >= m_circle.getPosition().y && sf::Mouse::getPosition().y<=m_circle.getPosition().y+m_circle.getScale().y*m_circle.getTexture()->getSize().y)   
		m_text.setColor(hoverColor);
	else m_text.setColor(normalColor);
}

const sf::Text& BoardCity::GetText() const
{
	return m_text;
}

const sf::Vector2f& BoardCity::GetPosition() const
{
	return m_circle.getPosition();
}

const sf::Vector2f& BoardCity::GetCenterShape() const
{
	return m_circle.getPosition();
}

const sf::Color& BoardCity::GetColor() const
{
	return m_circle.getColor();
}

bool BoardCity::IsMouseOnCity()
{
	if (sf::Mouse::getPosition().x >= m_circle.getPosition().x && sf::Mouse::getPosition().x <= m_circle.getPosition().x + m_circle.getScale().x * m_circle.getTexture()->getSize().x &&
		sf::Mouse::getPosition().y >= m_circle.getPosition().y && sf::Mouse::getPosition().y <= m_circle.getPosition().y + m_circle.getScale().y * m_circle.getTexture()->getSize().y)
		return true;

	return false;
}

bool BoardCity::IsCityPressed()
{
	if (IsMouseOnCity() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;
	return false;
}

void BoardCity::SetNormalColor()
{
	normalColor = sf::Color::White;
}

const sf::Color& BoardCity::GetColorCity()
{
	return m_ColorCity;
}

void BoardCity::AddYellowVirus()
{
	sf::RectangleShape m_rectShape;
	m_rectShape.setFillColor(sf::Color::Yellow);
	m_rectShape.setOutlineThickness(2);
	m_rectShape.setOutlineColor(sf::Color(sf::Color::Black));
	m_rectShape.setSize(sf::Vector2f(5, 35));

	std::string string = "Yellow";


	if (m_Virus.size() == 0)
	{
		m_rectShape.setPosition(m_circle.getPosition().x+50,m_circle.getPosition().y);
	}

	else
	{
		m_rectShape.setPosition(m_Virus.back().second.getPosition().x + 8, m_Virus.back().second.getPosition().y);
	}

	m_Virus.push_back(std::make_pair("Yellow", m_rectShape));
}

void BoardCity::AddBlackVirus()
{
	sf::RectangleShape m_rectShape;
	m_rectShape.setFillColor(sf::Color::Black);
	m_rectShape.setOutlineThickness(2);
	m_rectShape.setOutlineColor(sf::Color(sf::Color::White));
	m_rectShape.setSize(sf::Vector2f(5, 35));

	std::string string = "Black";


	if (m_Virus.size() == 0)
	{
		m_rectShape.setPosition(m_circle.getPosition().x + 50, m_circle.getPosition().y);
	}

	else
	{
		m_rectShape.setPosition(m_Virus.back().second.getPosition().x + 8, m_Virus.back().second.getPosition().y);
	}

	m_Virus.push_back(std::make_pair("Black", m_rectShape));
}

void BoardCity::AddRedVirus()
{
	sf::RectangleShape m_rectShape;
	m_rectShape.setFillColor(sf::Color::Red);
	m_rectShape.setOutlineThickness(2);
	m_rectShape.setOutlineColor(sf::Color(sf::Color::Black));
	m_rectShape.setSize(sf::Vector2f(5, 35));

	std::string string = "Red";


	if (m_Virus.size() == 0)
	{
		m_rectShape.setPosition(m_circle.getPosition().x + 50, m_circle.getPosition().y);
	}

	else
	{
		m_rectShape.setPosition(m_Virus.back().second.getPosition().x + 8, m_Virus.back().second.getPosition().y);
	}

	m_Virus.push_back(std::make_pair("Red", m_rectShape));
}

void BoardCity::AddBlueVirus()
{
	sf::RectangleShape m_rectShape;
	m_rectShape.setFillColor(sf::Color::Blue);
	m_rectShape.setOutlineThickness(2);
	m_rectShape.setOutlineColor(sf::Color(sf::Color::Black));
	m_rectShape.setSize(sf::Vector2f(5, 35));

	std::string string = "Blue";


	if (m_Virus.size() == 0)
	{
		m_rectShape.setPosition(m_circle.getPosition().x + 50, m_circle.getPosition().y);
	}

	else
	{
		m_rectShape.setPosition(m_Virus.back().second.getPosition().x + 8, m_Virus.back().second.getPosition().y);
	}

	m_Virus.push_back(std::make_pair("Blue", m_rectShape));
}

int BoardCity::GetNumberOfVirus()
{
	return m_Virus.size();
}

void BoardCity::EliminateVirus()
{
	m_Virus.pop_back();
}

const std::string& BoardCity::GetLastVirusColor()
{
	return m_Virus.back().first;
}

int BoardCity::getNumberOfYellowVirus()
{
	int numberOfYellowVirus = 0;
	for (auto virus : m_Virus)
		if (virus.first == "Yellow")
			numberOfYellowVirus++;
	return numberOfYellowVirus;
}

int BoardCity::getNumberOfRedVirus()
{
	int numberOfRedVirus = 0;
	for (auto virus : m_Virus)
		if (virus.first == "Red")
			numberOfRedVirus++;
	return numberOfRedVirus;
}

int BoardCity::getNumberOfBlueVirus()
{
	int numberOfBlueVirus = 0;
	for (auto virus : m_Virus)
		if (virus.first == "Blue")
			numberOfBlueVirus++;
	return numberOfBlueVirus;
}

int BoardCity::getNumberOfBlackVirus()
{
	int numberOfBlackVirus = 0;
	for (auto virus : m_Virus)
		if (virus.first == "Black")
			numberOfBlackVirus++;
	return numberOfBlackVirus;
}

void BoardCity::setAvailable()
{
	normalColor = sf::Color::Green;
}

void BoardCity::AddBuild()
{
	m_build.first = new Build();
	m_build.second = true;
	m_build.first->SetPosition(sf::Vector2f(m_circle.getPosition().x-40, m_circle.getPosition().y ));
}

bool BoardCity::HaveResearchStation()
{
	return m_build.second;
}

void BoardCity::AddPlayersInPosition(const sf::Vector2f& position)
{
	m_PositionFromPlayers.push_back(position);
}

const sf::Vector2f& BoardCity::GetLastPositionFromPlayers()
{
	if (m_PositionFromPlayers.size() == 0)
		return sf::Vector2f(m_circle.getPosition().x-10,m_circle.getPosition().y-30);

	return m_PositionFromPlayers.back();
}

void BoardCity::AddNeighbourCity(const std::string& cityName, BoardCity*& city)
{
	m_neighbouringCities.insert(std::make_pair(cityName, city));
}

std::map<std::string, BoardCity*>& BoardCity::getNeighborCities()
{
	return m_neighbouringCities;
}

