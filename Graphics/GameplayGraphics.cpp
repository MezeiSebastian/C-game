#include "GameplayGraphics.h"

#include<Windows.h>

#include<time.h>
#include<algorithm>
#include<iostream>
#include<random>
#include<queue>
#include<functional>

const int firstInfectionCardsSize = 4;

GamePlayGraphics::GamePlayGraphics(sf::RenderWindow& window, std::vector<BoardCity>& boardCities, ActionBoard& actionBoard, StatsTableBoard& statsTableBoard,StatsInfectionRate& statsInfectionRate) :
	m_window(window),
	m_boardCities(boardCities),
	m_actionBoard(actionBoard),
	m_statsTableBoard(statsTableBoard),
	m_statsInfectionRate(statsInfectionRate)
{

	changefirstTurn = false;

	firstDraw = true;

	numberOfTurns = 0;

	drawEpidemicCard = false;

	firstPhase = false;

	numberOfDraw = 0;

	m_isSharePressed = false;

	initInfectionCards();
	InitCityCards();
	InitEventCards();
	InitEpidemicCards();
	initDeckCityEventCard();
	ChooseRandomInfectionCards(9);
	initArrow();
	initBlackSquare();
	InitMapWithCities();
	InitStatsTeamCity();
	InitEpidemicCards();

	itCureInCity = false;

	m_pawn1 = nullptr;
	m_pawn2 = nullptr;
	m_turnStateGraphic = nullptr;

	/*firstPhase = false;*/
}


void GamePlayGraphics::rend()
{
	RendCityCards();
	RendChosenInfectionCards();
	RendViruses();

	/*m_drawLoseClass.Rend(m_window);*/

	if (m_toRandCityCardsCurrentPlayer.size()==0 &&  m_toRandInfectionCards.size() == 0)
	{
		RendPawn();

		m_actionBoard.render(m_window);

		RendStatsTableTurn();

		m_teamInfo.Render(m_window);
	}
}

void GamePlayGraphics::update()
{
	if (!haveMoreThan7)
		m_actionBoard.update(m_window);

	else m_actionBoard.SetPassWhite();

	UpdateSharedCityCardsAndEvents();
	UpdateChosenInfectionCards();
	UpdateViruses();

	if (m_toRandCityCardsCurrentPlayer.size()==0 && m_toRandInfectionCards.size() == 0 && m_pawn1 == nullptr)
	{
		InitPawn();
		InitTurnStateGraphic();
	}

	if (!haveMoreThan7 && m_toRandCityCardsCurrentPlayer.size()==0 && m_toRandInfectionCards.size() == 0)
	{
		UpdateMovePawn();
		UpdateTreatButton();
		m_teamInfo.Update();
		UpdateBuildButton();
		UpdateCureButton();
		IsSharePressed();
		UpdateShareButton();
		UpdatePassButton();
	}

	DropCardsToSeven();

	//if (m_currentPlayer!=nullptr && m_currentPlayer->GetCards().size() < 7)
	//	haveMoreThan7 = false;

	UpdateInfectionRate();
	UpdateChooseRandomInfectionCards();

	if (m_turnStateGraphic != nullptr)
	{
		m_turnStateGraphic->Update();
		UpdateCurrentPlayer();
	}


	if (numberOfTurns == 2)
		addEpidemicCardInDeck();
}

int GamePlayGraphics::Have5CardsWithSameColor(Pawn*& player)
{
	int yellowNumber = 0;
	int redNumber = 0;
	int blackNumber = 0;
	int blueNumber = 0;

	for (int index = 0; index < player->GetNumberOfCards(); index++)
	{
		for (auto& it : m_Cards)
		{
			if (it.second == player->GetCards()[index])
			{
				if (!it.second->IsEpidemicCard() && !it.second->IsEventCard())
				{
					if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Yellow)
					{
						yellowNumber++;
					}

					else if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Red)
					{
						redNumber++;
					}

					else if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Black)
					{
						blackNumber++;
					}

					else if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Blue)
					{
						blueNumber++;
					}
				}
			}
		}
	}

	if (yellowNumber >= 5)
		return 1;
	else if (redNumber >= 5)
		return 2;
	else if (blueNumber >= 5)
		return 3;
	else if (blackNumber >= 5)
		return 4;
	else return -1;
}

void GamePlayGraphics::ChooseRandomInfectionCards(int numberCards,bool lastCard)
{
	std::srand(time(NULL));

	for (int index = 0; index < numberCards; index++)
	{
		m_IsInfected.push_back(false);

		if (lastCard)
		{
			m_toRandInfectionCards.push_back(deckInfectionCard[0]);

			residualInfectionCard.push_back(deckInfectionCard[0]);

			deckInfectionCard.erase(deckInfectionCard.begin());
		}

		else
		{
			m_toRandInfectionCards.push_back(deckInfectionCard.back());

			residualInfectionCard.push_back(deckInfectionCard.back());

			deckInfectionCard.erase(deckInfectionCard.begin() + deckInfectionCard.size()-1);
		}
	}
}

void GamePlayGraphics::initInfectionCards()
{
	sf::Sprite sprite;
	sf::Texture texture;

	std::vector<std::string> cityNames;
	cityNames.push_back("Alger");
	cityNames.push_back("Atlanta");
	cityNames.push_back("Bagdad");
	cityNames.push_back("Bangkok");
	cityNames.push_back("Beijing");
	cityNames.push_back("Bogota");
	cityNames.push_back("Buenos Aires");
	cityNames.push_back("Cairo");
	cityNames.push_back("Chennai");
	cityNames.push_back("Chicago");
	cityNames.push_back("Delhi");
	cityNames.push_back("Essen");
	cityNames.push_back("Ho Chi Minh City");
	cityNames.push_back("Hong Kong");
	cityNames.push_back("Istanbul");
	cityNames.push_back("Jakarta");
	cityNames.push_back("Johannesburg");
	cityNames.push_back("Karachi");
	cityNames.push_back("Khartoum");
	cityNames.push_back("Kinshasa");
	cityNames.push_back("Kolkata");
	cityNames.push_back("Lagos");
	cityNames.push_back("Lima");
	cityNames.push_back("London");
	cityNames.push_back("Los Angeles");
	cityNames.push_back("Madrid");
	cityNames.push_back("Manila");
	cityNames.push_back("Mexico City");
	cityNames.push_back("Miami");
	cityNames.push_back("Milan");
	cityNames.push_back("Montreal");
	cityNames.push_back("Moscow");
	cityNames.push_back("Mumbai");
	cityNames.push_back("New York");
	cityNames.push_back("Osaka");
	cityNames.push_back("Paris");
	cityNames.push_back("Riyadh");
	cityNames.push_back("San Francisco");
	cityNames.push_back("Santiago");
	cityNames.push_back("Sao Paulo");
	cityNames.push_back("Seoul");
	cityNames.push_back("Shanghai");
	cityNames.push_back("St. Petersburg");
	cityNames.push_back("Sydney");
	cityNames.push_back("Taipei");
	cityNames.push_back("Tehran");
	cityNames.push_back("Tokyo");
	cityNames.push_back("Washington");

	std::vector<std::string> imagePaths;
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//37-Alger.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//25-Atlanta.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//38-Bagdad.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//13-Bankok.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//14-Beijing.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//01-Bogota.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//02-BuenosAires.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//39-Cairo.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//40-Chennai.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//26-Chicago.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//41-Delhi.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//27-Essen.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//15-HoChiMinhCity.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//16-HongKong.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//42-Instanbul.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//17-Jakarta.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//03-Johannesburg.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//43-Karachi.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//04-Khartoum.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//05-Kinshasa.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//44-Kolkata.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//06-Lagos.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//07-Lima.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//28-London.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//08-LosAngeles.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//29-Madrid.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//18-Manila.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//09-MexicoCity.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//10-Miami.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//30-Milan.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//31-Montreal.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//45-Moscow.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//46-Mumbai.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//32-NewYork.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//19-Osaka.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//33-Paris.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//47-Riyadh.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//34-SanFrancisco.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//11-Santiago.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//12-SaoPaulo.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//20-Seoul.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//21-Shanghai.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//35-St.Petersburg.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//22-Sydney.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//23-Taipei.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//48-Tehran.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//24-Tokyo.png");
	imagePaths.push_back("Res//Cards_Pandemic//infection cards//36-Washington.png");

	for (int index = 0; index < cityNames.size(); index++)
	{
		for (int chr = 0; chr < cityNames[index].length(); chr++)
			if(chr!=' ' && chr!='.')
			cityNames[index][chr] = toupper(cityNames[index][chr]);


		m_infectionCards[cityNames[index]].texture.loadFromFile(imagePaths[index]);
		m_infectionCards[cityNames[index]].sprite.setTexture(m_infectionCards[cityNames[index]].texture);
		m_infectionCards[cityNames[index]].sprite.setPosition(sf::Vector2f(0, 100));
		m_infectionCards[cityNames[index]].sprite.setScale(sf::Vector2f(0.0001, 0.0001));

		int colorCode = (imagePaths[index][38] - '0') * 10 + (imagePaths[index][39] - '0');
		std::cout << colorCode << "\n";

		if (colorCode <= 12)
			m_infectionCards[cityNames[index]].color = sf::Color::Yellow;
		else
			if (colorCode <= 24)
				m_infectionCards[cityNames[index]].color = sf::Color::Red;
			else
				if (colorCode <= 36)
					m_infectionCards[cityNames[index]].color = sf::Color::Blue;
				else
					if (colorCode <= 48)
						m_infectionCards[cityNames[index]].color =sf::Color::Black;
					else
						m_infectionCards[cityNames[index]].color = sf::Color::White;

		m_citiesName.push_back(cityNames[index]);

		deckInfectionCard.push_back(std::make_pair(cityNames[index], m_infectionCards[cityNames[index]]));
	}

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deckInfectionCard.begin(),deckInfectionCard.end(), g);
}

