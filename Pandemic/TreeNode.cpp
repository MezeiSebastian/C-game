#include "TreeNode.h"

TreeNode::TreeNode(int16_t layer, int16_t nextCardProbability, int16_t numberOfVirusesRemaining, int16_t numberOfRemainingCards) :
	m_layer(layer),
	m_nextCardProbability(nextCardProbability),
	m_numberOfVirusesRemaining(numberOfVirusesRemaining),
	m_numberOfCardsRemaining(numberOfRemainingCards)

{}

const int16_t TreeNode::GetLayer() const
{
	return m_layer;
}

const int16_t TreeNode::GetNextCardProbability() const
{
	return m_nextCardProbability;
}

const int16_t TreeNode::GetNumberOfViruses() const
{
	return m_numberOfVirusesRemaining;
}

const int16_t TreeNode::GetNumberOfCards() const
{
	return m_numberOfCardsRemaining;
}

const TreeNode& TreeNode::GetLeftSibling() const
{
	return *m_leftSibling
}

const TreeNode& TreeNode::GetRightSibling() const
{
	return *m_rightSibling
}

void TreeNode::SetLeftSibling()
{
	m_leftSibling=std::make_unique<TreeNode>();
}

void TreeNode::SetRightSibling()
{
	m_rightSibling = std::make_unique<TreeNode>();
}

bool TreeNode::MakeDecision() const 
{
	//To be implemented
	return;
}
