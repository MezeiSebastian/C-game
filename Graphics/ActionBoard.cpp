#include "ActionBoard.h"

ActionBoard::ActionBoard()
{
	initBox();
	initFont();
	initMoveButton();
	initTreatButton();
	initCureButton();
	initBuildButton();
	initShareButton();
	initPassButton();

	initSpriteMove();
	initSpriteTreat();
	initSpriteCure();
	initSpriteBuild();
	initSpritePass();
	initSpriteShare();
}

void ActionBoard::render(sf::RenderTarget& target)
{
	target.draw(m_box);
	m_buttonMove->Rend(target);
	m_buttonTreat->Rend(target);
	m_buttonCure->Rend(target);
	m_buttonBuild->Rend(target);
	m_buttonShare->Rend(target);
	m_buttonPass->Rend(target);

	target.draw(m_spriteMove.first);
	target.draw(m_spriteTreat.first);
	target.draw(m_spriteCure.first);
	target.draw(m_spriteBuild.first);
	target.draw(m_spritePass.first);
	target.draw(m_spriteShare.first);
}

void ActionBoard::update(sf::RenderWindow& target)
{
	m_buttonBuild->UpdateState(target);
	m_buttonCure->UpdateState(target);
	m_buttonPass->UpdateState(target);
	m_buttonMove->UpdateState(target);
	m_buttonShare->UpdateState(target);
	m_buttonTreat->UpdateState(target);
}

void ActionBoard::initBox()
{
	m_box.setSize(sf::Vector2f(1920, 200));
	m_box.setOutlineThickness(5);
	m_box.setOutlineColor(sf::Color::White);
	m_box.setPosition(0, 1000);
	m_box.setFillColor(sf::Color::Black);
}

void ActionBoard::initMoveButton()
{
	m_buttonMove = new Button(sf::Vector2f(600,1000),sf::Vector2f(50,50),"Move",m_font,sf::Color::Black,0,sf::Color::Yellow,25);
}

void ActionBoard::initTreatButton()
{
	m_buttonTreat = new Button(sf::Vector2f(750, 1000), sf::Vector2f(50,50), "Treat", m_font, sf::Color::Black, 0, sf::Color::Yellow, 25);
}

void ActionBoard::initCureButton()
{
	m_buttonCure = new Button(sf::Vector2f(900, 1000), sf::Vector2f(50,50), "Cure", m_font, sf::Color::Black, 0, sf::Color::Yellow, 25);
}

void ActionBoard::initBuildButton()
{
	m_buttonBuild = new Button(sf::Vector2f(1050, 1000), sf::Vector2f(50,50), "Build", m_font, sf::Color::Black, 0, sf::Color::Yellow, 25);
}

void ActionBoard::initShareButton()
{
	m_buttonShare = new Button(sf::Vector2f(1200, 1000), sf::Vector2f(50,50), "Share", m_font, sf::Color::Black, 0, sf::Color::Yellow, 25);
}

void ActionBoard::initPassButton()
{
	m_buttonPass = new Button(sf::Vector2f(1350, 1000), sf::Vector2f(50,50), "Pass", m_font, sf::Color::Black, 0, sf::Color::Yellow, 25);
}

void ActionBoard::initSpriteMove()
{
	m_spriteMove.second.loadFromFile("Res//ActionsImage//Move.png");

	m_spriteMove.first.setTexture(m_spriteMove.second);

	m_spriteMove.first.setScale(0.6, 0.6);

	m_spriteMove.first.setPosition(m_buttonMove->GetPosition().x-10, m_buttonMove->GetPosition().y + 10);
}

void ActionBoard::initSpriteTreat()
{
	m_spriteTreat.second.loadFromFile("Res//ActionsImage//Treat.png");

	m_spriteTreat.first.setTexture(m_spriteTreat.second);

	m_spriteTreat.first.setScale(0.6, 0.6);

	m_spriteTreat.first.setPosition(m_buttonTreat->GetPositionText().x-10,m_buttonTreat->GetPositionText().y+10);
}

void ActionBoard::initSpriteCure()
{
	m_spriteCure.second.loadFromFile("Res//ActionsImage//Cure.png");

	m_spriteCure.first.setTexture(m_spriteCure.second);

	m_spriteCure.first.setScale(0.6, 0.6);

	m_spriteCure.first.setPosition(m_buttonCure->GetPosition().x - 10, m_buttonCure->GetPositionText().y + 10);
}

void ActionBoard::initSpriteBuild()
{
	m_spriteBuild.second.loadFromFile("Res//ActionsImage//Build.png");

	m_spriteBuild.first.setTexture(m_spriteBuild.second);

	m_spriteBuild.first.setScale(0.6, 0.6);

	m_spriteBuild.first.setPosition(m_buttonBuild->GetPosition().x - 10, m_buttonBuild->GetPositionText().y + 10);
}

void ActionBoard::initSpritePass()
{
	m_spritePass.second.loadFromFile("Res//ActionsImage//Pass.png");

	m_spritePass.first.setTexture(m_spriteBuild.second);

	m_spritePass.first.setScale(0.6, 0.6);

	m_spritePass.first.setPosition(m_buttonPass->GetPosition().x - 10, m_buttonCure->GetPositionText().y + 10);
}

void ActionBoard::initSpriteShare()
{
	m_spriteShare.second.loadFromFile("Res//ActionsImage//Share.png");

	m_spriteShare.first.setTexture(m_spriteShare.second);

	m_spriteShare.first.setScale(0.6, 0.6);

	m_spriteShare.first.setPosition(m_buttonShare->GetPosition().x - 10, m_buttonShare->GetPosition().y + 10);
}

bool ActionBoard::IsMovePressed()
{
	return m_buttonMove->IsPressed();
}

bool ActionBoard::IsCurePressed()
{
	return m_buttonCure->IsPressed();
}

bool ActionBoard::IsTreatPressed()
{
	return m_buttonTreat->IsPressed();
}

bool ActionBoard::IsBuildPressed()
{
	return m_buttonBuild->IsPressed();
}

bool ActionBoard::IsSharePressed()
{
	return m_buttonShare->IsPressed();
}

bool ActionBoard::IsPassPressed()
{
	return m_buttonPass->IsPressed();
}

void ActionBoard::SetPassWhite()
{
	m_buttonPass->GetText().setColor(sf::Color::White);
}

void ActionBoard::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}
