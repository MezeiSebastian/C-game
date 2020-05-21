#include "StatsVirusBoard.h"

StatsVirusBoard::StatsVirusBoard(const std::string& pathTexture)
{
	InitSpriteVirus(pathTexture);
	InitFont();
	InitText();
}

void StatsVirusBoard::Render(sf::RenderTarget& target)
{
	target.draw(m_spriteVirus);
	target.draw(m_numberViruses);
}

void StatsVirusBoard::SetPosition(const sf::Vector2f& position)
{
	m_spriteVirus.setPosition(position);

	m_numberViruses.setPosition(position);
	m_numberViruses.setPosition(m_numberViruses.getPosition().x + 35, m_numberViruses.getPosition().y);
}

void StatsVirusBoard::SetScale(float x, float y)
{
	m_spriteVirus.setScale(x, y);
}

void StatsVirusBoard::InitSpriteVirus(const std::string& path)
{
	if(!m_textureVirus.loadFromFile(path))
		throw std::string("could not open the red square png");

	m_spriteVirus.setTexture(m_textureVirus);
	m_spriteVirus.setScale(sf::Vector2f(0.2,0.2));
}

void StatsVirusBoard::InitText()
{
	m_numberViruses.setFont(m_font);
	m_numberViruses.setCharacterSize(25);
	m_numberViruses.setColor(sf::Color::White);
	m_numberViruses.setString("24");

	sf::Vector2f position(m_spriteVirus.getPosition());
	position.x += 60;
	m_numberViruses.setPosition(position);
}

void StatsVirusBoard::InitFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

const sf::Vector2f& StatsVirusBoard::GetPosition() const
{
	return m_spriteVirus.getPosition();
}

void StatsVirusBoard::SetString(const std::string& string)
{
	m_numberViruses.setString(string);
}

void StatsVirusBoard::SetTexture(const std::string& pathTexture)
{
	m_textureVirus.loadFromFile(pathTexture);
}
