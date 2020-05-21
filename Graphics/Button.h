#pragma once
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"

enum class ButtonStates
{
	BTN_IDLE,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button 
{
private:
	sf::RectangleShape m_shape;
	sf::Font m_font;
	sf::Text m_text;
	ButtonStates m_buttonState;
	sf::Texture m_texture;

	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;
public:
	//Constructor
	Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text,
		const sf::Font& font,
		const sf::Color& idleColor,
		const float thicknes = 0,
		const sf::Color& thicknesColor = sf::Color::Transparent,
		int characterSize = 15);

	//Render
	void Rend(sf::RenderTarget& target) const;

	//Update
	void UpdateState(sf::RenderWindow& window);
	void UpdatePosition(const sf::Vector2f& position);
	//Verify if button is pressed
	bool IsPressed() const;
	bool IsMouseOnButton(sf::RenderWindow& window) const;

	void SetText(const std::string& string);

	sf::Text& GetText();

	//Getters
	const sf::Vector2f& GetShapeSize() const;
	const sf::Vector2f& GetPosition() const;
	const sf::Vector2f& GetPositionText() const;
};