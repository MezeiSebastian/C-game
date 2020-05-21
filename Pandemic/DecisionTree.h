#pragma once
#include"TreeNode.h"
#include<memory>
class DecisionTree
{
private:
	std::unique_ptr<TreeNode> m_root;
	int16_t firstNode=0;


public:
	DecisionTree();
	void GenerateNode();
	void NextNode();
	void PrintTree() const;

};

