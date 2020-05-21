#include "DecisionTree.h"

DecisionTree::DecisionTree(){
	
	m_root = std::make_unique<TreeNode>();
}

void DecisionTree::GenerateNode()
{
	m_root->SetLeftSibling();
	m_root->SetRightSibling();

}

void DecisionTree::NextNode()
{
	if (m_root->MakeDecision()) {
		m_root = m_root->SetLeftSibling();
	}
	else {
		m_root = m_root->SetRightSibling();
	}
	
}
