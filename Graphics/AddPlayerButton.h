#pragma once
#include "SFML/Graphics.hpp"

class AddPlayerButton
{
public:
	AddPlayerButton();

	void update(sf::RenderWindow& target);
	void render(sf::RenderTarget& target);

	//Setters
	void SetPosition(const sf::Vector2f& position);

	bool IsPressed(sf::RenderWindow& window);

	//Getters
	const sf::Vector2f& GetPosition() const;
private:
	void updateOutline(sf::RenderWindow& target);
	
	bool IsMouseOnButton(const sf::Vector2f& position);
	
	void initTexture();
	void initRectShape();
private:
	sf::Texture* m_texture;
	sf::RectangleShape m_rectShape;
};