#include "AddPlayerButton.h"

AddPlayerButton::AddPlayerButton()
{
	m_texture = nullptr;

	initTexture();
	initRectShape();
}

void AddPlayerButton::update(sf::RenderWindow& target)
{
	updateOutline(target);
}

void AddPlayerButton::render(sf::RenderTarget& target)
{
	target.draw(m_rectShape);
}

void AddPlayerButton::SetPosition(const sf::Vector2f& position)
{
	m_rectShape.setPosition(position);
}

bool AddPlayerButton::IsPressed(sf::RenderWindow& window)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

	if (IsMouseOnButton(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;

	return false;
}

const sf::Vector2f& AddPlayerButton::GetPosition() const
{
	return m_rectShape.getPosition();
}

void AddPlayerButton::updateOutline(sf::RenderWindow& window)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

	if(IsMouseOnButton(mousePos))
		m_rectShape.setOutlineColor(sf::Color::Black);

	else m_rectShape.setOutlineColor(sf::Color::Cyan);
}

bool AddPlayerButton::IsMouseOnButton(const sf::Vector2f& mousePos)
{
	if (mousePos.x >= m_rectShape.getPosition().x && mousePos.x <= m_rectShape.getPosition().x + m_rectShape.getSize().x
		&& mousePos.y >= m_rectShape.getPosition().y && mousePos.y <= m_rectShape.getPosition().y + m_rectShape.getSize().y)
		return true;
	return false;
}

void AddPlayerButton::initTexture()
{
	m_texture = new sf::Texture();
	if (!m_texture->loadFromFile("Res//PlusAddPlayer//BluePlus.png"))
		throw std::string("could not load BluePlus.png");
}

void AddPlayerButton::initRectShape()
{
	m_rectShape.setTexture(m_texture);
	m_rectShape.setSize(sf::Vector2f(150, 100));
	m_rectShape.setOutlineThickness(5);
	m_rectShape.setOutlineColor(sf::Color::Cyan);
}
