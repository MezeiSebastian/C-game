#pragma once
#include"SFML/Graphics.hpp"

#include"Build.h"

#include<vector>

class BoardCity
{
public:
	BoardCity() = default;
	BoardCity(sf::Sprite& circle, sf::Text& text,sf::Color colorCity);
	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2i& pos);
	void Update(sf::RenderWindow& window);
	const sf::Text& GetText() const;

	const sf::Vector2f& GetPosition() const;
	const sf::Vector2f& GetCenterShape() const;
	const sf::Color& GetColor() const;

	bool IsMouseOnCity();
	bool IsCityPressed();

	void SetNormalColor();

	const sf::Color& GetColorCity();

	void AddYellowVirus();
	void AddBlackVirus();
	void AddRedVirus();
	void AddBlueVirus();

	void EliminateVirus();

	const std::string& GetLastVirusColor();

	int GetNumberOfVirus();
	int getNumberOfYellowVirus();
	int getNumberOfRedVirus();
	int getNumberOfBlueVirus();
	int getNumberOfBlackVirus();

	void setAvailable();

	void AddBuild();

	bool HaveResearchStation();

	void AddPlayersInPosition(const sf::Vector2f& position);
	const sf::Vector2f& GetLastPositionFromPlayers();

	void AddNeighbourCity(const std::string& cityName, BoardCity*& city);
	std::map<std::string, BoardCity*>& getNeighborCities();
private:

	sf::Sprite m_circle;
	sf::Text m_text;

	sf::Color normalColor;
	sf::Color hoverColor;

	sf::Color m_ColorCity;

	std::pair<Build*,bool> m_build;

	std::vector<std::pair<std::string,sf::RectangleShape>> m_Virus;

	std::map<std::string, BoardCity*> m_neighbouringCities;

	//std::vector<sf::RectangleShape> m_yellowVirus;
	//std::vector<sf::RectangleShape> m_blackVirus;
	//std::vector<sf::RectangleShape> m_redVirus;
	//std::vector<sf::RectangleShape> m_blueVirus;

	sf::RectangleShape m_yellowVirus;
	sf::RectangleShape m_blackVirus;
	sf::RectangleShape m_redVirus;
	sf::RectangleShape m_blueVirus;

	int m_numberYellowVirus;
	int m_numberBlackVirus;
	int m_numberRedVirus;
	int m_numberBlueVirus;

	std::vector<sf::Vector2f> m_PositionFromPlayers;
};
