#pragma once
#include"BoardData.h"
#include"EVirus.h"
#include"Player.h"
#include"Input.h"

class ConsoleGraphics
{
public:
	void InitGameScreen(Input& userInput);
	void DisplayBoard(const BoardData& board,const std::vector<Player>& allPlayers) const;
};

