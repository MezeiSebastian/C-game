#include "Player.h"
#include<iostream>
#include<algorithm>








bool Player::FerryMove(City& nextCity) {

	if (this->GetCurentCity().FindNeibours(nextCity)) {
		this->SetCity(nextCity);
	}
	else {
		return false;
	}
}

bool Player::FlightMove(City& nextCity) { 

	if (this->DiscardCard(nextCity)) {
		this->SetCity(nextCity);
	}
	else {
		return false;
	}


}

bool Player::CharterMove(City& nextCity) { //City&

	if (this->DiscardCard(GetCurentCity())) {
		this->SetCity(nextCity);
	}
	else {
		return false;
	}

}

bool Player::ShuttleMove(City& nextCity) { //City&

	if (this->GetCurentCity().GetResearchStationStatus() && nextCity.GetResearchStationStatus()) {
		this->SetCity(nextCity);
	}
	else {
		return false;
	}



}

bool Player::BuildResearchStation() {
	if (this->DiscardCard(GetCurentCity())) {
		this->GetCurentCity().SetResearchStation(true);
	} 
	else{
		return false;
	}

}

bool Player::TreatDesease(const EVirus virus) {

	if (this->GetPlayerRole() == 4) {
		if (GetCurentCity().GetNumberOfViruses(virus) != 0) {
			this->GetCurentCity().SetDisease(virus,0);
		}
	}
	else {
		if (GetCurentCity().GetNumberOfViruses(virus) != 0) {
			this->GetCurentCity().ReduceDiseases(virus);
		}
		else {
			return false;
		}
	}

}

bool Player::ShareKnowledge(const Player& p2,CityCard&& c1) {// Player obj, SelectedCard

	if (GetCurentCity().GetCityName() == p2.GetCurentCity().GetCityName())
	{
		this->AddCityCard(std::move(c1));
	}
	else {
		return false;
	}
}

bool Player::DiscoverCure(EVirus virus) {

	auto count = 0;
	for (auto i = 0; i < GetNumOfCityCards(); ++i) {
		if (GetCard(i).GetVirus() == virus) {
			++count;
		}
	}
	if (this->GetPlayerRole() == 7) {
		if (count >4) {

			for (auto i = 0; i < GetNumOfCityCards(); ++i)
				if (GetCard(i).GetVirus() == virus) {
					if (count) {

						this->DeleteCard(GetCard(i));
					}
				}

		}
	}
	else {
		if (count > 5) {

			for (auto i = 0; i < GetNumOfCityCards(); ++i)
				if (GetCard(i).GetVirus() == virus) {
					if (count) {

						this->DeleteCard(GetCard(i));
					}
				}

		}
		else {
			return false;
		}
	}
}
