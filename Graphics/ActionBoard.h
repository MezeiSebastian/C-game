#pragma once

#include"SFML/Graphics.hpp"

#include"Button.h"

class ActionBoard
{
public:
	ActionBoard();

	void render(sf::RenderTarget& target);
	void update(sf::RenderWindow& target);

	bool IsMovePressed();
	bool IsTreatPressed();
	bool IsCurePressed();
	bool IsBuildPressed();
	bool IsSharePressed();
	bool IsPassPressed();

	void SetPassWhite();
private:
	void initBox();
	void initFont();

	void initMoveButton();
	void initTreatButton();
	void initCureButton();
	void initBuildButton();
	void initShareButton();
	void initPassButton();

	void initSpriteMove();
	void initSpriteTreat();
	void initSpriteCure();
	void initSpriteBuild();
	void initSpritePass();
	void initSpriteShare();

private:
	sf::RectangleShape m_box;
	sf::Font m_font;

	Button* m_buttonMove;
	Button* m_buttonTreat;
	Button* m_buttonCure;
	Button* m_buttonBuild;
	Button* m_buttonShare;
	Button* m_buttonPass;

	std::pair<sf::Sprite,sf::Texture> m_spriteMove;
	std::pair<sf::Sprite,sf::Texture> m_spriteTreat;
	std::pair<sf::Sprite,sf::Texture> m_spriteCure;
	std::pair<sf::Sprite,sf::Texture> m_spriteBuild;
	std::pair<sf::Sprite,sf::Texture> m_spritePass;
	std::pair<sf::Sprite, sf::Texture> m_spriteShare;
};