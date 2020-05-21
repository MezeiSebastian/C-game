#pragma once
#include "SFML/Graphics.hpp"

class TextBox
{
public:
	TextBox(int width, int height);

	void setCursorPosition(size_t position);
	void onKeyPressed(const sf::Event::KeyEvent& key);
	void onMousePressed(float x, float y);
	void onTextEntered(sf::Uint32 unicode);

	void Render(sf::RenderTarget& window);

	void setFillColorTextBox(const sf::Color& color);
	void setOutlineThicknessSize(int size);
	void setOutlineThicknessColor(const sf::Color& color);
	void setTextColor(const sf::Color& color);

private:
	int m_width;
	int m_height;

	sf::Text m_text;
	sf::RectangleShape m_box;

	int m_cursorPos;
};