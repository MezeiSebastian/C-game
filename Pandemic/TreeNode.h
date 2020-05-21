#pragma once
#include<iostream>
#include<memory>
class TreeNode
{
private:
	int16_t m_layer;
	int16_t m_nextCardProbability;
	int16_t m_numberOfVirusesRemaining;
	int16_t m_numberOfCardsRemaining;
	std::unique_ptr<TreeNode> m_leftSibling, m_rightSibling;
public:
	TreeNode(int16_t layer, int16_t nextCardProbability, int16_t numberOfVirusesRemaining,int16_t numberOfRemainingCards);
	const int16_t GetLayer() const;
	const int16_t GetNextCardProbability() const;
	const int16_t GetNumberOfViruses() const;
	const int16_t GetNumberOfCards() const;
	const TreeNode& GetLeftSibling() const;
	const TreeNode& GetRightSibling() const;

	void SetLeftSibling();
	void SetRightSibling();

	bool MakeDecision() const ;


};

