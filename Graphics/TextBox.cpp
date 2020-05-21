#include "TextBox.h"

TextBox::TextBox(int width, int height):m_width(width),m_height(m_height)
{
	m_cursorPos = 0;

	m_box.setSize(sf::Vector2f(m_width, m_height));
}

void TextBox::setCursorPosition(size_t position)
{
	if (position <= m_text.getString().getSize())
	{
		m_cursorPos = position;
	}
}

void TextBox::onKeyPressed(const sf::Event::KeyEvent& key)
{
}

void TextBox::onMousePressed(float x, float y)
{

}

void TextBox::onTextEntered(sf::Uint32 unicode)
{
}

void TextBox::Render(sf::RenderTarget& window)
{
	window.draw(m_box);
	window.draw(m_text);
}

void TextBox::setFillColorTextBox(const sf::Color& color)
{
	m_box.setFillColor(color);
}

void TextBox::setOutlineThicknessSize(int size)
{
	m_box.setOutlineThickness(size);
}

void TextBox::setOutlineThicknessColor(const sf::Color& color)
{
	m_box.setOutlineColor(color);
}

void TextBox::setTextColor(const sf::Color& color)
{
	m_text.setColor(color);
}
