#include "StatsTableBoard.h"

StatsTableBoard::StatsTableBoard()
{
	m_numberBlackVirus = 24;
	m_numberBlueVirus = 24;
	m_numberRedVirus = 24;
	m_numberYellowVirus = 24;
	m_numberOfResearchStations = 5;

	initBlackBox();

	initYellowVirus();
	initRedVirus();
	initBlueVirus();
	initGreyVirus();
	initResearchStation();

	initDecks();

	initFont();

	initInfectionRateText();
}

void StatsTableBoard::Rend(sf::RenderTarget& target)
{
	target.draw(m_blackBoxAddPlayer);

	m_yellowVirus->Render(target);
	m_redVirus->Render(target);
	m_blueVirus->Render(target);
	m_greyVirus->Render(target);
	m_researchStation->Render(target);

	m_deck->Render(target);
	m_deck2->Render(target);

	target.draw(m_text_InfectionRate);
}

void StatsTableBoard::DecreaseYellowVirus()
{
	m_numberYellowVirus--;
	m_yellowVirus->SetString(std::to_string(m_numberYellowVirus));
}

void StatsTableBoard::DecreaseRedVirus()
{
	m_numberRedVirus--;
	m_redVirus->SetString(std::to_string(m_numberRedVirus));
}

void StatsTableBoard::DecreaseBlueVirus()
{
	m_numberBlueVirus--;
	m_blueVirus->SetString(std::to_string(m_numberBlueVirus));
}

void StatsTableBoard::DecreaseBlackVirus()
{
	m_numberBlackVirus--;
	m_greyVirus->SetString(std::to_string(m_numberBlackVirus));
}

void StatsTableBoard::DecreaseResearchStations()
{
	m_numberOfResearchStations--;
	m_researchStation->SetString(std::to_string(m_numberOfResearchStations));
}

void StatsTableBoard::AddYellowVirus()
{
	m_numberYellowVirus++;
	m_yellowVirus->SetString(std::to_string(m_numberYellowVirus));
}

void StatsTableBoard::AddRedVirus()
{
	m_numberRedVirus++;
	m_redVirus->SetString(std::to_string(m_numberRedVirus));
}

void StatsTableBoard::AddBlueVirus()
{
	m_numberBlueVirus++;
	m_blueVirus->SetString(std::to_string(m_numberBlueVirus));
}

void StatsTableBoard::AddBlackVirus()
{
	m_numberBlackVirus++;
	m_greyVirus->SetString(std::to_string(m_numberBlackVirus));
}

void StatsTableBoard::AddResearchStations()
{
	m_numberOfResearchStations++;
	m_researchStation->SetString(std::to_string(m_numberOfResearchStations));
}

int StatsTableBoard::getNumberOFResearchStations()
{
	return m_numberOfResearchStations;
}

void StatsTableBoard::SetYellowEradicated()
{
	m_numberYellowVirus = 0;
}

void StatsTableBoard::SetYellowVirusTexture(const std::string& pathTexture)
{
	m_yellowVirus->SetTexture(pathTexture);
}

void StatsTableBoard::SetRedVirusTexture(const std::string& path)
{
	m_redVirus->SetTexture(path);
}

void StatsTableBoard::SetBlueVirusTexture(const std::string& path)
{
	m_blueVirus->SetTexture(path);
}

void StatsTableBoard::SetBlackVirusTexture(const std::string& path)
{
	m_blueVirus->SetTexture(path);
}

void StatsTableBoard::initBlackBox()
{
	m_blackBoxAddPlayer.setFillColor(sf::Color::Black);
	m_blackBoxAddPlayer.setSize(sf::Vector2f(776,203));
	m_blackBoxAddPlayer.setPosition(sf::Vector2f(575,0));
	m_blackBoxAddPlayer.setOutlineThickness(4);
	m_blackBoxAddPlayer.setOutlineColor(sf::Color::White);
}

void StatsTableBoard::initYellowVirus()
{
	m_yellowVirus = new StatsVirusBoard("Res//Square//YellowVirus.jpg");

	m_yellowVirus->SetPosition(sf::Vector2f(760, 10));

	m_yellowVirus->SetScale(0.05, 0.05);
}

void StatsTableBoard::initRedVirus()
{
	m_redVirus = new StatsVirusBoard("Res//Square//RedVirus.jpg");

	m_redVirus->SetPosition(sf::Vector2f(m_yellowVirus->GetPosition().x + 85, m_yellowVirus->GetPosition().y));

	m_redVirus->SetScale(0.05, 0.05);
}

void StatsTableBoard::initBlueVirus()
{
	m_blueVirus = new StatsVirusBoard("Res//Square//BlueVirus.jpg");

	m_blueVirus->SetPosition(sf::Vector2f(m_redVirus->GetPosition().x + 85, m_redVirus->GetPosition().y));

	m_blueVirus->SetScale(0.05, 0.05);
}

void StatsTableBoard::initGreyVirus()
{
	m_greyVirus = new StatsVirusBoard("Res//Square//BlackVirus.jpg");

	m_greyVirus->SetPosition(sf::Vector2f(m_blueVirus->GetPosition().x + 85, m_blueVirus->GetPosition().y));

	m_greyVirus->SetScale(0.05, 0.05);
}

void StatsTableBoard::initResearchStation()
{
	m_researchStation = new StatsVirusBoard("Res//Square//ResearchStation.png");

	m_researchStation->SetPosition(sf::Vector2f(m_greyVirus->GetPosition().x + 85, m_greyVirus->GetPosition().y));

	m_researchStation->SetScale(0.05, 0.05);

	m_researchStation->SetString(std::to_string(m_numberOfResearchStations));
}

void StatsTableBoard::initDecks()
{
	m_deck = new StatsDeckBoard("Res//Cards//PlayerCardBackSide.png");

	m_deck->SetPosition(sf::Vector2f(m_yellowVirus->GetPosition().x - 150, m_yellowVirus->GetPosition().y + 15));

	m_deck2 = new StatsDeckBoard("Res//Cards//InfectionCardBackSide.png");

	m_deck2->SetPosition(sf::Vector2f(m_greyVirus->GetPosition().x + 320, m_greyVirus->GetPosition().y + 50));

	m_deck2->Rotate(90);
}

void StatsTableBoard::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void StatsTableBoard::initInfectionRateText()
{
	//m_text_InfectionRate.setFont(m_font);

	//m_text_InfectionRate.setString("Infection Rate");

	//m_text_InfectionRate.setPosition(870,70);

	//m_text_InfectionRate.setColor(sf::Color::Green);

	//m_text_InfectionRate.setCharacterSize(25);
}
