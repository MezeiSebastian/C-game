#pragma once

#include"SFML/Graphics.hpp"

#include"BoardCity.h"
#include"ActionBoard.h"
#include"StatsTableBoard.h"
#include"TurnStateGraphic.h"
#include"StatsInfectionRate.h"

#include"Pawn.h"
#include"CityCard.h"
#include"EventCard.h"
#include"TeamInfo.h"
#include"Build.h"
#include"DrawLoseClass.h"

#include<string>
#include<vector>
#include<unordered_map>
#include<functional>
#include<deque>

struct drawCity {
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Color color;
};

class GamePlayGraphics
{
public:
	GamePlayGraphics(sf::RenderWindow& window,std::vector<BoardCity>& boardCities,ActionBoard& actionBoard,StatsTableBoard& statsTableBoard,StatsInfectionRate& statsInfectionRate);

	void rend();
	void update();
private:
	std::map<std::string, drawCity> m_infectionCards;
	sf::RenderWindow& m_window;

	std::vector<std::string> m_citiesName;
	std::vector<std::pair<std::string, drawCity>> m_toRandInfectionCards;

	std::vector<Card*> m_toRandCityCardsCurrentPlayer;
	std::vector<Card*> m_toRandCityCardsPlayer2;
	std::vector<Card*> m_toRandCityCardsPlayer3;
	std::vector<Card*> m_toRandCityCardsPlayer4;

	std::vector<bool> m_IsInfected;

	std::pair<sf::Sprite,sf::Texture> m_arrow;
	//std::vector<class line> m_lines;
	std::pair<sf::Sprite, sf::Texture> m_yellowSquare;
	std::pair<sf::Sprite, sf::Texture> m_blueSquare;
	std::pair<sf::Sprite, sf::Texture> m_blackSquare;
	std::pair<sf::Sprite, sf::Texture> m_redSquare;
	
	std::vector<BoardCity>& m_boardCities;
	
	std::vector<BoardCity> m_toMoveCities;

	std::unordered_map<std::string,BoardCity*> m_mapCities;

	bool itCureInCity;

	ActionBoard& m_actionBoard;
	StatsTableBoard& m_statsTableBoard;

	std::map<std::string,Card*> m_Cards;
	//std::map<std::string, EventCard*> m_eventCards;

	std::vector<std::string> m_eventNames;
	StatsInfectionRate& m_statsInfectionRate;

	int numberOfDraw;

	bool changefirstTurn;

	Pawn* m_pawn1;
	Pawn* m_pawn2;

	std::vector<Card*> deckCityEventAndEpidemicCard;
	std::vector<std::pair<std::string,drawCity>> deckInfectionCard;
	std::vector<std::pair<std::string,drawCity>> residualInfectionCard;
	
	Pawn* m_currentPlayer;

	TurnStateGraphic* m_turnStateGraphic;

	TeamInfo m_teamInfo;

	sf::Clock m_clock;

	std::vector<int> m_choosedInfectionCards;
	std::vector<int> m_choosedCityAndEventCards;

	StatsTeamPlayer* m_statsTeamPlayer1;
	StatsTeamPlayer* m_statsTeamPlayer2;

	std::vector<int> m_choosedCards;

	std::map<std::string,StatsTeamCity*> m_statsTeamCity;

	DrawLoseClass m_drawLoseClass;

	bool firstDraw;

	int m_numberResearchStation = 0;

	bool firstPhase;

	bool drawEpidemicCard;

	int Have5CardsWithSameColor(Pawn*& player);

	int numberOfTurns;

	bool m_isSharePressed;

	bool haveMoreThan7=false;

	bool IsMovePressed = false;

	bool m_curedYellowVirus = 0;
	bool m_curedRedVirus = 0;
	bool m_curedBlueVirus = 0;
	bool m_curedBlackVirus = 0;

private:

	void ChooseRandomInfectionCards(int numberCards,bool lastCard=false);
	void initInfectionCards();
	void initArrow();
	void initDeckCityEventCard();
	void addEpidemicCardInDeck();
	void IsSharePressed();

	void initBlackSquare();
	void initBlueSquare();
	void initRedSquare();
	void initYellowSquare();
	void InitMapWithCities();
	void InitPawn();
	void InitStatsTeamCity();
	void InitTurnStateGraphic();
	void initCityConnections();

	void InitCityCards();
	void InitEventCards();
	void InitEpidemicCards();

	void UpdateInfectionRate();
	void EraseCardsFromCurrentPlayer(const sf::Color& color);

	void UpdateCureButton();
	void UpdateShareButton();
	void ShareRandomCardsForPlayers(Pawn*& pawn,int numberCards);
	void DropCardsToSeven();

	const std::string& GetCityEventString(Card*& card);
	sf::Clock* m_dropCardsTimer;
private:
	void UpdateChosenInfectionCards();
	void UpdateSharedCityCardsAndEvents();
	void UpdateViruses();
	void UpdateMovePawn();
	void UpdatePawn();
	void UpdateCurrentPlayer();
	void UpdateTreatButton();
	void MovePawn();
	void UpdateBuildButton();
	void UpdatePassButton();

	void UpdateChooseRandomInfectionCards();
private:
	void RendChosenInfectionCards();
	void RendViruses();
	void RendPawn();
	void RendStatsTableTurn();
	void RendCityCards();
};