void GamePlayGraphics::initArrow()
{
	m_arrow.second.loadFromFile("Res//Arrow//Arrow5.png");
	m_arrow.first.setTexture(m_arrow.second);
	m_arrow.first.setPosition(sf::Vector2f(100, 100));
	m_arrow.first.setScale(0.5, 0.5);
	m_arrow.first.setOrigin(sf::Vector2f(128,256));
}

void GamePlayGraphics::initDeckCityEventCard()
{
	for (auto& it : m_Cards)
		if(!it.second->IsEpidemicCard())
		deckCityEventAndEpidemicCard.push_back(it.second);

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deckCityEventAndEpidemicCard.begin(), deckCityEventAndEpidemicCard.end(),g);
}

void GamePlayGraphics::addEpidemicCardInDeck()
{
	//std::vector<Card*> deck1;
	//std::vector<Card*> deck2;
	//std::vector<Card*> deck3;
	//std::vector<Card*> deck4;
	//std::vector<Card*> deck5;
	//std::vector<Card*> deck6;

	//int index = 0;
	//for(auto& it:m_Cards)
	//	if (index < 8)
	//	{
	//		if (!it.second->IsEpidemicCard())
	//			deck1.push_back(it);
	//	}

	int index = 8;

	for (auto& it : m_Cards)
	{
		if (it.second->IsEpidemicCard())
		{
			deckCityEventAndEpidemicCard.insert(deckCityEventAndEpidemicCard.begin() + index, it.second);
			index += 8;

		}
	}

	//std::random_device rd;
	//std::mt19937 g(rd());

	//std::shuffle(deckInfectionCard.begin(), deckInfectionCard.end(), g);


}

void GamePlayGraphics::IsSharePressed()
{
	if (m_actionBoard.IsSharePressed())
		m_isSharePressed = true;
}

void GamePlayGraphics::initBlackSquare()
{
	m_blackSquare.second.loadFromFile("Res//Square//BlackSquare.png");
	m_blackSquare.first.setTexture(m_blackSquare.second);
	m_blackSquare.first.setScale(0.05,0.05);
	m_blackSquare.first.setPosition(sf::Vector2f(0, 0));
}


