#pragma once
#include"SFML/Graphics.hpp"

class StatsTeamCity
{
public:
	StatsTeamCity(const std::string& cityName, const sf::Color& color);

	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2f& position);
private:
	void initText(const std::string& string);
	void initShape(const sf::Color& color);
	void initFont();
private:
	sf::RectangleShape m_rectShape;
	sf::Text m_text;
	sf::Font m_font;
};

class StatsTeamPlayer
{
public:
	StatsTeamPlayer() = default;

	void Rend(sf::RenderTarget& target);
	void AddCity(StatsTeamCity*& statsTeamCity);
	void SetPosition(const sf::Vector2f& position);
private:
	std::vector<StatsTeamCity*> m_statsTeamCities;
	sf::Vector2f m_position;
};

class TeamInfo
{
public:
	TeamInfo();

	void Render(sf::RenderTarget& target);
	void Update();

	void AddPlayer(StatsTeamPlayer*& player);
private:
	void initText();
	void initFont();
	void initBlackBox();

	bool IsMouseOnBlackBox();

	void UpdateTextColor();
private:
	sf::RectangleShape m_blackBox;
	sf::Text m_text;
	sf::Font m_font;

	std::vector<StatsTeamPlayer*> m_players;
};