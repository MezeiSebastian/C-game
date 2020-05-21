#include "GameState.h"

GameState::GameState(sf::RenderWindow& window):State(window)
{
	m_window.setView(sf::View(sf::FloatRect(0, 0, 1920, 1080)));

	initBackground();
	initFont();
	initBlueRound();
	initRedRound();
	initYellowRound();
	initBlackRound();
	initCities();
	initCityConnections();

	m_begin = std::clock();
}

void GameState::update()
{
	updateBlueRounds();
	for (int index = 0; index < m_cities.size(); index++)
		m_cities[index].Update(m_window);

	//updateActionBoard();

	m_end = std::clock();

	if (m_gamePlay==nullptr && m_end - m_begin >= 200)
		m_gamePlay = new GamePlayGraphics(m_window,m_cities,m_actionBoard,m_statsTableBoard,m_infectionRateBoard);

	if (m_gamePlay != nullptr  && m_end - m_begin >= 300)
		m_gamePlay->update();
}

void GameState::render()
{
	rendBackground();
	rendCityConnections();
	rendCities();
	rendStatsTableBoard();
	/*rendActionBoard();*/

	m_infectionRateBoard.render(m_window);

	if (m_gamePlay != nullptr)
		m_gamePlay->rend();
}

void GameState::endState()
{
}

void GameState::updateSFMLEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

bool GameState::initBackground()
{
	sf::Texture backgroundTexture;

	if (!backgroundTexture.loadFromFile("Res//Background.png"))
		throw("could not load background");

	m_textures["background"] = backgroundTexture;

	sf::Sprite backgroundSprite(m_textures["background"]);

	m_sprites["background"] = backgroundSprite;

	return true;
}

bool GameState::initBlueRound()
{
	sf::Texture blueRoundTexture;

	if (!blueRoundTexture.loadFromFile("Res//Rounds//Pan_Blue_Circle.png"))
		throw("could not load blue round");

	m_textures["blue_round"] = blueRoundTexture;

	sf::Sprite blueRoundSprite(m_textures["blue_round"]);
	blueRoundSprite.setScale(0.05,0.05);
	blueRoundSprite.setPosition(300,500);

	m_rounds["blue_round"] = blueRoundSprite;
}

bool GameState::initRedRound()
{
	sf::Texture redRoundTexture;

	if (!redRoundTexture.loadFromFile("Res//Rounds//Pan_Red_Circle.png"))
		throw("could not load red round texture");

	m_textures["red_round"] = redRoundTexture;

	sf::Sprite redRoundSprite(m_textures["red_round"]);
	redRoundSprite.setScale(0.02, 0.02);
	redRoundSprite.setPosition(500, 500);

	m_rounds["red_round"] = redRoundSprite;
}

bool GameState::initYellowRound()
{
	sf::Texture yellowRoundTexture;

	if (!yellowRoundTexture.loadFromFile("Res//Rounds//Pan_Yellow_Circle.png"))
		throw("could not load yellow round texture");

	m_textures["yellow_round"] = yellowRoundTexture;

	sf::Sprite yellowRoundSprite(m_textures["yellow_round"]);
	yellowRoundSprite.setScale(0.03, 0.03);
	yellowRoundSprite.setPosition(600, 600);

	m_rounds["yellow_round"] = yellowRoundSprite;
}

bool GameState::initBlackRound()
{
	sf::Texture blackRoundTexture;

	if (!blackRoundTexture.loadFromFile("Res//Rounds//Pan_Black_Circle.png"))
		throw("could not load black round texture");

	m_textures["black_round"] = blackRoundTexture;

	sf::Sprite blackRoundSprite(m_textures["black_round"]);
	blackRoundSprite.setScale(0.07,0.07);
	blackRoundSprite.setPosition(700,700);

	m_rounds["black_round"] = blackRoundSprite;
}