void GamePlayGraphics::InitMapWithCities()
{
	std::sort(m_boardCities.begin(), m_boardCities.end(), [](const BoardCity& first, const BoardCity& second) ->bool {return first.GetText().getString() < second.GetText().getString(); });
	for (int index = 0; index < m_boardCities.size(); index++)
		m_mapCities[m_citiesName[index]]= &m_boardCities[index];

	m_mapCities["ALGER"]->AddNeighbourCity("CAIRO", m_mapCities["CAIRO"]);
	m_mapCities["ALGER"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["ALGER"]->AddNeighbourCity("PARIS", m_mapCities["PARIS"]);
	m_mapCities["ALGER"]->AddNeighbourCity("MADRID", m_mapCities["MADRID"]);

	m_mapCities["ATLANTA"]->AddNeighbourCity("CHICAGO", m_mapCities["CHICAGO"]);
	m_mapCities["ATLANTA"]->AddNeighbourCity("MIAMI", m_mapCities["MIAMI"]);
	m_mapCities["ATLANTA"]->AddNeighbourCity("WASHINGTON", m_mapCities["WASHINGTON"]);

	m_mapCities["BAGDAD"]->AddNeighbourCity("CAIRO", m_mapCities["CAIRO"]);
	m_mapCities["BAGDAD"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["BAGDAD"]->AddNeighbourCity("KARACHI", m_mapCities["KARACHI"]);
	m_mapCities["BAGDAD"]->AddNeighbourCity("RIYADH", m_mapCities["RIYADH"]);
	m_mapCities["BAGDAD"]->AddNeighbourCity("TEHRAN", m_mapCities["TEHRAN"]);

	m_mapCities["BANGKOK"]->AddNeighbourCity("CHENNAI", m_mapCities["CHENNAI"]);
	m_mapCities["BANGKOK"]->AddNeighbourCity("KOLKATA", m_mapCities["KOLKATA"]);
	m_mapCities["BANGKOK"]->AddNeighbourCity("HO CHI MINH CITY", m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["BANGKOK"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);
	m_mapCities["BANGKOK"]->AddNeighbourCity("JAKARTA", m_mapCities["JAKARTA"]);

	m_mapCities["BEIJING"]->AddNeighbourCity("SEOUL", m_mapCities["SEOUL"]);
	m_mapCities["BEIJING"]->AddNeighbourCity("SHANGHAI", m_mapCities["SHANGHAI"]);

	m_mapCities["BOGOTA"]->AddNeighbourCity("BUENOS AIRES", m_mapCities["BUENOS AIRES"]);
	m_mapCities["BOGOTA"]->AddNeighbourCity("LIMA", m_mapCities["LIMA"]);
	m_mapCities["BOGOTA"]->AddNeighbourCity("MEXICO CITY", m_mapCities["MEXICO CITY"]);
	m_mapCities["BOGOTA"]->AddNeighbourCity("MIAMI", m_mapCities["MIAMI"]);
	m_mapCities["BOGOTA"]->AddNeighbourCity("SAO PAULO", m_mapCities["SAO PAULO"]);

	m_mapCities["BUENOS AIRES"]->AddNeighbourCity("BOGOTA", m_mapCities["BOGOTA"]);
	m_mapCities["BUENOS AIRES"]->AddNeighbourCity("SAO PAULO", m_mapCities["SAO PAULO"]);

	m_mapCities["CAIRO"]->AddNeighbourCity("ALGER", m_mapCities["ALGER"]);
	m_mapCities["CAIRO"]->AddNeighbourCity("BAGDAD", m_mapCities["BAGDAD"]);
	m_mapCities["CAIRO"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["CAIRO"]->AddNeighbourCity("KHARTOUM", m_mapCities["KHARTOUM"]);
	m_mapCities["CAIRO"]->AddNeighbourCity("RIYADH", m_mapCities["RIYADH"]);

	m_mapCities["CHENNAI"]->AddNeighbourCity("BANGKOK", m_mapCities["BANGKOK"]);
	m_mapCities["CHENNAI"]->AddNeighbourCity("DELHI", m_mapCities["DELHI"]);
	m_mapCities["CHENNAI"]->AddNeighbourCity("JAKARTA", m_mapCities["JAKARTA"]);
	m_mapCities["CHENNAI"]->AddNeighbourCity("KOLKATA", m_mapCities["KOLKATA"]);
	m_mapCities["CHENNAI"]->AddNeighbourCity("MUMBAI", m_mapCities["MUMBAI"]);

	m_mapCities["CHICAGO"]->AddNeighbourCity("ATLANTA", m_mapCities["ATLANTA"]);
	m_mapCities["CHICAGO"]->AddNeighbourCity("LOS ANGELES", m_mapCities["LOS ANGELES"]);
	m_mapCities["CHICAGO"]->AddNeighbourCity("MEXICO CITY", m_mapCities["MEXICO CITY"]);
	m_mapCities["CHICAGO"]->AddNeighbourCity("MONTREAL", m_mapCities["MONTREAL"]);
	m_mapCities["CHICAGO"]->AddNeighbourCity("SAN FRANCISCO", m_mapCities["SAN FRANCISCO"]);

	m_mapCities["DELHI"]->AddNeighbourCity("CHENNAI", m_mapCities["CHENNAI"]);
	m_mapCities["DELHI"]->AddNeighbourCity("KARACHI", m_mapCities["KARACHI"]);
	m_mapCities["DELHI"]->AddNeighbourCity("KOLKATA", m_mapCities["KOLKATA"]);
	m_mapCities["DELHI"]->AddNeighbourCity("MUMBAI", m_mapCities["MUMBAI"]);
	m_mapCities["DELHI"]->AddNeighbourCity("TEHRAN", m_mapCities["TEHRAN"]);

	m_mapCities["ESSEN"]->AddNeighbourCity("LONDON", m_mapCities["LONDON"]);
	m_mapCities["ESSEN"]->AddNeighbourCity("MILAN", m_mapCities["MILAN"]);
	m_mapCities["ESSEN"]->AddNeighbourCity("PARIS", m_mapCities["PARIS"]);
	m_mapCities["ESSEN"]->AddNeighbourCity("ST. PETERSBURG", m_mapCities["ST. PETERSBURG"]);

	m_mapCities["HO CHI MINH CITY"]->AddNeighbourCity("BANGKOK", m_mapCities["BANGKOK"]);
	m_mapCities["HO CHI MINH CITY"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);
	m_mapCities["HO CHI MINH CITY"]->AddNeighbourCity("JAKARTA", m_mapCities["JAKARTA"]);
	m_mapCities["HO CHI MINH CITY"]->AddNeighbourCity("MANILA", m_mapCities["MANILA"]);

	m_mapCities["HONG KONG"]->AddNeighbourCity("BANGKOK", m_mapCities["BANGKOK"]);
	m_mapCities["HONG KONG"]->AddNeighbourCity("HO CHI MINH CITY", m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["HONG KONG"]->AddNeighbourCity("KOLKATA", m_mapCities["KOLKATA"]);
	m_mapCities["HONG KONG"]->AddNeighbourCity("MANILA", m_mapCities["MANILA"]);
	m_mapCities["HONG KONG"]->AddNeighbourCity("SHANGHAI", m_mapCities["SHANGHAI"]);
	m_mapCities["HONG KONG"]->AddNeighbourCity("TAIPEI", m_mapCities["TAIPEI"]);

	m_mapCities["ISTANBUL"]->AddNeighbourCity("ALGER", m_mapCities["ALGER"]);
	m_mapCities["ISTANBUL"]->AddNeighbourCity("BAGDAD", m_mapCities["BAGDAD"]);
	m_mapCities["ISTANBUL"]->AddNeighbourCity("CAIRO", m_mapCities["CAIRO"]);
	m_mapCities["ISTANBUL"]->AddNeighbourCity("MILAN", m_mapCities["MILAN"]);
	m_mapCities["ISTANBUL"]->AddNeighbourCity("MOSCOW", m_mapCities["MOSCOW"]);
	m_mapCities["ISTANBUL"]->AddNeighbourCity("ST. PETERSBURG", m_mapCities["ST. PETERSBURG"]);

	m_mapCities["JAKARTA"]->AddNeighbourCity("BANGKOK", m_mapCities["BANGKOK"]);
	m_mapCities["JAKARTA"]->AddNeighbourCity("CHENNAI", m_mapCities["CHENNAI"]);
	m_mapCities["JAKARTA"]->AddNeighbourCity("HO CHI MINH CITY", m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["JAKARTA"]->AddNeighbourCity("SYDNEY", m_mapCities["SYDNEY"]);

	m_mapCities["JOHANNESBURG"]->AddNeighbourCity("KHARTOUM", m_mapCities["KHARTOUM"]);
	m_mapCities["JOHANNESBURG"]->AddNeighbourCity("KINSHASA", m_mapCities["KINSHASA"]);

	m_mapCities["KARACHI"]->AddNeighbourCity("BAGDAD", m_mapCities["BAGDAD"]);
	m_mapCities["KARACHI"]->AddNeighbourCity("DELHI", m_mapCities["DELHI"]);
	m_mapCities["KARACHI"]->AddNeighbourCity("MUMBAI", m_mapCities["MUMBAI"]);
	m_mapCities["KARACHI"]->AddNeighbourCity("RIYADH", m_mapCities["RIYADH"]);
	m_mapCities["KARACHI"]->AddNeighbourCity("TEHRAN", m_mapCities["TEHRAN"]);

	m_mapCities["KHARTOUM"]->AddNeighbourCity("CAIRO", m_mapCities["CAIRO"]);
	m_mapCities["KHARTOUM"]->AddNeighbourCity("KINSHASA", m_mapCities["KINSHASA"]);
	m_mapCities["KHARTOUM"]->AddNeighbourCity("JOHANNESBURG", m_mapCities["JOHANNESBURG"]);
	m_mapCities["KHARTOUM"]->AddNeighbourCity("LAGOS", m_mapCities["LAGOS"]);

	m_mapCities["KINSHASA"]->AddNeighbourCity("JOHANNESBURG", m_mapCities["JOHANNESBURG"]);
	m_mapCities["KINSHASA"]->AddNeighbourCity("KHARTOUM", m_mapCities["KHARTOUM"]);
	m_mapCities["KINSHASA"]->AddNeighbourCity("LAGOS", m_mapCities["LAGOS"]);

	m_mapCities["KOLKATA"]->AddNeighbourCity("BANGKOK", m_mapCities["BANGKOK"]);
	m_mapCities["KOLKATA"]->AddNeighbourCity("CHENNAI", m_mapCities["CHENNAI"]);
	m_mapCities["KOLKATA"]->AddNeighbourCity("DELHI", m_mapCities["DELHI"]);
	m_mapCities["KOLKATA"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);

	m_mapCities["LAGOS"]->AddNeighbourCity("KHARTOUM", m_mapCities["KHARTOUM"]);
	m_mapCities["LAGOS"]->AddNeighbourCity("KINSHASA", m_mapCities["KINSHASA"]);
	m_mapCities["LAGOS"]->AddNeighbourCity("SAO PAULO", m_mapCities["SAO PAULO"]);

	m_mapCities["LIMA"]->AddNeighbourCity("BOGOTA", m_mapCities["BOGOTA"]);
	m_mapCities["LIMA"]->AddNeighbourCity("MEXICO CITY", m_mapCities["MEXICO CITY"]);
	m_mapCities["LIMA"]->AddNeighbourCity("SANTIAGO", m_mapCities["SANTIAGO"]);

	m_mapCities["LONDON"]->AddNeighbourCity("ESSEN", m_mapCities["ESSEN"]);
	m_mapCities["LONDON"]->AddNeighbourCity("MADRID", m_mapCities["MADRID"]);
	m_mapCities["LONDON"]->AddNeighbourCity("NEW YORK", m_mapCities["NEW YORK"]);
	m_mapCities["LONDON"]->AddNeighbourCity("PARIS", m_mapCities["PARIS"]);

	m_mapCities["LOS ANGELES"]->AddNeighbourCity("MEXICO CITY", m_mapCities["MEXICO CITY"]);
	m_mapCities["LOS ANGELES"]->AddNeighbourCity("SAN FRANCISCO", m_mapCities["SAN FRANCISCO"]);
	m_mapCities["LOS ANGELES"]->AddNeighbourCity("SYDNEY", m_mapCities["SYDNEY"]);

	m_mapCities["MADRID"]->AddNeighbourCity("ALGER", m_mapCities["ALGER"]);
	m_mapCities["MADRID"]->AddNeighbourCity("LONDON", m_mapCities["LONDON"]);
	m_mapCities["MADRID"]->AddNeighbourCity("NEW YORK", m_mapCities["NEW YORK"]);
	m_mapCities["MADRID"]->AddNeighbourCity("PARIS", m_mapCities["PARIS"]);
	m_mapCities["MADRID"]->AddNeighbourCity("SAO PAULO", m_mapCities["SAO PAULO"]);

	m_mapCities["MANILA"]->AddNeighbourCity("HO CHI MINH CITY", m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["MANILA"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);
	m_mapCities["MANILA"]->AddNeighbourCity("SAN FRANCISCO", m_mapCities["SAN FRANCISCO"]);
	m_mapCities["MANILA"]->AddNeighbourCity("SYDNEY", m_mapCities["SYDNEY"]);
	m_mapCities["MANILA"]->AddNeighbourCity("TAIPEI", m_mapCities["TAIPEI"]);

	m_mapCities["MEXICO CITY"]->AddNeighbourCity("BOGOTA", m_mapCities["BOGOTA"]);
	m_mapCities["MEXICO CITY"]->AddNeighbourCity("CHICAGO", m_mapCities["CHICAGO"]);
	m_mapCities["MEXICO CITY"]->AddNeighbourCity("LIMA", m_mapCities["LIMA"]);
	m_mapCities["MEXICO CITY"]->AddNeighbourCity("LOS ANGELES", m_mapCities["LOS ANGELES"]);
	m_mapCities["MEXICO CITY"]->AddNeighbourCity("MIAMI", m_mapCities["MIAMI"]);

	m_mapCities["MIAMI"]->AddNeighbourCity("ATLANTA", m_mapCities["ATLANTA"]);
	m_mapCities["MIAMI"]->AddNeighbourCity("BOGOTA", m_mapCities["BOGOTA"]);
	m_mapCities["MIAMI"]->AddNeighbourCity("MEXICO CITY", m_mapCities["MEXICO CITY"]);
	m_mapCities["MIAMI"]->AddNeighbourCity("WASHINGTON", m_mapCities["WASHINGTON"]);

	m_mapCities["MILAN"]->AddNeighbourCity("ESSEN", m_mapCities["ESSEN"]);
	m_mapCities["MILAN"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["MILAN"]->AddNeighbourCity("PARIS", m_mapCities["PARIS"]);

	m_mapCities["MONTREAL"]->AddNeighbourCity("CHICAGO", m_mapCities["CHICAGO"]);
	m_mapCities["MONTREAL"]->AddNeighbourCity("NEW YORK", m_mapCities["NEW YORK"]);
	m_mapCities["MONTREAL"]->AddNeighbourCity("WASHINGTON", m_mapCities["WASHINGTON"]);

	m_mapCities["MOSCOW"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["MOSCOW"]->AddNeighbourCity("ST. PETERSBURG", m_mapCities["ST. PETERSBURG"]);
	m_mapCities["MOSCOW"]->AddNeighbourCity("TEHRAN", m_mapCities["TEHRAN"]);

	m_mapCities["MUMBAI"]->AddNeighbourCity("DELHI", m_mapCities["DELHI"]);
	m_mapCities["MUMBAI"]->AddNeighbourCity("CHENNAI", m_mapCities["CHENNAI"]);
	m_mapCities["MUMBAI"]->AddNeighbourCity("KARACHI", m_mapCities["KARACHI"]);

	m_mapCities["NEW YORK"]->AddNeighbourCity("LONDON", m_mapCities["LONDON"]);
	m_mapCities["NEW YORK"]->AddNeighbourCity("MADRID", m_mapCities["MADRID"]);
	m_mapCities["NEW YORK"]->AddNeighbourCity("MONTREAL", m_mapCities["MONTREAL"]);
	m_mapCities["NEW YORK"]->AddNeighbourCity("WASHINGTON", m_mapCities["WASHINGTON"]);

	m_mapCities["OSAKA"]->AddNeighbourCity("TAIPEI", m_mapCities["TAIPEI"]);
	m_mapCities["OSAKA"]->AddNeighbourCity("TOKYO", m_mapCities["TOKYO"]);

	m_mapCities["PARIS"]->AddNeighbourCity("ALGER", m_mapCities["ALGER"]);
	m_mapCities["PARIS"]->AddNeighbourCity("ESSEN", m_mapCities["ESSEN"]);
	m_mapCities["PARIS"]->AddNeighbourCity("LONDON", m_mapCities["LONDON"]);
	m_mapCities["PARIS"]->AddNeighbourCity("MADRID", m_mapCities["MADRID"]);
	m_mapCities["PARIS"]->AddNeighbourCity("MILAN", m_mapCities["MILAN"]);

	m_mapCities["RIYADH"]->AddNeighbourCity("BAGDAD", m_mapCities["BAGDAD"]);
	m_mapCities["RIYADH"]->AddNeighbourCity("CAIRO", m_mapCities["CAIRO"]);
	m_mapCities["RIYADH"]->AddNeighbourCity("KARACHI", m_mapCities["KARACHI"]);

	m_mapCities["SAN FRANCISCO"]->AddNeighbourCity("CHICAGO", m_mapCities["CHICAGO"]);
	m_mapCities["SAN FRANCISCO"]->AddNeighbourCity("LOS ANGELES", m_mapCities["LOS ANGELES"]);
	m_mapCities["SAN FRANCISCO"]->AddNeighbourCity("MANILA", m_mapCities["MANILA"]);
	m_mapCities["SAN FRANCISCO"]->AddNeighbourCity("TOKYO", m_mapCities["TOKYO"]);

	m_mapCities["SANTIAGO"]->AddNeighbourCity("LIMA", m_mapCities["LIMA"]);

	m_mapCities["SAO PAULO"]->AddNeighbourCity("BOGOTA", m_mapCities["BOGOTA"]);
	m_mapCities["SAO PAULO"]->AddNeighbourCity("BUENOS AIRES", m_mapCities["BUENOS AIRES"]);
	m_mapCities["SAO PAULO"]->AddNeighbourCity("LAGOS", m_mapCities["LAGOS"]);
	m_mapCities["SAO PAULO"]->AddNeighbourCity("MADRID", m_mapCities["MADRID"]);

	m_mapCities["SEOUL"]->AddNeighbourCity("BEIJING", m_mapCities["BEIJING"]);
	m_mapCities["SEOUL"]->AddNeighbourCity("SHANGHAI", m_mapCities["SHANGHAI"]);
	m_mapCities["SEOUL"]->AddNeighbourCity("TOKYO", m_mapCities["TOKYO"]);

	m_mapCities["SHANGHAI"]->AddNeighbourCity("BEIJING", m_mapCities["BEIJING"]);
	m_mapCities["SHANGHAI"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);
	m_mapCities["SHANGHAI"]->AddNeighbourCity("SEOUL", m_mapCities["SEOUL"]);
	m_mapCities["SHANGHAI"]->AddNeighbourCity("TAIPEI", m_mapCities["TAIPEI"]);
	m_mapCities["SHANGHAI"]->AddNeighbourCity("TOKYO", m_mapCities["TOKYO"]);

	m_mapCities["ST. PETERSBURG"]->AddNeighbourCity("ESSEN", m_mapCities["ESSEN"]);
	m_mapCities["ST. PETERSBURG"]->AddNeighbourCity("ISTANBUL", m_mapCities["ISTANBUL"]);
	m_mapCities["ST. PETERSBURG"]->AddNeighbourCity("MOSCOW", m_mapCities["MOSCOW"]);

	m_mapCities["SYDNEY"]->AddNeighbourCity("JAKARTA", m_mapCities["JAKARTA"]);
	m_mapCities["SYDNEY"]->AddNeighbourCity("LOS ANGELES", m_mapCities["LOS ANGELES"]);
	m_mapCities["SYDNEY"]->AddNeighbourCity("MANILA", m_mapCities["MANILA"]);

	m_mapCities["TAIPEI"]->AddNeighbourCity("HONG KONG", m_mapCities["HONG KONG"]);
	m_mapCities["TAIPEI"]->AddNeighbourCity("MANILA", m_mapCities["MANILA"]);
	m_mapCities["TAIPEI"]->AddNeighbourCity("OSAKA", m_mapCities["OSAKA"]);
	m_mapCities["TAIPEI"]->AddNeighbourCity("SHANGHAI", m_mapCities["SHANGHAI"]);

	m_mapCities["TEHRAN"]->AddNeighbourCity("BAGDAD", m_mapCities["BAGDAD"]);
	m_mapCities["TEHRAN"]->AddNeighbourCity("DELHI", m_mapCities["DELHI"]);
	m_mapCities["TEHRAN"]->AddNeighbourCity("KARACHI", m_mapCities["KARACHI"]);
	m_mapCities["TEHRAN"]->AddNeighbourCity("MOSCOW", m_mapCities["MOSCOW"]);

	m_mapCities["TOKYO"]->AddNeighbourCity("OSAKA", m_mapCities["OSAKA"]);
	m_mapCities["TOKYO"]->AddNeighbourCity("SAN FRANCISCO", m_mapCities["SAN FRANCISCO"]);
	m_mapCities["TOKYO"]->AddNeighbourCity("SHANGHAI", m_mapCities["SHANGHAI"]);
	m_mapCities["TOKYO"]->AddNeighbourCity("SEOUL", m_mapCities["SEOUL"]);

	m_mapCities["WASHINGTON"]->AddNeighbourCity("ATLANTA", m_mapCities["ATLANTA"]);
	m_mapCities["WASHINGTON"]->AddNeighbourCity("MIAMI", m_mapCities["MIAMI"]);
	m_mapCities["WASHINGTON"]->AddNeighbourCity("MONTREAL", m_mapCities["MONTREAL"]);
	m_mapCities["WASHINGTON"]->AddNeighbourCity("NEW YORK", m_mapCities["NEW YORK"]);
}

void GamePlayGraphics::InitPawn()
{
	m_pawn1 = new Pawn(m_mapCities["ATLANTA"]);
	m_pawn1->Move(sf::Vector2f(m_mapCities["ATLANTA"]->GetLastPositionFromPlayers().x, m_mapCities["ATLANTA"]->GetLastPositionFromPlayers().y));
	m_mapCities["ATLANTA"]->AddPlayersInPosition(sf::Vector2f(m_mapCities["ATLANTA"]->GetPosition().x-10, m_mapCities["ATLANTA"]->GetPosition().y-30));

	m_pawn1->SetCurrentCity(m_mapCities["ATLANTA"]);

	m_mapCities["ATLANTA"]->AddBuild();

	m_statsTeamPlayer1 = new StatsTeamPlayer();

	m_teamInfo.AddPlayer(m_statsTeamPlayer1);

	m_numberResearchStation++;

	/*ShareRandomCardsForPlayers(m_pawn1,4);*/


	m_pawn2 = new Pawn(m_mapCities["ATLANTA"]);
	m_pawn2->Move(sf::Vector2f(m_mapCities["ATLANTA"]->GetLastPositionFromPlayers().x +15, m_mapCities["ATLANTA"]->GetLastPositionFromPlayers().y));

	m_pawn2->SetCurrentCity(m_mapCities["ATLANTA"]);

	m_statsTeamPlayer2 = new StatsTeamPlayer();

	m_teamInfo.AddPlayer(m_statsTeamPlayer2);

	/*ShareRandomCardsForPlayers(m_pawn2,4);*/

	m_currentPlayer = m_pawn1;

	ShareRandomCardsForPlayers(m_pawn1, 4);
	ShareRandomCardsForPlayers(m_pawn2, 4);

	m_currentPlayer->SetTurn();
}

void GamePlayGraphics::InitStatsTeamCity()
{
	m_statsTeamCity.insert(std::make_pair("ALGER", new StatsTeamCity("Alger", sf::Color::Yellow)));
}

void GamePlayGraphics::InitTurnStateGraphic()
{
	m_turnStateGraphic = new TurnStateGraphic();
}

void GamePlayGraphics::InitCityCards()
{
	m_Cards.insert(std::make_pair("HO CHI MINH CITY",new Card("Res//Cards_Pandemic//city cards//1-Ho Chi Minh City.png")));
	m_Cards.insert(std::make_pair("MADRID", new Card("Res//Cards_Pandemic//city cards//2-Madrid.png")));
	m_Cards.insert(std::make_pair("BAGDAD", new Card("Res//Cards_Pandemic//city cards//3-Bagdad.png")));
	m_Cards.insert(std::make_pair("ALGER", new Card("Res//Cards_Pandemic//city cards//4-Alger.png")));
	m_Cards.insert(std::make_pair("JOHANNESBURG", new Card("Res//Cards_Pandemic//city cards//5-Johannesburg.png")));
	m_Cards.insert(std::make_pair("CHICAGO", new Card("Res//Cards_Pandemic//city cards//6-Chicago.png")));
	m_Cards.insert(std::make_pair("ATLANTA", new Card("Res//Cards_Pandemic//city cards//7-Atlanta.png")));
	m_Cards.insert(std::make_pair("ISTANBUL", new Card("Res//Cards_Pandemic//city cards//8-Instanbul.png")));
	m_Cards.insert(std::make_pair("TOKYO", new Card("Res//Cards_Pandemic//city cards//9-Tokyo.png")));
	m_Cards.insert(std::make_pair("MIAMI", new Card("Res//Cards_Pandemic//city cards//10-Miami.png")));
	m_Cards.insert(std::make_pair("NEW YORK", new Card("Res//Cards_Pandemic//city cards//11-New York.png")));
	m_Cards.insert(std::make_pair("LOS ANGELES", new Card("Res//Cards_Pandemic//city cards//12-Los Angeles.png")));
	m_Cards.insert(std::make_pair("ESSEN", new Card("Res//Cards_Pandemic//city cards//13-Essen.png")));
	m_Cards.insert(std::make_pair("MEXICO CITY", new Card("Res//Cards_Pandemic//city cards//14-Mexico City.png")));
	m_Cards.insert(std::make_pair("KINSHASA", new Card("Res//Cards_Pandemic//city cards//15-Kinshasa.png")));
	m_Cards.insert(std::make_pair("LIMA", new Card("Res//Cards_Pandemic//city cards//16-Lima.png")));
	m_Cards.insert(std::make_pair("SANTIAGO", new Card("Res//Cards_Pandemic//city cards//17-Santiago.png")));
	m_Cards.insert(std::make_pair("BUENOS AIRES", new Card("Res//Cards_Pandemic//city cards//18-Buenos Aires.png")));
	m_Cards.insert(std::make_pair("PARIS", new Card("Res//Cards_Pandemic//city cards//19-Paris.png")));
	m_Cards.insert(std::make_pair("SAO PAULO", new Card("Res//Cards_Pandemic//city cards//20-Sao Paulo.png")));
	m_Cards.insert(std::make_pair("SAN FRANCISCO", new Card("Res//Cards_Pandemic//city cards//21-San Francisco.png")));
	m_Cards.insert(std::make_pair("BOGOTA", new Card("Res//Cards_Pandemic//city cards//22-Bogota.png")));
	m_Cards.insert(std::make_pair("KARACHI", new Card("Res//Cards_Pandemic//city cards//23-Karachi.png")));
	m_Cards.insert(std::make_pair("LAGOS", new Card("Res//Cards_Pandemic//city cards//24-Lagos.png")));
	m_Cards.insert(std::make_pair("WASHINGTON", new Card("Res//Cards_Pandemic//city cards//25-Washington.png")));
	m_Cards.insert(std::make_pair("BEIJING", new Card("Res//Cards_Pandemic//city cards//26-Beijing.png")));
	m_Cards.insert(std::make_pair("CHENNAI", new Card("Res//Cards_Pandemic//city cards//27-Chennai.png")));
	m_Cards.insert(std::make_pair("MANILA", new Card("Res//Cards_Pandemic//city cards//28-Manila.png")));
	m_Cards.insert(std::make_pair("TEHRAN", new Card("Res//Cards_Pandemic//city cards//29-Tehran.png")));
	m_Cards.insert(std::make_pair("LONDON", new Card("Res//Cards_Pandemic//city cards//30-London.png")));
	m_Cards.insert(std::make_pair("SHANGHAI", new Card("Res//Cards_Pandemic//city cards//31-Shanghai.png")));
	m_Cards.insert(std::make_pair("JAKARTA", new Card("Res//Cards_Pandemic//city cards//32-Jakarta.png")));
	m_Cards.insert(std::make_pair("DELHI", new Card("Res//Cards_Pandemic//city cards//33-Delhi.png")));
	m_Cards.insert(std::make_pair("OSAKA", new Card("Res//Cards_Pandemic//city cards//34-Osaka.png")));
	m_Cards.insert(std::make_pair("TAIPEI", new Card("Res//Cards_Pandemic//city cards//35-Taipei.png")));
	m_Cards.insert(std::make_pair("BANGKOK", new Card("Res//Cards_Pandemic//city cards//36-Bangkok.png")));
	m_Cards.insert(std::make_pair("MONTREAL", new Card("Res//Cards_Pandemic//city cards//37-Montreal.png")));
	m_Cards.insert(std::make_pair("MUMBAI", new Card("Res//Cards_Pandemic//city cards//38-Mumbai.png")));
	m_Cards.insert(std::make_pair("SYDNEY", new Card("Res//Cards_Pandemic//city cards//39-Sydney.png")));
	m_Cards.insert(std::make_pair("RIYADH", new Card("Res//Cards_Pandemic//city cards//40-Riyadh.png")));
	m_Cards.insert(std::make_pair("CAIRO", new Card("Res//Cards_Pandemic//city cards//41-Cairo.png")));
	m_Cards.insert(std::make_pair("MOSCOW", new Card("Res//Cards_Pandemic//city cards//42-Moscow.png")));
	m_Cards.insert(std::make_pair("SEOUL", new Card("Res//Cards_Pandemic//city cards//43-Seoul.png")));
	m_Cards.insert(std::make_pair("MILAN", new Card("Res//Cards_Pandemic//city cards//44-Milano.png")));
	m_Cards.insert(std::make_pair("KHARTOUM", new Card("Res//Cards_Pandemic//city cards//45-Khartoum.png")));
	m_Cards.insert(std::make_pair("KOLKATA", new Card("Res//Cards_Pandemic//city cards//46-Kolkata.png")));
	m_Cards.insert(std::make_pair("HONG KONG", new Card("Res//Cards_Pandemic//city cards//47-Hong Kong.png")));
	m_Cards.insert(std::make_pair("ST. PETERSBURG", new Card("Res//Cards_Pandemic//city cards//48-St. Petersburg.png")));
}

void GamePlayGraphics::InitEventCards()
{
	m_Cards.insert(std::make_pair("ADD", new Card("Res//Cards_Pandemic//event cards//1-Add.png",false,true)));

	m_eventNames.push_back("ADD");

	m_Cards.insert(std::make_pair("SKIP", new Card("Res//Cards_Pandemic//event cards//2-Skip.png", false,true)));

	m_eventNames.push_back("SKIP");

	m_Cards.insert(std::make_pair("MOVE", new Card("Res//Cards_Pandemic//event cards//3-Move.png",false,true)));

	m_eventNames.push_back("MOVE");

	m_Cards.insert(std::make_pair("DRAW", new Card("Res//Cards_Pandemic//event cards//4-Draw.png",false,true)));

	m_eventNames.push_back("DRAW");

	m_Cards.insert(std::make_pair("REMOVE", new Card("Res//Cards_Pandemic//event cards//5-Remove.png",false,true)));

	m_eventNames.push_back("REMOVE");
}

void GamePlayGraphics::InitEpidemicCards()
{
	Card* card;

	card = new Card("Res//Cards_Pandemic//EpidemicCard.jpg");
	card->SetIsEpidemicCard(true);
	m_Cards.insert(std::make_pair("EPIDEMIC",card));

	m_Cards.insert(std::make_pair("EPIDEMIC2", new Card("Res//Cards_Pandemic//EpidemicCard.jpg",true)));
	m_Cards.insert(std::make_pair("EPIDEMIC3", new Card("Res//Cards_Pandemic//EpidemicCard.jpg",true)));
	m_Cards.insert(std::make_pair("EPIDEMIC4", new Card("Res//Cards_Pandemic//EpidemicCard.jpg",true)));
	m_Cards.insert(std::make_pair("EPIDEMIC5", new Card("Res//Cards_Pandemic//EpidemicCard.jpg",true)));
	m_Cards.insert(std::make_pair("EPIDEMIC6", new Card("Res//Cards_Pandemic//EpidemicCard.jpg",true)));
}

void GamePlayGraphics::UpdateInfectionRate()
{
	//if (m_turnStateGraphic!=nullptr && m_turnStateGraphic->GetRemainingMovesPosible() == 0)
	//{
	//	m_statsInfectionRate.updateInfectionRate();
	//}
}

void GamePlayGraphics::EraseCardsFromCurrentPlayer(const sf::Color& color)
{

}

void GamePlayGraphics::UpdateCureButton()
{
	if (m_currentPlayer != nullptr)
	{
		int have5CardsWithSameColor = Have5CardsWithSameColor(m_currentPlayer);
		if (m_actionBoard.IsCurePressed() && have5CardsWithSameColor!=-1 && m_currentPlayer->GetCurrentCity()->HaveResearchStation())
		{
			if (have5CardsWithSameColor == 1 && m_curedYellowVirus == 0)
			{
				m_statsTableBoard.SetYellowVirusTexture("Res//YellowPotion.png");
				int index = 0;
				int cardsLeft = 5;
				for (auto& card : m_currentPlayer->GetCards())
				{
					for (auto& it : m_Cards)
					{
						if (it.second == m_currentPlayer->GetCards()[index])
						{
							if (!it.second->IsEpidemicCard() && !it.second->IsEventCard())
							{
								if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Yellow && cardsLeft > 0)
								{
									m_currentPlayer->GetCards().erase(m_currentPlayer->GetCards().begin() + index);
									cardsLeft--;
									if (index > 0)
										index--;
								}
							}
						}
					}
					if (index < m_currentPlayer->GetCards().size() - 2)
						index++;
				}

				m_currentPlayer->RearangeCards();
				m_curedYellowVirus = 1;
			}
			else if (have5CardsWithSameColor == 2 && m_curedRedVirus == 0)
			{
				m_statsTableBoard.SetRedVirusTexture("Res//RedPotion.png");
				int index = 0;
				int cardsLeft = 5;
				for (auto& card : m_currentPlayer->GetCards())
				{
					for (auto& it : m_Cards)
					{
						if (it.second == m_currentPlayer->GetCards()[index])
						{
							if (!it.second->IsEpidemicCard() && !it.second->IsEventCard())
							{
								if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Red && cardsLeft > 0)
								{
									m_currentPlayer->GetCards().erase(m_currentPlayer->GetCards().begin() + index);
									cardsLeft--;
									if (index > 0)
										index--;
								}
							}
						}
					}
					if(index < m_currentPlayer->GetCards().size() - 2)
						index++;
				}

				m_currentPlayer->RearangeCards();
				m_curedRedVirus = 1;
			}
			else if (have5CardsWithSameColor == 3 && m_curedBlueVirus == 0)
			{
				m_statsTableBoard.SetBlueVirusTexture("Res//BluePotion.png");
				int index = 0;
				int cardsLeft = 5;
				for (auto& card : m_currentPlayer->GetCards())
				{
					for (auto& it : m_Cards)
					{
						if (it.second == m_currentPlayer->GetCards()[index])
						{
							if (!it.second->IsEpidemicCard() && !it.second->IsEventCard())
							{
								if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Blue && cardsLeft > 0)
								{
									m_currentPlayer->GetCards().erase(m_currentPlayer->GetCards().begin() + index);
									cardsLeft--;
									if (index != 0)
										index--;
								}
							}
						}
					}
					if (index < m_currentPlayer->GetCards().size() - 2)
						index++;
				}

				m_currentPlayer->RearangeCards();
				m_curedBlueVirus = 1;
			}
			else if (have5CardsWithSameColor == 4 && m_curedBlackVirus == 0)
			{
				m_statsTableBoard.SetBlackVirusTexture("Res//BlackPotion.png");
				int index = 0;
				int cardsLeft = 5;
				for (auto& card : m_currentPlayer->GetCards())
				{
					for (auto& it : m_Cards)
					{
						if (it.second == m_currentPlayer->GetCards()[index])
						{
							if (!it.second->IsEpidemicCard() && !it.second->IsEventCard())
							{
								if (this->m_mapCities[it.first]->GetColorCity() == sf::Color::Black && cardsLeft > 0)
								{
									m_currentPlayer->GetCards().erase(m_currentPlayer->GetCards().begin() + index);
									cardsLeft--;
									if (index > 0)
										index--;
								}
							}
						}
					}
					if (index < m_currentPlayer->GetCards().size() - 2)
						index++;
				}

				m_currentPlayer->RearangeCards();
				m_curedBlackVirus = 1;
			}
		}
		if (m_curedYellowVirus == 1 && m_curedRedVirus == 1 && m_curedBlueVirus == 1 && m_curedBlackVirus == 1)
			std::cout << " YOU SAVED THE WORLD !";
	}
}

void GamePlayGraphics::UpdateShareButton()
{
	if (m_isSharePressed)
	{
		if (m_currentPlayer != nullptr)
		{
			if (m_currentPlayer == m_pawn1 && m_currentPlayer->GetCurrentCity()==m_pawn2->GetCurrentCity())
			{
				Card* aux2 = nullptr;
				int index=m_currentPlayer->pressedCard(aux2);
			
				if (index != -1)
				{
					std::string PressedCard = GetCityEventString(aux2);

					if (m_mapCities[PressedCard] == m_currentPlayer->GetCurrentCity() && m_mapCities[PressedCard] == m_pawn2->GetCurrentCity())
					{
						m_currentPlayer->EraseCard(index);
						m_currentPlayer->RearangeCards();

						if (aux2 != nullptr)
						{
							m_pawn2->AddCards(aux2);
							m_isSharePressed = false;
							m_turnStateGraphic->DecreaseTurn();
						}
					}
				}
			}

			else if (m_currentPlayer == m_pawn2 && m_currentPlayer->GetCurrentCity()==m_pawn1->GetCurrentCity())
			{
				Card* aux1 = nullptr;
				int index=m_currentPlayer->pressedCard(aux1);

				if (index != -1)
				{
					std::string PressedCard = GetCityEventString(aux1);

					if (m_mapCities[PressedCard] == m_currentPlayer->GetCurrentCity() && m_mapCities[PressedCard] == m_pawn1->GetCurrentCity())
					{
						m_currentPlayer->EraseCard(index);
						m_currentPlayer->RearangeCards();

						if (aux1 != nullptr)
						{
							m_pawn1->AddCards(aux1);
							m_isSharePressed = false;
							m_turnStateGraphic->DecreaseTurn();
						}
					}
				}
			}

		}
	}

}

void GamePlayGraphics::ShareRandomCardsForPlayers(Pawn*& pawn,int numberCards)
{
	//int x;

	//std::srand(time(NULL));

	for (int index = 0; index < numberCards; index++)
	{
		m_toRandCityCardsCurrentPlayer.push_back(deckCityEventAndEpidemicCard.back());
		deckCityEventAndEpidemicCard.pop_back();
	}

	m_statsTeamPlayer1->AddCity(m_statsTeamCity["ALGER"]);

	/*m_toRandCityCardsCurrentPlayer.push_back(m_Cards["EPIDEMIC"]);*/
}

void GamePlayGraphics::DropCardsToSeven()
{
	if (m_currentPlayer != nullptr && haveMoreThan7)
	{
		if (m_dropCardsTimer == nullptr || m_dropCardsTimer->getElapsedTime().asSeconds() > 1)
		{
			if (m_currentPlayer->GetCards().size() > 7)
			{
				Card* aux;

				int index = m_currentPlayer->pressedCard(aux);

				if (index != -1 && aux != nullptr)
				{
					if (m_dropCardsTimer == nullptr)
						m_dropCardsTimer = new sf::Clock();

					else
					{
						m_dropCardsTimer->restart();
					}

					m_currentPlayer->EraseCard(index);
					m_currentPlayer->RearangeCards();

					if (m_currentPlayer->GetCards().size() <= 7)
						haveMoreThan7 = false;
				}
			}
		}
	}
}

const std::string& GamePlayGraphics::GetCityEventString(Card*& card)
{
	for (auto& it : m_Cards)
		if (it.second == card)
			return it.first;
	return std::string("");
}


void GamePlayGraphics::UpdateChosenInfectionCards()
{
	if (m_toRandInfectionCards.size() && m_toRandCityCardsCurrentPlayer.size()==0)
	{
		if (m_toRandInfectionCards.back().second.sprite.getPosition().x <= 300)
		{
			m_toRandInfectionCards.back().second.sprite.move(sf::Vector2f(0.5, 0.1));
			m_toRandInfectionCards.back().second.sprite.setScale(sf::Vector2f(m_toRandInfectionCards.back().second.sprite.getScale().x + 0.002, m_toRandInfectionCards.back().second.sprite.getScale().y + 0.002));
		}

		else
		{
			for (int index = 0; index < m_boardCities.size(); index++)
			{
				std::string str = m_boardCities[index].GetText().getString();

				if (str == m_toRandInfectionCards.back().first)
				{
					m_arrow.first.setPosition(sf::Vector2f(m_boardCities[index].GetPosition().x-25,m_boardCities[index].GetPosition().y-120));

					if (m_IsInfected.back() == false)
					{

						if (m_toRandInfectionCards.size() >= 7 || drawEpidemicCard)
						{

							if (m_toRandInfectionCards.back().second.color == sf::Color::Yellow)
							{
								if (drawEpidemicCard)
								{
									while (m_boardCities[index].getNumberOfYellowVirus() < 3)
									{
										m_boardCities[index].AddYellowVirus();
										m_statsTableBoard.DecreaseYellowVirus();
									}
								}
								else
								{
									m_boardCities[index].AddYellowVirus();
									m_boardCities[index].AddYellowVirus();
									m_boardCities[index].AddYellowVirus();

									m_statsTableBoard.DecreaseYellowVirus();
									m_statsTableBoard.DecreaseYellowVirus();
									m_statsTableBoard.DecreaseYellowVirus();
								}
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Red)
							{
								if (drawEpidemicCard)
								{
									while (m_boardCities[index].getNumberOfRedVirus() < 3)
									{
										m_boardCities[index].AddRedVirus();
										m_statsTableBoard.DecreaseRedVirus();
									}
								}
								else
								{
									m_boardCities[index].AddRedVirus();
									m_boardCities[index].AddRedVirus();
									m_boardCities[index].AddRedVirus();

									m_statsTableBoard.DecreaseRedVirus();
									m_statsTableBoard.DecreaseRedVirus();
									m_statsTableBoard.DecreaseRedVirus();
								}
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Black)
							{
								if (drawEpidemicCard)
								{
									while (m_boardCities[index].getNumberOfBlackVirus() < 3)
									{
										m_boardCities[index].AddBlackVirus();
										m_statsTableBoard.DecreaseBlackVirus();
									}
								}
								else
								{
									m_boardCities[index].AddBlackVirus();
									m_boardCities[index].AddBlackVirus();
									m_boardCities[index].AddBlackVirus();

									m_statsTableBoard.DecreaseBlackVirus();
									m_statsTableBoard.DecreaseBlackVirus();
									m_statsTableBoard.DecreaseBlackVirus();
								}
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Blue)
							{
								if (drawEpidemicCard)
								{
									while (m_boardCities[index].getNumberOfBlueVirus() < 3)
									{
										m_boardCities[index].AddBlueVirus();
										m_statsTableBoard.DecreaseBlueVirus();
									}
								}
								else
								{
									m_boardCities[index].AddBlueVirus();
									m_boardCities[index].AddBlueVirus();
									m_boardCities[index].AddBlueVirus();

									m_statsTableBoard.DecreaseBlueVirus();
									m_statsTableBoard.DecreaseBlueVirus();
									m_statsTableBoard.DecreaseBlueVirus();
								}
							}

								drawEpidemicCard = false;
						}

						else if (m_toRandInfectionCards.size() >= 4 && m_statsInfectionRate.GetInfectionRateValue() != 4)
						{
							if (m_toRandInfectionCards.back().second.color == sf::Color::Yellow)
							{
								m_boardCities[index].AddYellowVirus();
								m_boardCities[index].AddYellowVirus();

								m_statsTableBoard.DecreaseYellowVirus();
								m_statsTableBoard.DecreaseYellowVirus();
							}
							else if (m_toRandInfectionCards.back().second.color == sf::Color::Red)
							{

								m_boardCities[index].AddRedVirus();
								m_boardCities[index].AddRedVirus();

								m_statsTableBoard.DecreaseRedVirus();
								m_statsTableBoard.DecreaseRedVirus();
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Black)
							{
								m_boardCities[index].AddBlackVirus();
								m_boardCities[index].AddBlackVirus();
								

								m_statsTableBoard.DecreaseBlackVirus();
								m_statsTableBoard.DecreaseBlackVirus();
								
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Blue)
							{
								m_boardCities[index].AddBlueVirus();
								m_boardCities[index].AddBlueVirus();
								

								m_statsTableBoard.DecreaseBlueVirus();
								m_statsTableBoard.DecreaseBlueVirus();
								
							}

							drawEpidemicCard = false;
						}
						else if (m_toRandInfectionCards.size() >= 1)
						{
							if (m_toRandInfectionCards.back().second.color == sf::Color::Yellow)
							{
								if (m_boardCities[index].getNumberOfYellowVirus() < 3)
								{
									m_boardCities[index].AddYellowVirus();
									m_statsTableBoard.DecreaseYellowVirus();
								}
								else
								{
									std::queue<BoardCity*> breadthFirst;
									std::vector<BoardCity*> visited;

									BoardCity* city = &m_boardCities[index];
									std::cout << city->GetText().getString().toAnsiString() << "\n";
									breadthFirst.push(city);
									visited.push_back(city);

									while (!breadthFirst.empty())
									{
										city = breadthFirst.front();
										breadthFirst.pop();
										if (city->getNumberOfYellowVirus() < 3)
										{
											city->AddYellowVirus();
											m_statsTableBoard.DecreaseYellowVirus();
										}
										else
										{
											if (city->getNumberOfYellowVirus() == 3)
											{
												m_statsInfectionRate.updateOutbreaksMarker();
												for (auto& neighbour : city->getNeighborCities())
												{
													bool isVisited = 0;
													for (auto& visitedCity : visited)
														if (neighbour.second->GetText().getString() == visitedCity->GetText().getString())
															isVisited = 1;
													if (isVisited == 0)
													{
														breadthFirst.push(neighbour.second);
														visited.push_back(neighbour.second);
														std::cout << "   " << neighbour.second->GetText().getString().toAnsiString() << " " << neighbour.second->getNumberOfYellowVirus() << "\n";
													}
												}
											}
										}
									}
									visited.clear();
								}
							}
							else if (m_toRandInfectionCards.back().second.color == sf::Color::Red)
							{
								if (m_boardCities[index].getNumberOfRedVirus() < 3)
								{
									m_boardCities[index].AddRedVirus();
									m_statsTableBoard.DecreaseRedVirus();
								}
								else
								{
									std::queue<BoardCity*> breadthFirst;
									std::vector<BoardCity*> visited;

									BoardCity* city = &m_boardCities[index];
									std::cout << city->GetText().getString().toAnsiString() << "\n";
									breadthFirst.push(city);
									visited.push_back(city);

									while (!breadthFirst.empty())
									{
										city = breadthFirst.front();
										breadthFirst.pop();
										if (city->getNumberOfRedVirus() < 3)
										{
											city->AddRedVirus();
											m_statsTableBoard.DecreaseRedVirus();
										}
										else
										{
											if (city->getNumberOfRedVirus() == 3)
											{
												m_statsInfectionRate.updateOutbreaksMarker();
												for (auto& neighbour : city->getNeighborCities())
												{
													bool isVisited = 0;
													for (auto& visitedCity : visited)
														if (neighbour.second->GetText().getString() == visitedCity->GetText().getString())
															isVisited = 1;
													if (isVisited == 0)
													{
														breadthFirst.push(neighbour.second);
														visited.push_back(neighbour.second);
														std::cout << "   " << neighbour.second->GetText().getString().toAnsiString() << " " << neighbour.second->getNumberOfRedVirus() << "\n";
													}
												}
											}

										}
									}
									visited.clear();
								}
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Black)
							{
								if (m_boardCities[index].getNumberOfBlackVirus() < 3)
								{
									m_boardCities[index].AddBlackVirus();
									m_statsTableBoard.DecreaseBlackVirus();
								}
								else
								{
									std::queue<BoardCity*> breadthFirst;
									std::vector<BoardCity*> visited;

									BoardCity* city = &m_boardCities[index];
									std::cout << city->GetText().getString().toAnsiString() << "\n";
									breadthFirst.push(city);
									visited.push_back(city);

									while (!breadthFirst.empty())
									{
										city = breadthFirst.front();
										breadthFirst.pop();
										if (city->getNumberOfBlackVirus() < 3)
										{
											city->AddBlackVirus();
											m_statsTableBoard.DecreaseBlackVirus();
										}
										else
										{
											if (city->getNumberOfBlackVirus() == 3)
											{
												m_statsInfectionRate.updateOutbreaksMarker();
												for (auto& neighbour : city->getNeighborCities())
												{
													bool isVisited = 0;
													for (auto& visitedCity : visited)
														if (neighbour.second->GetText().getString() == visitedCity->GetText().getString())
															isVisited = 1;
													if (isVisited == 0)
													{
														breadthFirst.push(neighbour.second);
														visited.push_back(neighbour.second);
														std::cout << "   " << neighbour.second->GetText().getString().toAnsiString() << " " << neighbour.second->getNumberOfBlackVirus() << "\n";
													}
												}
											}
										}
									}
									visited.clear();
								}
							}

							else if (m_toRandInfectionCards.back().second.color == sf::Color::Blue)
							{
								if (m_boardCities[index].getNumberOfBlueVirus() < 3)
								{
									m_boardCities[index].AddBlueVirus();
									m_statsTableBoard.DecreaseBlueVirus();
								}
								else
								{
									std::queue<BoardCity*> breadthFirst;
									std::vector<BoardCity*> visited;

									BoardCity* city = &m_boardCities[index];
									std::cout << city->GetText().getString().toAnsiString() << "\n";
									breadthFirst.push(city);
									visited.push_back(city);

									while (!breadthFirst.empty())
									{
										city = breadthFirst.front();
										breadthFirst.pop();
										if (city->getNumberOfBlueVirus() < 3)
										{
											city->AddBlueVirus();
											m_statsTableBoard.DecreaseBlueVirus();
										}
										else
										{
											if (city->getNumberOfBlueVirus() == 3)
											{
												m_statsInfectionRate.updateOutbreaksMarker();
												for (auto& neighbour : city->getNeighborCities())
												{
													bool isVisited = 0;
													for (auto& visitedCity : visited)
														if (neighbour.second->GetText().getString() == visitedCity->GetText().getString())
															isVisited = 1;
													if (isVisited == 0)
													{
														breadthFirst.push(neighbour.second);
														visited.push_back(neighbour.second);
														std::cout << "   " << neighbour.second->GetText().getString().toAnsiString() << " " << neighbour.second->getNumberOfBlueVirus() << "\n";
													}
												}
											}
										}
									}
									visited.clear();
								}
							}
						}

						drawEpidemicCard = false;

						m_IsInfected.back() = true;
					}
					/*m_blackSquare.first.setPosition(sf::Vector2f(m_boardCities[index].GetPosition().x + 35, m_boardCities[index].GetPosition().y+25));*/
					/*m_blackSquare.first.setOrigin(sf::Vector2f(m_boardCities[index].GetPosition().x-60, m_boardCities[index].GetPosition().y - 50));*/
				}
			}
		}
	}
}

void GamePlayGraphics::UpdateSharedCityCardsAndEvents()
{
	if (m_toRandCityCardsCurrentPlayer.size())
	{
		if (m_toRandCityCardsCurrentPlayer.back()->GetPosition().x <= 300)
		{
			m_toRandCityCardsCurrentPlayer.back()->Move(sf::Vector2f(0.5, 0.1));
			m_toRandCityCardsCurrentPlayer.back()->SetScale(sf::Vector2f(m_toRandCityCardsCurrentPlayer.back()->GetScale().x + 0.002, m_toRandCityCardsCurrentPlayer.back()->GetScale().y+ 0.002));
		}
	}
}

void GamePlayGraphics::UpdateViruses()
{
	//if (m_blackSquare.first.getPosition() != sf::Vector2f(0, 0))
	//{
	//	/*m_blackSquare.first.move(sf::Vector2f(0.1, 0));*/
	//	m_blackSquare.first.rotate(1);
	//}
}

void GamePlayGraphics::UpdateMovePawn()
{
	if (m_toRandInfectionCards.size() == 0)
	{
		if (m_actionBoard.IsMovePressed())
		{
			for (auto& it : m_currentPlayer->GetCurrentCity()->getNeighborCities())
			{
				it.second->setAvailable();
				m_toMoveCities.push_back(*it.second);
			}

		}


		if (m_toMoveCities.size())
		{
			for (auto& it : m_currentPlayer->GetCurrentCity()->getNeighborCities())
			{
				if (it.second->IsCityPressed())
				{
					for (int index = 0; index < m_boardCities.size(); index++)
						m_boardCities[index].SetNormalColor();

					this->itCureInCity = true;
					sf::Vector2f position = sf::Vector2f(m_mapCities[it.first]->GetLastPositionFromPlayers().x + 10, m_mapCities[it.first]->GetLastPositionFromPlayers().y);
					m_currentPlayer->Move(position);
					m_mapCities[it.first]->AddPlayersInPosition(position);
					m_currentPlayer->SetCurrentCity(m_mapCities[it.first]);

					m_turnStateGraphic->DecreaseTurn();


					m_toMoveCities.clear();
					break;
				}
			}
		}
	}
}

void GamePlayGraphics::UpdatePawn()
{
	m_pawn1->Update(m_window);

	m_pawn2->Update(m_window);
}

void GamePlayGraphics::UpdateCurrentPlayer()
{
	if (m_turnStateGraphic->GetRemainingMovesPosible() == 0)
	{
		numberOfTurns++;

		m_turnStateGraphic->Reset();
		m_currentPlayer->SetTurn(false);
		if (m_currentPlayer == m_pawn1)
		{
			//m_currentPlayer->SetCurrentCity(m_pawn2->GetCurrentCity());
			m_currentPlayer = m_pawn2;
		}
		else
		{
			//m_currentPlayer->SetCurrentCity(m_pawn1->GetCurrentCity());
			m_currentPlayer = m_pawn1;
		}

		m_currentPlayer->SetTurn(true);
		
		if (changefirstTurn)
		{
			ShareRandomCardsForPlayers(m_currentPlayer, 2);
		}

		changefirstTurn = true;
	}
}

void GamePlayGraphics::UpdateTreatButton()
{
	if (m_currentPlayer != nullptr && m_actionBoard.IsTreatPressed() && m_currentPlayer->GetCurrentCity()->GetNumberOfVirus() > 0 && m_clock.getElapsedTime().asSeconds() > 1)
	{
		if (m_currentPlayer->GetCurrentCity()->GetLastVirusColor() == "Yellow")
			m_statsTableBoard.AddYellowVirus();

		else if (m_currentPlayer->GetCurrentCity()->GetLastVirusColor() == "Red")
			m_statsTableBoard.AddRedVirus();

		else if (m_currentPlayer->GetCurrentCity()->GetLastVirusColor() == "Black")
			m_statsTableBoard.AddBlackVirus();

		else if (m_currentPlayer->GetCurrentCity()->GetLastVirusColor() == "Blue")
			m_statsTableBoard.AddBlueVirus();

		m_currentPlayer->GetCurrentCity()->EliminateVirus();

		m_turnStateGraphic->DecreaseTurn();

		m_clock.restart();
	}
}

void GamePlayGraphics::UpdateBuildButton()
{
	if (m_currentPlayer != nullptr && m_actionBoard.IsBuildPressed() && !m_currentPlayer->GetCurrentCity()->HaveResearchStation() && m_numberResearchStation < 7)
	{
		if (m_statsTableBoard.getNumberOFResearchStations() > 0) {
			m_numberResearchStation++;
			m_turnStateGraphic->DecreaseTurn();
			m_currentPlayer->GetCurrentCity()->AddBuild();
			m_numberResearchStation--;
			m_statsTableBoard.DecreaseResearchStations();
		}
	}
}

void GamePlayGraphics::UpdatePassButton()
{
	if(m_actionBoard.IsPassPressed())
		m_turnStateGraphic->DecreaseTurn();
}

void GamePlayGraphics::UpdateChooseRandomInfectionCards()
{
	if (m_turnStateGraphic != nullptr)
	{
		if (m_turnStateGraphic->GetRemainingMovesPosible() == 0 && m_infectionCards.size() != 0)
			ChooseRandomInfectionCards(m_statsInfectionRate.GetInfectionRateValue());
	}
}

void GamePlayGraphics::RendChosenInfectionCards()
{
	if (!m_toRandCityCardsCurrentPlayer.size() && m_toRandInfectionCards.size())
	{
		if (m_toRandInfectionCards.back().second.sprite.getPosition().x < 300)
		{
			m_window.draw(m_toRandInfectionCards.back().second.sprite);
		}


		else if (numberOfDraw <= 500)
			{
				m_window.draw(m_toRandInfectionCards.back().second.sprite);
				m_window.draw(m_arrow.first);
				numberOfDraw++;
			}

		else
		{
			numberOfDraw = 0;
			m_toRandInfectionCards.pop_back();
			m_IsInfected.pop_back();
		}
	}
}

void GamePlayGraphics::RendViruses()
{
	if (m_blackSquare.first.getPosition() != sf::Vector2f(0, 0))
		m_window.draw(m_blackSquare.first);
}

void GamePlayGraphics::RendPawn()
{
	if (m_pawn1 != nullptr)
		m_pawn1->Rend(m_window);

	if (m_pawn2 != nullptr)
		m_pawn2->Rend(m_window);
}

void GamePlayGraphics::RendStatsTableTurn()
{
	if (m_turnStateGraphic != nullptr)
		m_turnStateGraphic->Render(m_window);
}

void GamePlayGraphics::RendCityCards()
{
	if (m_toRandCityCardsCurrentPlayer.size())
	{
		if (m_toRandCityCardsCurrentPlayer.back()->GetPosition().x < 300)
		{
			m_toRandCityCardsCurrentPlayer.back()->Rend(m_window);
		}


		else if (numberOfDraw <= 500)
		{
			m_toRandCityCardsCurrentPlayer.back()->Rend(m_window);
			//m_window.draw(m_arrow.first);
			numberOfDraw++;
		}

		else
		{
			numberOfDraw = 0;

			if (m_toRandCityCardsCurrentPlayer.back()->IsEpidemicCard())
			{
				m_statsInfectionRate.updateInfectionRate();

				std::random_device rd;
				std::mt19937 g(rd());

				std::shuffle(residualInfectionCard.begin(), residualInfectionCard.end(), g);

				for (int index = 0; index < residualInfectionCard.size(); index++)
					deckInfectionCard.push_back(residualInfectionCard[index]);

				m_toRandInfectionCards.clear();

				residualInfectionCard.clear();

				ChooseRandomInfectionCards(m_statsInfectionRate.GetInfectionRateValue());

				ChooseRandomInfectionCards(1, true);

				drawEpidemicCard = true;

			}

			else if (firstDraw)
			{
				if (m_toRandCityCardsCurrentPlayer.size() > 4)
					m_pawn1->AddCards(m_toRandCityCardsCurrentPlayer.back());
				else m_pawn2->AddCards(m_toRandCityCardsCurrentPlayer.back());
			}

			else if (!m_toRandCityCardsCurrentPlayer.back()->IsEpidemicCard())
			{
				 m_currentPlayer->AddCards(m_toRandCityCardsCurrentPlayer.back());

				m_choosedInfectionCards.clear();
			}

			m_toRandCityCardsCurrentPlayer.pop_back();

			if (m_currentPlayer->GetCards().size() >= 7 && m_toRandCityCardsCurrentPlayer.size()==0)
				haveMoreThan7 = true;

			if (firstDraw && m_toRandCityCardsCurrentPlayer.size() == 0)
				firstDraw = false;
		}
	}
}

