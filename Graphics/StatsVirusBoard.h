#pragma once
#include"SFML/Graphics.hpp"

class StatsVirusBoard
{
public:
	StatsVirusBoard(const std::string& pathTexture);

	void Render(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2f& position);
	void SetScale(float x, float y);

	const sf::Vector2f& GetPosition() const;

	void SetString(const std::string& string);

	void SetTexture(const std::string& pathTexture);

private:
	void InitSpriteVirus(const std::string& path);
	void InitText();
	void InitFont();
private:
	sf::Sprite m_spriteVirus;
	sf::Texture m_textureVirus;
	sf::Text m_numberViruses;
	sf::Font m_font;
};