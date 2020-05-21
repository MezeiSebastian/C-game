#include "Input.h"
#include<iostream>

const EVirus Input::GetVirus() const
{
	return m_selectedVirus;
}

City& Input::GetCity(BoardData& board)
{
	 return board.GetCity(m_inputCity);
	
}

void Input::SetVirus()
{
	auto intermediar = 0;
	std::cin >> intermediar;
	if (intermediar == 1) {
		m_selectedVirus = EVirus::BlackVirus;
	}
	else if (intermediar == 2) {
		m_selectedVirus = EVirus::BlueVirus;
	}
	else if (intermediar == 3) {
		m_selectedVirus = EVirus::RedVirus;
	}
	else {
		m_selectedVirus = EVirus::YellowVirus;
	}
}

void Input::SetPlayerNumber()
{
	std::cout << "The player to whom you want to give the card";
	std::cin >> m_playerNumber;
}

void Input::SetCard()
{
	std::cout << "The card you want to give away is?\n";
	std::cin >> m_selectedCard;
}

void Input::ChooseInput()
{
	auto intermediaryInput = 0;
	auto intermediaryPlayerNumber = 0;
	auto intermediaryCityName = 0;
	
	
	
	std::cout << "Read Player Action" << "\n";
	std::cin >> intermediaryInput;
	
	
	if(intermediaryInput==1){
		std::cout << "Read City Name" << "\n";
		std::cin >> intermediaryCityName;
		m_action = 1;
		m_inputCity = intermediaryCityName;
	}else if(intermediaryInput==2){
		std::cout << "Read City Name" << "\n";
		std::cin >> intermediaryCityName;
		m_action = 2;
		m_inputCity = intermediaryCityName;
	}else if(intermediaryInput==3){
		std::cout << "Read City Name" << "\n";
		std::cin >> intermediaryCityName;
		m_action = 3;
		m_inputCity = intermediaryCityName;
	}
	else if(intermediaryInput==4){
		std::cout << "Read City Name" << "\n";
		std::cin >> intermediaryCityName;
		m_action = 4;
		m_inputCity = intermediaryCityName;
	}else if(intermediaryInput==5)
	{
		m_action = 5;
	}
	else if(intermediaryInput==6) {
		m_action = 6;
	}
	else if(intermediaryInput==7) {
		m_action = 7;
		//m_playerNumber = intermediaryPlayerNumber;
	}
	else if(intermediaryInput==8) {
		m_action = 8;
	}
	system("cls");
}



void Input::PrintInput() const {
	std::cout << m_action;
	std::cout << m_inputCity;
	std::cout << m_playerNumber;
	std::cin.get();
	
}