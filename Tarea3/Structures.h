#pragma once
#include <iostream>
#include <cstdio>
using namespace std;

class AbbNode
{
public:
	AbbNode(string data)
	{
		this->data = data;
		this->leftNode = nullptr;
		this->rightNode = nullptr;
	}
	AbbNode* leftNode;
	AbbNode* rightNode;
	string data;
	void printData();
};

void AbbNode::printData()
{
	cout << " " << this->data << " ->";
}

class AbbTree
{
	bool insert(string data,AbbNode* currentRoot);
	AbbNode* deleteNode(string data,AbbNode* currentRoot);
	AbbNode* changeToGreaterFromSmallers(AbbNode* currentRoot);
public:
	AbbTree() 
	{
		this->root = nullptr;
	}
	AbbNode* root;
	void insert(string data);
	void deleteNode(string data) { this->root = deleteNode(data,this->root); }
	void showInorder() { if (this->root == nullptr) { cout << "Empty Tree" << endl; } else { inorder(this->root); cout << endl; }}
	void inorder(AbbNode* currentRoot);
};

void AbbTree::insert(string data)
{
	insert(data,this->root);
}

bool AbbTree::insert(string data,AbbNode* currentRoot)
{
	if (this->root == nullptr)
	{
		this->root = new AbbNode(data);
		return true;
	}
	else if (data < currentRoot->data)
	{
		if (currentRoot->leftNode == nullptr)
		{
			AbbNode* newNode = new AbbNode(data);
			currentRoot->leftNode = newNode;
			return true;
		}
		else
		{
			return insert(data, currentRoot->leftNode);
		}
	}
	else if (data > currentRoot->data)
	{
		if (currentRoot->rightNode == nullptr)
		{
			AbbNode* newNode = new AbbNode(data);
			currentRoot->rightNode = newNode;
			return true;
		}
		else
		{
			return insert(data, currentRoot->rightNode);
		}
	}
	else
	{
		return false;
	}
}

void AbbTree::inorder(AbbNode* currentNode)
{
	if (currentNode != nullptr)
	{
		inorder(currentNode->leftNode);
		currentNode->printData();
		inorder(currentNode->rightNode);
	}
}

AbbNode* AbbTree::deleteNode(string data,AbbNode* currentNode)
{
	if (currentNode == nullptr)
	{
		cout << "Error data not found" << endl;
		return false;
	}
	else if (data < currentNode->data)
	{
		AbbNode* leftNode;
		leftNode = deleteNode(data,currentNode->leftNode);
		currentNode->leftNode = leftNode;
	}
	else if (data > currentNode->data)
	{
		AbbNode* rightNode;
		rightNode = deleteNode(data,currentNode->rightNode);
		currentNode->rightNode = rightNode;
	}
	else
	{
		AbbNode* eliminateNode;
		eliminateNode = currentNode;
		if (currentNode->leftNode == nullptr)
		{
			currentNode = currentNode->rightNode;
		}
		else if (currentNode->rightNode == nullptr)
		{
			currentNode = currentNode->leftNode;
		}
		else
		{
			eliminateNode = changeToGreaterFromSmallers(currentNode);
		}
		eliminateNode = nullptr;
	}
	return currentNode;
}

AbbNode* AbbTree::changeToGreaterFromSmallers(AbbNode* currentRoot)
{
	AbbNode* previousNode, *currentNode;

	previousNode = currentRoot;
	currentNode = currentRoot->leftNode;

	while (currentNode->rightNode != nullptr)
	{
		previousNode = currentNode;
		currentNode = currentNode->rightNode;
	}

	currentRoot->data = currentNode->data;

	if (previousNode == currentRoot)
	{
		previousNode->leftNode = currentNode->leftNode;
	}
	else
	{
		previousNode->rightNode = currentNode->leftNode;
	}
	return currentNode;
}