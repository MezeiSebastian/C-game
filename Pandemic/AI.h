#pragma once
#include"Player.h"
#include"BoardData.h"
#include"Deck.h"

//enum OutbreakThreat {
//	LowOut,
//	Average,
//	High
//};
//
//enum VirusesLoss {
//	Low,
//	Average,
//	High
//};
//
//enum CardsLoss {
//	Low,
//	Average,
//	High
//};
//
//enum ResearchStations {
//	Low,
//	Average,
//	High
//};
//
//enum InfectionRate {
//	Low,
//	Average,
//	High
//};
//
//enum OutbreakLoss {
//	Low,
//	Average,
//	High
//};
//
//enum InfectionChance {
//	Low,
//	Average,
//	High
//};

class AI
{
private:
	std::array<int, 7> predictions{ -1 };
public:
	void MakePrediction(BoardData& board, Player& player, Deck& infectionDeck); 
	void FitnessFunction(BoardData& board, Player& player, Deck& infectionDeck);
	void SmartSearch();
	void GenerateText(int numberOfPrediction, int predictionNumber);

	void PrintOutput(std::string& finalMessage);
	
	
};