bool GameState::initCities()
{
	sf::Text text;
	text.setFont(m_font);
	text.setString("BEIJING");
	text.setCharacterSize(13);

	m_cities.push_back(BoardCity(m_rounds["red_round"], text,sf::Color::Red));
	m_cities[0].SetPosition(sf::Vector2i(1300,400));
	m_mapCities.insert(std::make_pair("BEIJING", m_cities[0]));

	text.setString("SEOUL");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text,sf::Color::Red));
	m_cities[1].SetPosition(sf::Vector2i(1500,380));
	m_mapCities.insert(std::make_pair("SEOUL", m_cities[1]));

	text.setString("SHANGHAI");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text,sf::Color::Red));
	m_cities[2].SetPosition(sf::Vector2i(1420,490));
	m_mapCities.insert(std::make_pair("SHANGHAI", m_cities[2]));

	text.setString("TOKYO");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text,sf::Color::Red));
	m_cities[3].SetPosition(sf::Vector2i(1560,470));
	m_mapCities.insert(std::make_pair("TOKYO", m_cities[3]));

	text.setString("HONG KONG");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[4].SetPosition(sf::Vector2i(1400,600));
	m_mapCities.insert(std::make_pair("HONG KONG", m_cities[4]));

	text.setString("TAIPEI");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[5].SetPosition(sf::Vector2i(1550,560));
	m_mapCities.insert(std::make_pair("TAIPEI", m_cities[5]));

	text.setString("OSAKA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[6].SetPosition(sf::Vector2i(1700,520));
	m_mapCities.insert(std::make_pair("OSAKA", m_cities[6]));

	text.setString("BANGKOK");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[7].SetPosition(sf::Vector2i(1350,650));
	m_mapCities.insert(std::make_pair("BANGKOK", m_cities[7]));

	text.setString("HO CHI MINH CITY");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[8].SetPosition(sf::Vector2i(1450,720));
	m_mapCities.insert(std::make_pair("HO CHI MINH CITY", m_cities[8]));

	text.setString("MANILA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[9].SetPosition(sf::Vector2i(1550,680));
	m_mapCities.insert(std::make_pair("MANILA", m_cities[9]));

	text.setString("SYDNEY");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[10].SetPosition(sf::Vector2i(1600,900));
	m_mapCities.insert(std::make_pair("SYDNEY", m_cities[10]));

	text.setString("JAKARTA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text, sf::Color::Red));
	m_cities[11].SetPosition(sf::Vector2i(1400,780));
	m_mapCities.insert(std::make_pair("JAKARTA", m_cities[11]));

	text.setString("KOLKATA");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text,sf::Color::Black));
	m_cities[12].SetPosition(sf::Vector2i(1300,520));
	m_mapCities.insert(std::make_pair("KOLKATA", m_cities[12]));

	text.setString("CHENNAI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[13].SetPosition(sf::Vector2i(1250,670));
	m_mapCities.insert(std::make_pair("CHENNAI", m_cities[13]));

	text.setString("MUMBAI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[14].SetPosition(sf::Vector2i(1150,620));
	m_mapCities.insert(std::make_pair("MUMBAI", m_cities[14]));

	text.setString("DELHI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[15].SetPosition(sf::Vector2i(1200,490));
	m_mapCities.insert(std::make_pair("DELHI", m_cities[15]));

	text.setString("KARACHI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[16].SetPosition(sf::Vector2i(1120,540));
	m_mapCities.insert(std::make_pair("KARACHI", m_cities[16]));

	text.setString("RIYADH");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[17].SetPosition(sf::Vector2i(1050,590));
	m_mapCities.insert(std::make_pair("RIYADH", m_cities[17]));

	text.setString("BAGDAD");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[18].SetPosition(sf::Vector2i(1050,480));
	m_mapCities.insert(std::make_pair("BAGDAD", m_cities[18]));

	text.setString("TEHRAN");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[19].SetPosition(sf::Vector2i(1100,400));
	m_mapCities.insert(std::make_pair("TEHRAN", m_cities[19]));

	text.setString("MOSCOW");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[20].SetPosition(sf::Vector2i(1000,400));
	m_mapCities.insert(std::make_pair("MOSCOW", m_cities[20]));

	text.setString("ISTANBUL");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[21].SetPosition(sf::Vector2i(960,490));
	m_mapCities.insert(std::make_pair("ISTANBUL", m_cities[21]));

	text.setString("CAIRO");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[22].SetPosition(sf::Vector2i(960,590));
	m_mapCities.insert(std::make_pair("CAIRO", m_cities[22]));

	text.setString("ALGER");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text, sf::Color::Black));
	m_cities[23].SetPosition(sf::Vector2i(830,550));
	m_mapCities.insert(std::make_pair("ALGER", m_cities[23]));

	text.setString("LAGOS");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[24].SetPosition(sf::Vector2i(830,650));
	m_mapCities.insert(std::make_pair("LAGOS", m_cities[24]));

	text.setString("KHARTOUM");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[25].SetPosition(sf::Vector2i(970,670));
	m_mapCities.insert(std::make_pair("KHARTOUM", m_cities[25]));

	text.setString("KINSHASA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[26].SetPosition(sf::Vector2i(900,730));
	m_mapCities.insert(std::make_pair("KINSHASA", m_cities[26]));

	text.setString("JOHANNESBURG");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[27].SetPosition(sf::Vector2i(1000,780));
	m_mapCities.insert(std::make_pair("JOHANNESBURG", m_cities[27]));

	text.setString("SAO PAULO");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[28].SetPosition(sf::Vector2i(650,840));
	m_mapCities.insert(std::make_pair("SAO PAULO", m_cities[28]));

	text.setString("BUENOS AIRES");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[29].SetPosition(sf::Vector2i(600,900));
	m_mapCities.insert(std::make_pair("BUENOS AIRES", m_cities[29]));

	text.setString("SANTIAGO");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[30].SetPosition(sf::Vector2i(470, 920));
	m_mapCities.insert(std::make_pair("SANTIAGO", m_cities[30]));

	text.setString("LIMA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[31].SetPosition(sf::Vector2i(470,800));
	m_mapCities.insert(std::make_pair("LIMA", m_cities[31]));

	text.setString("BOGOTA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[32].SetPosition(sf::Vector2i(490,700));
	m_mapCities.insert(std::make_pair("BOGOTA", m_cities[32]));

	text.setString("MIAMI");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[33].SetPosition(sf::Vector2i(490,610));
	m_mapCities.insert(std::make_pair("MIAMI", m_cities[33]));

	text.setString("MEXICO CITY");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[34].SetPosition(sf::Vector2i(380,630));
	m_mapCities.insert(std::make_pair("MEXICO CITY", m_cities[34]));

	text.setString("LOS ANGELES");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text, sf::Color::Yellow));
	m_cities[35].SetPosition(sf::Vector2i(310,560));
	m_mapCities.insert(std::make_pair("LOS ANGELES", m_cities[35]));

	text.setString("SAN FRANCISCO");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text, sf::Color::Blue));
	m_cities[36].SetPosition(sf::Vector2i(280,470));
	m_mapCities.insert(std::make_pair("SAN FRANCISCO", m_cities[36]));

	text.setString("CHICAGO");
	m_cities.push_back(BoardCity(m_rounds["blue_round"],text, sf::Color::Blue));
	m_cities[37].SetPosition(sf::Vector2i(400,420));
	m_mapCities.insert(std::make_pair("CHICAGO", m_cities[37]));

	text.setString("MONTREAL");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text, sf::Color::Blue));
	m_cities[38].SetPosition(sf::Vector2i(500,440));
	m_mapCities.insert(std::make_pair("MONTREAL", m_cities[38]));

	text.setString("WASHINGTON");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text, sf::Color::Blue));
	m_cities[39].SetPosition(sf::Vector2i(530,520));
	m_mapCities.insert(std::make_pair("WASHINGTON", m_cities[39]));

	text.setString("NEW YORK");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text, sf::Color::Blue));
	m_cities[40].SetPosition(sf::Vector2i(620,450));
	m_mapCities.insert(std::make_pair("NEW YORK", m_cities[40]));

	text.setString("ATLANTA");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text, sf::Color::Blue));
	m_cities[41].SetPosition(sf::Vector2i(420, 520));
	m_mapCities.insert(std::make_pair("ATLANTA", m_cities[41]));

	text.setString("LONDON");
	m_cities.push_back(BoardCity(m_rounds["blue_round"],text,sf::Color::Blue));
	m_cities[42].SetPosition(sf::Vector2i(750,370));
	m_mapCities.insert(std::make_pair("LONDON", m_cities[42]));

	text.setString("MADRID");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text,sf::Color::Blue));
	m_cities[43].SetPosition(sf::Vector2i(740,520));
	m_mapCities.insert(std::make_pair("MADRID", m_cities[43]));

	text.setString("PARIS");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text,sf::Color::Blue));
	m_cities[44].SetPosition(sf::Vector2i(800,440));
	m_mapCities.insert(std::make_pair("PARIS", m_cities[44]));

	text.setString("MILAN");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text,sf::Color::Blue));
	m_cities[45].SetPosition(sf::Vector2i(900,460));
	m_mapCities.insert(std::make_pair("MILAN", m_cities[45]));

	text.setString("ESSEN");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text,sf::Color::Blue));
	m_cities[46].SetPosition(sf::Vector2i(900,360));
	m_mapCities.insert(std::make_pair("ESSEN", m_cities[46]));

	text.setString("ST. PETERSBURG");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text,sf::Color::Blue));
	m_cities[47].SetPosition(sf::Vector2i(1000,330));
	m_mapCities.insert(std::make_pair("ST. PETERSBURG", m_cities[47]));

	return true;
}

