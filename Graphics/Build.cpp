#include "Build.h"

Build::Build()
{
	InitBuildSprite();
}

void Build::Rend(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}

void Build::SetPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

void Build::InitBuildSprite()
{
	m_texture.loadFromFile("Res//Hospital.png");

	m_sprite.setTexture(m_texture);
	
	m_sprite.setPosition(500, 500);

	m_sprite.setScale(0.03, 0.03);
}
