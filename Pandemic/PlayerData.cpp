#include "PlayerData.h"



PlayerData::PlayerData(const std::string playerName, const int16_t playerNumber,City& originalCity,int16_t playerRole):
	m_playerName(playerName),
	m_playerNumber(playerNumber),
	m_actions(0),
	m_currentCity(&originalCity),
	m_playerRole(playerRole)
{}


const int PlayerData::GetPlayerRole()
{
	return m_playerRole;
}

const std::string PlayerData::GetPlayerName() const{
	return this->m_playerName;
}
const int16_t PlayerData::GetPlayerNumber() const {
	return this->m_playerNumber;
}
const int16_t PlayerData::GetNumOfActions() const {
	return this->m_actions;
}
City& PlayerData::GetCurentCity() const {
	return *m_currentCity;
}
const size_t PlayerData::GetNumOfCityCards() const {
	return this->m_cityCards.size();
}
void PlayerData::SetActions(int16_t actions) {
	this->m_actions = actions;
}
void PlayerData::SetCity(City& city) {
	this->m_currentCity = &city;
}
void PlayerData::AddCityCard(CityCard&& cityCard) {
	m_cityCards.emplace_back(cityCard);
}
void PlayerData::AddCityCard(const CityCard& cityCard)
{
	m_cityCards.emplace_back(cityCard);
}
const CityCard& PlayerData::GetCard(int index) const
{
	return m_cityCards.at(index);
}
void PlayerData::AddEventCard(EventCard&& eventCard)
{
	m_eventCards.emplace_back(eventCard);
}
const EventCard PlayerData::GetEventCard(int CardNumber) const
{
	return m_eventCards.at(CardNumber);
}
void PlayerData::DeleteCard(const CityCard& Card)
{
	std::remove_if(m_cityCards.begin(), m_cityCards.end(), [&](CityCard& card) { return Card.GetVirus() == card.GetVirus(); });
}
const bool PlayerData::DiscardCard(const City& city) {
	int8_t size = m_cityCards.size();
	auto pred = [city](CityCard& intermediary) {return intermediary.GetCityName() == city.GetCityName(); };
	auto newEnd=std::remove_if(m_cityCards.begin(), m_cityCards.end(),pred);
	m_cityCards.erase(newEnd, m_cityCards.end());
	if (m_cityCards.size() != size) {
		return true;
	}
	return false;
}