void GameState::initCityConnections()
{
	sf::VertexArray line(sf::LinesStrip, 2);
	int center = 18;
	line[0].color = sf::Color::Green;
	line[1].color = sf::Color::Green;
	int connection;

	// ALGER (CAIRO, ISTANBUL, PARIS, MADRID)
	line[0].position = sf::Vector2f(m_mapCities["ALGER"].GetPosition().x + center, m_mapCities["ALGER"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["CAIRO"].GetPosition().x + center, m_mapCities["CAIRO"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["ISTANBUL"].GetPosition().x + center, m_mapCities["ISTANBUL"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["PARIS"].GetPosition().x + center, m_mapCities["PARIS"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MADRID"].GetPosition().x + center, m_mapCities["MADRID"].GetPosition().y + center);
	m_lines.push_back(line);



	// ATLANTA (CHICAGO, MIAMI, WASHINGTON)
	line[0].position = sf::Vector2f(m_mapCities["ATLANTA"].GetPosition().x+center, m_mapCities["ATLANTA"].GetPosition().y+center);
	
	line[1].position = sf::Vector2f(m_mapCities["CHICAGO"].GetPosition().x+center, m_mapCities["CHICAGO"].GetPosition().y+center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MIAMI"].GetPosition().x + center, m_mapCities["MIAMI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["WASHINGTON"].GetPosition().x+center, m_mapCities["WASHINGTON"].GetPosition().y+center);
	m_lines.push_back(line);



	// BAGDAD (CAIRO, ISTANBUL, KARACHI, RIYADH, TEHRAN)
	line[0].position = sf::Vector2f(m_mapCities["BAGDAD"].GetPosition().x + center, m_mapCities["BAGDAD"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["CAIRO"].GetPosition().x + center, m_mapCities["CAIRO"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["ISTANBUL"].GetPosition().x + center, m_mapCities["ISTANBUL"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KARACHI"].GetPosition().x + center, m_mapCities["KARACHI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["RIYADH"].GetPosition().x + center, m_mapCities["RIYADH"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TEHRAN"].GetPosition().x + center, m_mapCities["TEHRAN"].GetPosition().y + center);
	m_lines.push_back(line);



	// BANGKOK (CHENNAI, KOLKATA, HO CHI MINH CITY, HONG KONG, JAKARTA)
	line[0].position = sf::Vector2f(m_mapCities["BANGKOK"].GetPosition().x + center, m_mapCities["BANGKOK"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["CHENNAI"].GetPosition().x + center, m_mapCities["CHENNAI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KOLKATA"].GetPosition().x + center, m_mapCities["KOLKATA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["HO CHI MINH CITY"].GetPosition().x + center, m_mapCities["HO CHI MINH CITY"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["HONG KONG"].GetPosition().x + center, m_mapCities["HONG KONG"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["JAKARTA"].GetPosition().x + center, m_mapCities["JAKARTA"].GetPosition().y + center);
	m_lines.push_back(line);



	// BEIJING (SEOUL, SHANGHAI)
	line[0].position = sf::Vector2f(m_mapCities["BEIJING"].GetPosition().x + center, m_mapCities["BEIJING"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["SEOUL"].GetPosition().x + center, m_mapCities["SEOUL"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SHANGHAI"].GetPosition().x + center, m_mapCities["SHANGHAI"].GetPosition().y + center);
	m_lines.push_back(line);



	// BOGOTA (BUENOS AIRES, LIMA, MEXICO CITY, MIAMI, SAO PAULO)
	line[0].position = sf::Vector2f(m_mapCities["BOGOTA"].GetPosition().x + center, m_mapCities["BOGOTA"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["BUENOS AIRES"].GetPosition().x + center, m_mapCities["BUENOS AIRES"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["LIMA"].GetPosition().x + center, m_mapCities["LIMA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MEXICO CITY"].GetPosition().x + center, m_mapCities["MEXICO CITY"].GetPosition().y + center);
	m_lines.push_back(line);
	
	line[1].position = sf::Vector2f(m_mapCities["MIAMI"].GetPosition().x + center, m_mapCities["MIAMI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SAO PAULO"].GetPosition().x + center, m_mapCities["SAO PAULO"].GetPosition().y + center);
	m_lines.push_back(line);



	// BUENOS AIRES (BOGOTA X, SAO PAULO)
	line[0].position = sf::Vector2f(m_mapCities["BUENOS AIRES"].GetPosition().x + center, m_mapCities["BUENOS AIRES"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["SAO PAULO"].GetPosition().x + center, m_mapCities["SAO PAULO"].GetPosition().y + center);
	m_lines.push_back(line);



	// CAIRO (ALGER X, BAGDAD X, ISTANBUL, KHARTOUM, RIYADH)
	line[0].position = sf::Vector2f(m_mapCities["CAIRO"].GetPosition().x + center, m_mapCities["CAIRO"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["ISTANBUL"].GetPosition().x + center, m_mapCities["ISTANBUL"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KHARTOUM"].GetPosition().x + center, m_mapCities["KHARTOUM"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["RIYADH"].GetPosition().x + center, m_mapCities["RIYADH"].GetPosition().y + center);
	m_lines.push_back(line);



	// CHENNAI (BANGKOK X, DELHI, JAKARTA, KOLKATA, MUMBAI)
	line[0].position = sf::Vector2f(m_mapCities["CHENNAI"].GetPosition().x + center, m_mapCities["CHENNAI"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["DELHI"].GetPosition().x + center, m_mapCities["DELHI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["JAKARTA"].GetPosition().x + center, m_mapCities["JAKARTA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KOLKATA"].GetPosition().x + center, m_mapCities["KOLKATA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MUMBAI"].GetPosition().x + center, m_mapCities["MUMBAI"].GetPosition().y + center);
	m_lines.push_back(line);



	// CHICAGO (ATLANTA X, LOS ANGELES, MEXICO CITY, MONTREAL, SAN FRANCISCO)
	line[0].position = sf::Vector2f(m_mapCities["CHICAGO"].GetPosition().x + center, m_mapCities["CHICAGO"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["LOS ANGELES"].GetPosition().x + center, m_mapCities["LOS ANGELES"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MEXICO CITY"].GetPosition().x + center, m_mapCities["MEXICO CITY"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MONTREAL"].GetPosition().x + center, m_mapCities["MONTREAL"].GetPosition().y + center);
	m_lines.push_back(line);
	
	line[1].position = sf::Vector2f(m_mapCities["SAN FRANCISCO"].GetPosition().x + center, m_mapCities["SAN FRANCISCO"].GetPosition().y + center);
	m_lines.push_back(line);



	// DELHI (CHENNAI X, KARACHI, KOLKATA, MUMBAI, TEHRAN)
	line[0].position = sf::Vector2f(m_mapCities["DELHI"].GetPosition().x + center, m_mapCities["DELHI"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["KARACHI"].GetPosition().x + center, m_mapCities["KARACHI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KOLKATA"].GetPosition().x + center, m_mapCities["KOLKATA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MUMBAI"].GetPosition().x + center, m_mapCities["MUMBAI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TEHRAN"].GetPosition().x + center, m_mapCities["TEHRAN"].GetPosition().y + center);
	m_lines.push_back(line);



	// ESSEN (LONDON, MILAN, PARIS, ST. PETERSBURG)
	line[0].position = sf::Vector2f(m_mapCities["ESSEN"].GetPosition().x + center, m_mapCities["ESSEN"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["LONDON"].GetPosition().x + center, m_mapCities["LONDON"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MILAN"].GetPosition().x + center, m_mapCities["MILAN"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["PARIS"].GetPosition().x + center, m_mapCities["PARIS"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["ST. PETERSBURG"].GetPosition().x + center, m_mapCities["ST. PETERSBURG"].GetPosition().y + center);
	m_lines.push_back(line);



	// HO CHI MINH CITY (BANGKOK X, HONG KONG, JAKARTA, MANILA)
	line[0].position = sf::Vector2f(m_mapCities["HO CHI MINH CITY"].GetPosition().x + center, m_mapCities["HO CHI MINH CITY"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["HONG KONG"].GetPosition().x + center, m_mapCities["HONG KONG"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["JAKARTA"].GetPosition().x + center, m_mapCities["JAKARTA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MANILA"].GetPosition().x + center, m_mapCities["MANILA"].GetPosition().y + center);
	m_lines.push_back(line);



	// HONG KONG (BANGKOK X, HO CHI MINH CITY X, KOLKATA, MANILA, SHANGHAI, TAIPEI)
	line[0].position = sf::Vector2f(m_mapCities["HONG KONG"].GetPosition().x + center, m_mapCities["HONG KONG"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["KOLKATA"].GetPosition().x + center, m_mapCities["KOLKATA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MANILA"].GetPosition().x + center, m_mapCities["MANILA"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SHANGHAI"].GetPosition().x + center, m_mapCities["SHANGHAI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TAIPEI"].GetPosition().x + center, m_mapCities["TAIPEI"].GetPosition().y + center);
	m_lines.push_back(line);



	// ISTANBUL (ALGER X, BAGDAD X, CAIRO X, MILAN, MOSCOW, ST. PETERSBURG)
	line[0].position = sf::Vector2f(m_mapCities["ISTANBUL"].GetPosition().x + center, m_mapCities["ISTANBUL"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["MILAN"].GetPosition().x + center, m_mapCities["MILAN"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["MOSCOW"].GetPosition().x + center, m_mapCities["MOSCOW"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["ST. PETERSBURG"].GetPosition().x + center, m_mapCities["ST. PETERSBURG"].GetPosition().y + center);
	m_lines.push_back(line);



	// JAKARTA (BANGKOK X, CHENNAI X, HO CHI MINH CITY X, SYDNEY)
	line[0].position = sf::Vector2f(m_mapCities["JAKARTA"].GetPosition().x + center, m_mapCities["JAKARTA"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["SYDNEY"].GetPosition().x + center, m_mapCities["SYDNEY"].GetPosition().y + center);
	m_lines.push_back(line);



	// JOHANNESBURG (KHARTOUM, KINSHASA)
	line[0].position = sf::Vector2f(m_mapCities["JOHANNESBURG"].GetPosition().x + center, m_mapCities["JOHANNESBURG"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["KHARTOUM"].GetPosition().x + center, m_mapCities["KHARTOUM"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KINSHASA"].GetPosition().x + center, m_mapCities["KINSHASA"].GetPosition().y + center);
	m_lines.push_back(line);



	// KARACHI (BAGDAD X, DELHI X, MUMBAI, RIYADH, TEHRAN)
	line[0].position = sf::Vector2f(m_mapCities["KARACHI"].GetPosition().x + center, m_mapCities["KARACHI"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["MUMBAI"].GetPosition().x + center, m_mapCities["MUMBAI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["RIYADH"].GetPosition().x + center, m_mapCities["RIYADH"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TEHRAN"].GetPosition().x + center, m_mapCities["TEHRAN"].GetPosition().y + center);
	m_lines.push_back(line);



	// KHARTOUM (CAIRO X, KINSHASA, JOHANNESBURG, LAGOS)
	line[0].position = sf::Vector2f(m_mapCities["KHARTOUM"].GetPosition().x + center, m_mapCities["KHARTOUM"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["LAGOS"].GetPosition().x + center, m_mapCities["LAGOS"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["KINSHASA"].GetPosition().x + center, m_mapCities["KINSHASA"].GetPosition().y + center);
	m_lines.push_back(line);



	// KINSHASA (JOHANNESBURG X, KHARTOUM X, LAGOS)
	line[0].position = sf::Vector2f(m_mapCities["KINSHASA"].GetPosition().x + center, m_mapCities["KINSHASA"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["LAGOS"].GetPosition().x + center, m_mapCities["LAGOS"].GetPosition().y + center);
	m_lines.push_back(line);



	// KOLKATA (BANGKOK X, CHENNAI X, DELHI X, HONG KONG X)



	// LAGOS (KHARTOUM X, KINSHASA X, SAO PAULO)
	line[0].position = sf::Vector2f(m_mapCities["LAGOS"].GetPosition().x + center, m_mapCities["LAGOS"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["SAO PAULO"].GetPosition().x + center, m_mapCities["SAO PAULO"].GetPosition().y + center);
	m_lines.push_back(line);



	// LIMA (BOGOTA X, MEXICO CITY, SANTIAGO)
	line[0].position = sf::Vector2f(m_mapCities["LIMA"].GetPosition().x + center, m_mapCities["LIMA"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["MEXICO CITY"].GetPosition().x + center, m_mapCities["MEXICO CITY"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SANTIAGO"].GetPosition().x + center, m_mapCities["SANTIAGO"].GetPosition().y + center);
	m_lines.push_back(line);



	// LONDON (ESSEN X, MADRID, NEW YORK, PARIS)
	line[0].position = sf::Vector2f(m_mapCities["LONDON"].GetPosition().x + center, m_mapCities["LONDON"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["MADRID"].GetPosition().x + center, m_mapCities["MADRID"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["NEW YORK"].GetPosition().x + center, m_mapCities["NEW YORK"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["PARIS"].GetPosition().x + center, m_mapCities["PARIS"].GetPosition().y + center);
	m_lines.push_back(line);



	// LOS ANGELES (MEXICO CITY, SAN FRANCISCO, SYDNEY)
	line[0].position = sf::Vector2f(m_mapCities["LOS ANGELES"].GetPosition().x + center, m_mapCities["LOS ANGELES"].GetPosition().y + center);
	
	line[1].position = sf::Vector2f(m_mapCities["MEXICO CITY"].GetPosition().x + center, m_mapCities["MEXICO CITY"].GetPosition().y + center);
	m_lines.push_back(line);

	connection = (m_mapCities["SYDNEY"].GetPosition().y - m_mapCities["LOS ANGELES"].GetPosition().y) / 2;
	line[1].position = sf::Vector2f(0, m_mapCities["LOS ANGELES"].GetPosition().y + connection);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SAN FRANCISCO"].GetPosition().x + center, m_mapCities["SAN FRANCISCO"].GetPosition().y + center);
	m_lines.push_back(line);

	line[0].position = sf::Vector2f(m_window.getSize().x, m_mapCities["SYDNEY"].GetPosition().y - connection);
	line[1].position = sf::Vector2f(m_mapCities["SYDNEY"].GetPosition().x + center, m_mapCities["SYDNEY"].GetPosition().y + center);
	m_lines.push_back(line);



	// MADRID (ALGER X, LONDON X, NEW YORK, PARIS, SAO PAULO)
	line[0].position = sf::Vector2f(m_mapCities["MADRID"].GetPosition().x + center, m_mapCities["MADRID"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["NEW YORK"].GetPosition().x + center, m_mapCities["NEW YORK"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["PARIS"].GetPosition().x + center, m_mapCities["PARIS"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["SAO PAULO"].GetPosition().x + center, m_mapCities["SAO PAULO"].GetPosition().y + center);
	m_lines.push_back(line);



	// MANILA (HO CHI MINH CITY X, HONG KONG X, SAN FRANCISCO, SYDNEY, TAIPEI)
	line[0].position = sf::Vector2f(m_mapCities["MANILA"].GetPosition().x + center, m_mapCities["MANILA"].GetPosition().y + center);

	connection = (m_mapCities["MANILA"].GetPosition().y - m_mapCities["SAN FRANCISCO"].GetPosition().y) / 2;
	line[1].position = sf::Vector2f(m_window.getSize().x, m_mapCities["MANILA"].GetPosition().y - connection);
	
	m_lines.push_back(line);
	line[0].position = sf::Vector2f(0, m_mapCities["SAN FRANCISCO"].GetPosition().y + connection);
	line[1].position = sf::Vector2f(m_mapCities["SAN FRANCISCO"].GetPosition().x + center, m_mapCities["SAN FRANCISCO"].GetPosition().y + center);
	m_lines.push_back(line);

	line[0].position = sf::Vector2f(m_mapCities["MANILA"].GetPosition().x + center, m_mapCities["MANILA"].GetPosition().y + center);
	line[1].position = sf::Vector2f(m_mapCities["SYDNEY"].GetPosition().x + center, m_mapCities["SYDNEY"].GetPosition().y + center);
	m_lines.push_back(line);

	line[0].position = sf::Vector2f(m_mapCities["MANILA"].GetPosition().x + center, m_mapCities["MANILA"].GetPosition().y + center);
	line[1].position = sf::Vector2f(m_mapCities["TAIPEI"].GetPosition().x + center, m_mapCities["TAIPEI"].GetPosition().y + center);
	m_lines.push_back(line);



	// MEXICO CITY (BOGOTA X, CHICAGO X, LIMA X, LOS ANGELES X, MIAMI)
	line[0].position = sf::Vector2f(m_mapCities["MEXICO CITY"].GetPosition().x + center, m_mapCities["MEXICO CITY"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["MIAMI"].GetPosition().x + center, m_mapCities["MIAMI"].GetPosition().y + center);
	m_lines.push_back(line);



	// MIAMI (ATLANTA X, BOGOTA X, MEXICO CITY X, WASHINGTON)
	line[0].position = sf::Vector2f(m_mapCities["MIAMI"].GetPosition().x + center, m_mapCities["MIAMI"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["WASHINGTON"].GetPosition().x + center, m_mapCities["WASHINGTON"].GetPosition().y + center);
	m_lines.push_back(line);



	// MILAN (ESSEN X, ISTANBUL X, PARIS)
	line[0].position = sf::Vector2f(m_mapCities["MILAN"].GetPosition().x + center, m_mapCities["MILAN"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["PARIS"].GetPosition().x + center, m_mapCities["PARIS"].GetPosition().y + center);
	m_lines.push_back(line);



	// MONTREAL (CHICAGO X, NEW YORK, WASHINGTON)
	line[0].position = sf::Vector2f(m_mapCities["MONTREAL"].GetPosition().x + center, m_mapCities["MONTREAL"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["NEW YORK"].GetPosition().x + center, m_mapCities["NEW YORK"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["WASHINGTON"].GetPosition().x + center, m_mapCities["WASHINGTON"].GetPosition().y + center);
	m_lines.push_back(line);



	// MOSCOW (ISTANBUL X, ST. PETERSBURG, TEHRAN)
	line[0].position = sf::Vector2f(m_mapCities["MOSCOW"].GetPosition().x + center, m_mapCities["MOSCOW"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["ST. PETERSBURG"].GetPosition().x + center, m_mapCities["ST. PETERSBURG"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TEHRAN"].GetPosition().x + center, m_mapCities["TEHRAN"].GetPosition().y + center);
	m_lines.push_back(line);



	// MUMBAI (DELHI X, CHENNAI X, KARACHI X)



	// NEW YORK (LONDON X, MADRID X, MONTREAL X, WASHINGTON)
	line[0].position = sf::Vector2f(m_mapCities["NEW YORK"].GetPosition().x + center, m_mapCities["NEW YORK"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["WASHINGTON"].GetPosition().x + center, m_mapCities["WASHINGTON"].GetPosition().y + center);
	m_lines.push_back(line);



	// OSAKA (TAIPEI, TOKYO)
	line[0].position = sf::Vector2f(m_mapCities["OSAKA"].GetPosition().x + center, m_mapCities["OSAKA"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["TAIPEI"].GetPosition().x + center, m_mapCities["TAIPEI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TOKYO"].GetPosition().x + center, m_mapCities["TOKYO"].GetPosition().y + center);
	m_lines.push_back(line);



	// PARIS (ALGER X, ESSEN X, LONDON X, MADRID X, MILAN X)



	// RIYADH (BAGDAD X, CAIRO X, KARACHI X)



	// SAN FRANCISCO (CHICAGO X, LOS ANGELES X, MANILA X, TOKYO)
	line[0].position = sf::Vector2f(m_mapCities["SAN FRANCISCO"].GetPosition().x + center, m_mapCities["SAN FRANCISCO"].GetPosition().y + center);
	line[1].position = sf::Vector2f(0, m_mapCities["SAN FRANCISCO"].GetPosition().y + center);
	m_lines.push_back(line);
	line[0].position = sf::Vector2f(m_window.getSize().x, m_mapCities["TOKYO"].GetPosition().y + center);
	line[1].position = sf::Vector2f(m_mapCities["TOKYO"].GetPosition().x + center, m_mapCities["TOKYO"].GetPosition().y + center);
	m_lines.push_back(line);



	// SANTIAGO (LIMA X)



	// SAO PAULO (BOGOTA X, BUENOS AIRES X, LAGOS X, MADRID X)



	// SEOUL (BEIJING X, SHANGHAI, TOKYO)
	line[0].position = sf::Vector2f(m_mapCities["SEOUL"].GetPosition().x + center, m_mapCities["SEOUL"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["SHANGHAI"].GetPosition().x + center, m_mapCities["SHANGHAI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TOKYO"].GetPosition().x + center, m_mapCities["TOKYO"].GetPosition().y + center);
	m_lines.push_back(line);



	// SHANGHAI (BEIJING X, HONG KONG X, SEOUL X, TAIPEI, TOKYO)
	line[0].position = sf::Vector2f(m_mapCities["SHANGHAI"].GetPosition().x + center, m_mapCities["SHANGHAI"].GetPosition().y + center);

	line[1].position = sf::Vector2f(m_mapCities["TAIPEI"].GetPosition().x + center, m_mapCities["TAIPEI"].GetPosition().y + center);
	m_lines.push_back(line);

	line[1].position = sf::Vector2f(m_mapCities["TOKYO"].GetPosition().x + center, m_mapCities["TOKYO"].GetPosition().y + center);
	m_lines.push_back(line);



	// ST. PETERSBURG (ESSEN X, ISTANBUL X, MOSCOW X)



	// SYDNEY (JAKARTA X, LOS ANGELES X, MANILA X)



	// TAIPEI (HONG KONG X, MANILA X, OSAKA X, SHANGHAI X)



	// TEHRAN (BAGHDAD X, DELHI X, KARACHI X, MOSCOW X)



	// TOKYO (OSAKA X, SAN FRANCISCO X, SHANGHAI X, SEOUL X)



	// WASHINGTON (ATLANTA X, MIAMI X, MONTREAL X, NEW YORK X)



	/*m_mapCities["ALGER"].AddNeighbourCity("CAIRO", &m_mapCities["CAIRO"]);
	m_mapCities["ALGER"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["ALGER"].AddNeighbourCity("PARIS", &m_mapCities["PARIS"]);
	m_mapCities["ALGER"].AddNeighbourCity("MADRID", &m_mapCities["MADRID"]);

	m_mapCities["ATLANTA"].AddNeighbourCity("CHICAGO", &m_mapCities["CHICAGO"]);
	m_mapCities["ATLANTA"].AddNeighbourCity("MIAMI", &m_mapCities["MIAMI"]);
	m_mapCities["ATLANTA"].AddNeighbourCity("WASHINGTON", &m_mapCities["WASHINGTON"]);

	m_mapCities["BAGDAD"].AddNeighbourCity("CAIRO", &m_mapCities["CAIRO"]);
	m_mapCities["BAGDAD"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["BAGDAD"].AddNeighbourCity("KARACHI", &m_mapCities["KARACHI"]);
	m_mapCities["BAGDAD"].AddNeighbourCity("RIYADH", &m_mapCities["RIYADH"]);
	m_mapCities["BAGDAD"].AddNeighbourCity("TEHRAN", &m_mapCities["TEHRAN"]);

	m_mapCities["BANGKOK"].AddNeighbourCity("CHENNAI", &m_mapCities["CHENNAI"]);
	m_mapCities["BANGKOK"].AddNeighbourCity("KOLKATA", &m_mapCities["KOLKATA"]);
	m_mapCities["BANGKOK"].AddNeighbourCity("HO CHI MINH CITY", &m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["BANGKOK"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);
	m_mapCities["BANGKOK"].AddNeighbourCity("JAKARTA", &m_mapCities["JAKARTA"]);

	m_mapCities["BEIJING"].AddNeighbourCity("SEOUL", &m_mapCities["SEOUL"]);
	m_mapCities["BEIJING"].AddNeighbourCity("SHANGHAI", &m_mapCities["SHANGHAI"]);

	m_mapCities["BOGOTA"].AddNeighbourCity("BUENOS AIRES", &m_mapCities["BUENOS AIRES"]);
	m_mapCities["BOGOTA"].AddNeighbourCity("LIMA", &m_mapCities["LIMA"]);
	m_mapCities["BOGOTA"].AddNeighbourCity("MEXICO CITY", &m_mapCities["MEXICO CITY"]);
	m_mapCities["BOGOTA"].AddNeighbourCity("MIAMI", &m_mapCities["MIAMI"]);
	m_mapCities["BOGOTA"].AddNeighbourCity("SAO PAULO", &m_mapCities["SAO PAULO"]);

	m_mapCities["BUENOS AIRES"].AddNeighbourCity("BOGOTA", &m_mapCities["BOGOTA"]);
	m_mapCities["BUENOS AIRES"].AddNeighbourCity("SAO PAULO", &m_mapCities["SAO PAULO"]);

	m_mapCities["CAIRO"].AddNeighbourCity("ALGER", &m_mapCities["ALGER"]);
	m_mapCities["CAIRO"].AddNeighbourCity("BAGDAD", &m_mapCities["BAGDAD"]);
	m_mapCities["CAIRO"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["CAIRO"].AddNeighbourCity("KHARTOUM", &m_mapCities["KHARTOUM"]);
	m_mapCities["CAIRO"].AddNeighbourCity("RIYADH", &m_mapCities["RIYADH"]);

	m_mapCities["CHENNAI"].AddNeighbourCity("BANGKOK", &m_mapCities["BANGKOK"]);
	m_mapCities["CHENNAI"].AddNeighbourCity("DELHI", &m_mapCities["DELHI"]);
	m_mapCities["CHENNAI"].AddNeighbourCity("JAKARTA", &m_mapCities["JAKARTA"]);
	m_mapCities["CHENNAI"].AddNeighbourCity("KOLKATA", &m_mapCities["KOLKATA"]);
	m_mapCities["CHENNAI"].AddNeighbourCity("MUMBAI", &m_mapCities["MUMBAI"]);

	m_mapCities["CHICAGO"].AddNeighbourCity("ATLANTA", &m_mapCities["ATLANTA"]);
	m_mapCities["CHICAGO"].AddNeighbourCity("LOS ANGELES", &m_mapCities["LOS ANGELES"]);
	m_mapCities["CHICAGO"].AddNeighbourCity("MEXICO CITY", &m_mapCities["MEXICO CITY"]);
	m_mapCities["CHICAGO"].AddNeighbourCity("MONTREAL", &m_mapCities["MONTREAL"]);
	m_mapCities["CHICAGO"].AddNeighbourCity("SAN FRANCISCO", &m_mapCities["SAN FRANCISCO"]);

	m_mapCities["DELHI"].AddNeighbourCity("CHENNAI", &m_mapCities["CHENNAI"]);
	m_mapCities["DELHI"].AddNeighbourCity("KARACHI", &m_mapCities["KARACHI"]);
	m_mapCities["DELHI"].AddNeighbourCity("KOLKATA", &m_mapCities["KOLKATA"]);
	m_mapCities["DELHI"].AddNeighbourCity("MUMBAI", &m_mapCities["TEHRAN"]);
	m_mapCities["DELHI"].AddNeighbourCity("TEHRAN", &m_mapCities["TEHRAN"]);

	m_mapCities["ESSEN"].AddNeighbourCity("LONDON", &m_mapCities["LONDON"]);
	m_mapCities["ESSEN"].AddNeighbourCity("MILAN", &m_mapCities["MILAN"]);
	m_mapCities["ESSEN"].AddNeighbourCity("PARIS", &m_mapCities["PARIS"]);
	m_mapCities["ESSEN"].AddNeighbourCity("ST. PETERSBURG", &m_mapCities["ST. PETERSBURG"]);

	m_mapCities["HO CHI MINH CITY"].AddNeighbourCity("BANGKOK", &m_mapCities["BANGKOK"]);
	m_mapCities["HO CHI MINH CITY"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);
	m_mapCities["HO CHI MINH CITY"].AddNeighbourCity("JAKARTA", &m_mapCities["JAKARTA"]);
	m_mapCities["HO CHI MINH CITY"].AddNeighbourCity("MANILA", &m_mapCities["MANILA"]);

	m_mapCities["HONG KONG"].AddNeighbourCity("BANGKOK", &m_mapCities["BANGKOK"]);
	m_mapCities["HONG KONG"].AddNeighbourCity("HO CHI MINH CITY", &m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["HONG KONG"].AddNeighbourCity("KOLKATA", &m_mapCities["KOLKATA"]);
	m_mapCities["HONG KONG"].AddNeighbourCity("MANILA", &m_mapCities["MANILA"]);
	m_mapCities["HONG KONG"].AddNeighbourCity("SHANGHAI", &m_mapCities["SHANGHAI"]);
	m_mapCities["HONG KONG"].AddNeighbourCity("TAIPEI", &m_mapCities["TAIPEI"]);

	m_mapCities["ISTANBUL"].AddNeighbourCity("ALGER", &m_mapCities["ALGER"]);
	m_mapCities["ISTANBUL"].AddNeighbourCity("BAGHDAD", &m_mapCities["BAGHDAD"]);
	m_mapCities["ISTANBUL"].AddNeighbourCity("CAIRO", &m_mapCities["CAIRO"]);
	m_mapCities["ISTANBUL"].AddNeighbourCity("MILAN", &m_mapCities["MILAN"]);
	m_mapCities["ISTANBUL"].AddNeighbourCity("MOSCOW", &m_mapCities["MOSCOW"]);
	m_mapCities["ISTANBUL"].AddNeighbourCity("ST. PETERSBURG", &m_mapCities["ST. PETERSBURG"]);

	m_mapCities["JAKARTA"].AddNeighbourCity("BANGKOK", &m_mapCities["BANGKOK"]);
	m_mapCities["JAKARTA"].AddNeighbourCity("CHENNAI", &m_mapCities["CHENNAI"]);
	m_mapCities["JAKARTA"].AddNeighbourCity("HO CHI MINH CITY", &m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["JAKARTA"].AddNeighbourCity("SYDNEY", &m_mapCities["SYDNEY"]);

	m_mapCities["JOHANNESBURG"].AddNeighbourCity("KHARTOUM", &m_mapCities["KHARTOUM"]);
	m_mapCities["JOHANNESBURG"].AddNeighbourCity("KINSHASA", &m_mapCities["KINSHASA"]);
	
	m_mapCities["KARACHI"].AddNeighbourCity("BAGHDAD", &m_mapCities["BAGHDAD"]);
	m_mapCities["KARACHI"].AddNeighbourCity("DELHI", &m_mapCities["DELHI"]);
	m_mapCities["KARACHI"].AddNeighbourCity("MUMBAI", &m_mapCities["MUMBAI"]);
	m_mapCities["KARACHI"].AddNeighbourCity("RIYADH", &m_mapCities["RIYADH"]);
	m_mapCities["KARACHI"].AddNeighbourCity("TEHRAN", &m_mapCities["TEHRAN"]);

	m_mapCities["KHARTOUM"].AddNeighbourCity("CAIRO", &m_mapCities["CAIRO"]);
	m_mapCities["KHARTOUM"].AddNeighbourCity("KINSHASA", &m_mapCities["KINSHASA"]);
	m_mapCities["KHARTOUM"].AddNeighbourCity("JOHANNESBURG", &m_mapCities["JOHANNESBURG"]);
	m_mapCities["KHARTOUM"].AddNeighbourCity("LAGOS", &m_mapCities["LAGOS"]);

	m_mapCities["KINSHASA"].AddNeighbourCity("JOHANNESBURG", &m_mapCities["JOHANNESBURG"]);
	m_mapCities["KINSHASA"].AddNeighbourCity("KHARTOUM", &m_mapCities["KHARTOUM"]);
	m_mapCities["KINSHASA"].AddNeighbourCity("LAGOS", &m_mapCities["LAGOS"]);

	m_mapCities["KOLKATA"].AddNeighbourCity("BANGKOK", &m_mapCities["BANGKOK"]);
	m_mapCities["KOLKATA"].AddNeighbourCity("CHENNAI", &m_mapCities["CHENNAI"]);
	m_mapCities["KOLKATA"].AddNeighbourCity("DELHI", &m_mapCities["DELHI"]);
	m_mapCities["KOLKATA"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);

	m_mapCities["LAGOS"].AddNeighbourCity("KHARTOUM", &m_mapCities["KHARTOUM"]);
	m_mapCities["LAGOS"].AddNeighbourCity("KINSHASA", &m_mapCities["KINSHASA"]);
	m_mapCities["LAGOS"].AddNeighbourCity("SAO PAULO", &m_mapCities["SAO PAULO"]);

	m_mapCities["LIMA"].AddNeighbourCity("BOGOTA", &m_mapCities["BOGOTA"]);
	m_mapCities["LIMA"].AddNeighbourCity("MEXICO CITY", &m_mapCities["MEXICO CITY"]);
	m_mapCities["LIMA"].AddNeighbourCity("SANTIAGO", &m_mapCities["SANTIAGO"]);

	m_mapCities["LONDON"].AddNeighbourCity("ESSEN", &m_mapCities["ESSEN"]);
	m_mapCities["LONDON"].AddNeighbourCity("MADRID", &m_mapCities["MADRID"]);
	m_mapCities["LONDON"].AddNeighbourCity("NEW YORK", &m_mapCities["NEW YORK"]);
	m_mapCities["LONDON"].AddNeighbourCity("PARIS", &m_mapCities["PARIS"]);

	m_mapCities["LOS ANGELES"].AddNeighbourCity("MEXICO CITY", &m_mapCities["MEXICO CITY"]);
	m_mapCities["LOS ANGELES"].AddNeighbourCity("SAN FRANCISCO", &m_mapCities["SAN FRANCISCO"]);
	m_mapCities["LOS ANGELES"].AddNeighbourCity("SYDNEY", &m_mapCities["SYDNEY"]);

	m_mapCities["MADRID"].AddNeighbourCity("ALGER", &m_mapCities["ALGER"]);
	m_mapCities["MADRID"].AddNeighbourCity("LONDON", &m_mapCities["LONDON"]);
	m_mapCities["MADRID"].AddNeighbourCity("NEW YORK", &m_mapCities["NEW YORK"]);
	m_mapCities["MADRID"].AddNeighbourCity("PARIS", &m_mapCities["PARIS"]);
	m_mapCities["MADRID"].AddNeighbourCity("SAO PAULO", &m_mapCities["SAO PAULO"]);

	m_mapCities["MANILA"].AddNeighbourCity("HO CHI MINH CITY", &m_mapCities["HO CHI MINH CITY"]);
	m_mapCities["MANILA"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);
	m_mapCities["MANILA"].AddNeighbourCity("SAN FRANCISCO", &m_mapCities["SAN FRANCISCO"]);
	m_mapCities["MANILA"].AddNeighbourCity("SYDNEY", &m_mapCities["SYDNEY"]);
	m_mapCities["MANILA"].AddNeighbourCity("TAIPEI", &m_mapCities["TAIPEI"]);
	
	m_mapCities["MEXICO CITY"].AddNeighbourCity("BOGOTA", &m_mapCities["BOGOTA"]);
	m_mapCities["MEXICO CITY"].AddNeighbourCity("CHICAGO", &m_mapCities["CHICAGO"]);
	m_mapCities["MEXICO CITY"].AddNeighbourCity("LIMA", &m_mapCities["LIMA"]);
	m_mapCities["MEXICO CITY"].AddNeighbourCity("LOS ANGELES", &m_mapCities["LOS ANGELES"]);
	m_mapCities["MEXICO CITY"].AddNeighbourCity("MIAMI", &m_mapCities["MIAMI"]);
	
	m_mapCities["MIAMI"].AddNeighbourCity("ATLANTA", &m_mapCities["ATLANTA"]);
	m_mapCities["MIAMI"].AddNeighbourCity("BOGOTA", &m_mapCities["BOGOTA"]);
	m_mapCities["MIAMI"].AddNeighbourCity("MEXICO CITY", &m_mapCities["MEXICO CITY"]);
	m_mapCities["MIAMI"].AddNeighbourCity("WASHINGTON", &m_mapCities["WASHINGTON"]);
	
	m_mapCities["MILAN"].AddNeighbourCity("ESSEN", &m_mapCities["ESSEN"]);
	m_mapCities["MILAN"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["MILAN"].AddNeighbourCity("PARIS", &m_mapCities["PARIS"]);
	
	m_mapCities["MONTREAL"].AddNeighbourCity("CHICAGO", &m_mapCities["CHICAGO"]);
	m_mapCities["MONTREAL"].AddNeighbourCity("NEW YORK", &m_mapCities["NEW YORK"]);
	m_mapCities["MONTREAL"].AddNeighbourCity("WASHINGTON", &m_mapCities["WASHINGTON"]);
	
	m_mapCities["MOSCOW"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["MOSCOW"].AddNeighbourCity("ST. PETERSBURG", &m_mapCities["ST. PETERSBURG"]);
	m_mapCities["MOSCOW"].AddNeighbourCity("TEHRAN", &m_mapCities["TEHRAN"]);

	m_mapCities["MUMBAI"].AddNeighbourCity("DELHI", &m_mapCities["DELHI"]);
	m_mapCities["MUMBAI"].AddNeighbourCity("CHENNAI", &m_mapCities["CHENNAI"]);
	m_mapCities["MUMBAI"].AddNeighbourCity("KARACHI", &m_mapCities["KARACHI"]);
	
	m_mapCities["NEW YORK"].AddNeighbourCity("LONDON", &m_mapCities["LONDON"]);
	m_mapCities["NEW YORK"].AddNeighbourCity("MADRID", &m_mapCities["MADRID"]);
	m_mapCities["NEW YORK"].AddNeighbourCity("MONTREAL", &m_mapCities["MONTREAL"]);
	m_mapCities["NEW YORK"].AddNeighbourCity("WASHINGTON", &m_mapCities["WASHINGTON"]);

	m_mapCities["OSAKA"].AddNeighbourCity("TAIPEI", &m_mapCities["TAIPEI"]);
	m_mapCities["OSAKA"].AddNeighbourCity("TOKYO", &m_mapCities["TOKYO"]);

	m_mapCities["PARIS"].AddNeighbourCity("ALGER", &m_mapCities["ALGER"]);
	m_mapCities["PARIS"].AddNeighbourCity("ESSEN", &m_mapCities["ESSEN"]);
	m_mapCities["PARIS"].AddNeighbourCity("LONDON", &m_mapCities["LONDON"]);
	m_mapCities["PARIS"].AddNeighbourCity("MADRID", &m_mapCities["MADRID"]);
	m_mapCities["PARIS"].AddNeighbourCity("MILAN", &m_mapCities["MILAN"]);

	m_mapCities["RIYADH"].AddNeighbourCity("BAGHDAD", &m_mapCities["BAGHDAD"]);
	m_mapCities["RIYADH"].AddNeighbourCity("CAIRO", &m_mapCities["CAIRO"]);
	m_mapCities["RIYADH"].AddNeighbourCity("KARACHI", &m_mapCities["KARACHI"]);

	m_mapCities["SAN FRANCISCO"].AddNeighbourCity("CHICAGO", &m_mapCities["CHICAGO"]);
	m_mapCities["SAN FRANCISCO"].AddNeighbourCity("LOS ANGELES", &m_mapCities["LOS ANGELES"]);
	m_mapCities["SAN FRANCISCO"].AddNeighbourCity("MANILA", &m_mapCities["MANILA"]);
	m_mapCities["SAN FRANCISCO"].AddNeighbourCity("TOKYO", &m_mapCities["TOKYO"]);

	m_mapCities["SANTIAGO"].AddNeighbourCity("LIMA", &m_mapCities["LIMA"]);

	m_mapCities["SAO PAULO"].AddNeighbourCity("BOGOTA", &m_mapCities["BOGOTA"]);
	m_mapCities["SAO PAULO"].AddNeighbourCity("BUENOS AIRES", &m_mapCities["BUENOS AIRES"]);
	m_mapCities["SAO PAULO"].AddNeighbourCity("LAGOS", &m_mapCities["LAGOS"]);
	m_mapCities["SAO PAULO"].AddNeighbourCity("MADRID", &m_mapCities["MADRID"]);

	m_mapCities["SEOUL"].AddNeighbourCity("BEIJING", &m_mapCities["BEIJING"]);
	m_mapCities["SEOUL"].AddNeighbourCity("SHANGHAI", &m_mapCities["SHANGHAI"]);
	m_mapCities["SEOUL"].AddNeighbourCity("TOKYO", &m_mapCities["TOKYO"]);

	m_mapCities["SHANGHAI"].AddNeighbourCity("BEIJING", &m_mapCities["BEIJING"]);
	m_mapCities["SHANGHAI"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);
	m_mapCities["SHANGHAI"].AddNeighbourCity("SEOUL", &m_mapCities["SEOUL"]);
	m_mapCities["SHANGHAI"].AddNeighbourCity("TAIPEI", &m_mapCities["TAIPEI"]);
	m_mapCities["SHANGHAI"].AddNeighbourCity("TOKYO", &m_mapCities["TOKYO"]);

	m_mapCities["ST. PETERSBURG"].AddNeighbourCity("ESSEN", &m_mapCities["ESSEN"]);
	m_mapCities["ST. PETERSBURG"].AddNeighbourCity("ISTANBUL", &m_mapCities["ISTANBUL"]);
	m_mapCities["ST. PETERSBURG"].AddNeighbourCity("MOSCOW", &m_mapCities["MOSCOW"]);

	m_mapCities["SYDNEY"].AddNeighbourCity("JAKARTA", &m_mapCities["JAKARTA"]);
	m_mapCities["SYDNEY"].AddNeighbourCity("LOS ANGELES", &m_mapCities["LOS ANGELES"]);
	m_mapCities["SYDNEY"].AddNeighbourCity("MANILA", &m_mapCities["MANILA"]);

	m_mapCities["TAIPEI"].AddNeighbourCity("HONG KONG", &m_mapCities["HONG KONG"]);
	m_mapCities["TAIPEI"].AddNeighbourCity("MANILA", &m_mapCities["MANILA"]);
	m_mapCities["TAIPEI"].AddNeighbourCity("OSAKA", &m_mapCities["OSAKA"]);
	m_mapCities["TAIPEI"].AddNeighbourCity("SHANGHAI", &m_mapCities["SHANGHAI"]);

	m_mapCities["TEHRAN"].AddNeighbourCity("BAGHDAD", &m_mapCities["BAGHDAD"]);
	m_mapCities["TEHRAN"].AddNeighbourCity("DELHI", &m_mapCities["DELHI"]);
	m_mapCities["TEHRAN"].AddNeighbourCity("KARACHI", &m_mapCities["KARACHI"]);
	m_mapCities["TEHRAN"].AddNeighbourCity("MOSCOW", &m_mapCities["MOSCOW"]);

	m_mapCities["TOKYO"].AddNeighbourCity("OSAKA", &m_mapCities["OSAKA"]);
	m_mapCities["TOKYO"].AddNeighbourCity("SAN FRANCISCO", &m_mapCities["SAN FRANCISCO"]);
	m_mapCities["TOKYO"].AddNeighbourCity("SHANGHAI", &m_mapCities["SHANGHAI"]);
	m_mapCities["TOKYO"].AddNeighbourCity("SEOUL", &m_mapCities["SEOUL"]);
	
	m_mapCities["WASHINGTON"].AddNeighbourCity("ATLANTA", &m_mapCities["ATLANTA"]);
	m_mapCities["WASHINGTON"].AddNeighbourCity("MIAMI", &m_mapCities["MIAMI"]);
	m_mapCities["WASHINGTON"].AddNeighbourCity("MONTREAL", &m_mapCities["MONTREAL"]);
	m_mapCities["WASHINGTON"].AddNeighbourCity("NEW YORK", &m_mapCities["NEW YORK"]);*/
}

bool GameState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
	return true;
}

void GameState::rendBackground()
{
	m_window.draw(m_sprites["background"]);
}

void GameState::rendBlueRound()
{
	m_window.draw(m_rounds["blue_round"]);
}

void GameState::rendRedRound()
{
	m_window.draw(m_rounds["red_round"]);
}

void GameState::rendYellowRound()
{
	m_window.draw(m_rounds["yellow_round"]);
	m_window.draw(m_rounds["black_round"]);
}

void GameState::rendCities()
{
	for (int index = 0; index < m_cities.size(); index++)
		m_cities[index].Rend(m_window);
}

void GameState::rendStatsTableBoard()
{
	m_statsTableBoard.Rend(m_window);
}

void GameState::rendActionBoard()
{
	m_actionBoard.render(m_window);
}

void GameState::rendCityConnections()
{
	for (int line = 0; line < m_lines.size(); line++)
	{
		m_window.draw(m_lines[line]);
	}
}

void GameState::updateBlueRounds()
{
	//for (int index = 0; index < m_blueRounds.size(); index++)
	//	if (index == 0)
	//		m_blueRounds[index].setPosition(100, 100);
}

void GameState::updateActionBoard()
{
	m_actionBoard.update(m_window);
}
