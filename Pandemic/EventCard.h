#pragma once
#include<iostream>
class EventCard
{
private:
	int16_t m_cardId = 0;
public:
	
	EventCard(int cardId) :
		m_cardId(m_cardId)
	{}
	int GetId() {
		return m_cardId;
	}
};

