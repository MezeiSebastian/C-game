#include "ConsoleGraphics.h"
#include "Input.h"



void ConsoleGraphics::InitGameScreen(Input& userInput)
{
	auto numberOfPlayers = 0;
	std::cout << "PANDEMIC\n";
	std::cout << "The game has started;\n";
	std::cout << "Select the number of Players:\n";
	std::cin >> numberOfPlayers;
	userInput.SetNumberOfPlayers(numberOfPlayers);
	std::cout << "The roles in the game are:\n"
		<< "1.CONTINGENCY PLANNER \n"
		<< "2.OPERATIONS EXPERT \n"
		<< "3.DISPATCHER \n"
		<< "4.MEDIC \n"
		<< "5.QUARANTINE SPECIALIST \n"
		<< "6.RESEARCHER \n"
		<< "7.SCIENTIST \n";

	auto playerRole = 0;
	for (int i = 0; i < numberOfPlayers; ++i) {
		std::cout << "Select Player's " << i << " Role:";
		std::cin >> playerRole;
		userInput.AddPlayerRole(playerRole);
	}
	
	system("cls");
}

void ConsoleGraphics::DisplayBoard(const BoardData& board,const std::vector<Player>& allPlayers) const
{	
	
	auto index = 0;
	for (auto it : board.GetCities()) {
		++index;
		std::cout << "[" << it.GetCityId()-1 << "," << it.GetCityName() << "]"
			<< "[" << it.GetNumberOfViruses(EVirus::BlackVirus) << "," << it.GetNumberOfViruses(EVirus::BlueVirus) << "," <<
			it.GetNumberOfViruses(EVirus::RedVirus) << "," << it.GetNumberOfViruses(EVirus::YellowVirus) << "]"
			<< "[" << it.GetResearchStationStatus() << "]";
		if (index % 4 == 0) {
			std::cout << "\n";
		}
		for (auto i = 0; i < allPlayers.size(); ++i) {
			if (allPlayers[i].GetCurentCity().GetCityName() == it.GetCityName()) {
				std::cout << "[" << allPlayers[i].GetPlayerName() << "]\n";
			}
		}
		
		std::cout<< "      " <<"\n";
	}
	
	std::cout << "1.Ferry Move " << "2.Flight Move " << "3.CharterMove " << "4.ShuttleMove\n" << "5.BuildResearchStation " << "6.TreatDisease " << "7.ShareKnowledge " << "8.DiscoverCure\n";
	
	
}
