#pragma once
#include <iostream>
#include <cstdio>
#include <fstream>
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
	void graphTree(string nameFile);
};

class Node {
public:
	Node(AbbNode* data) 
	{ 
		this->data = data;
		this->next = nullptr;
		this->previous = nullptr;
	}
	AbbNode* data;
	Node* previous;
	Node* next;
};

class Queue {
public:
	Queue() 
	{
		this->front = nullptr;
		this->rear = nullptr;
	}
	Node* front;
	Node* rear;
	void enqueue(AbbNode* data);
	Node* dequeue();
	bool isEmpty();
	void emptyQueue();
};


void Queue::enqueue(AbbNode* data)
{
	Node* newNode = new Node(data);

	if (this->rear == nullptr)
	{
		this->rear = this->front = newNode;
	}
	else
	{
		this->rear->next = newNode;
		this->rear = newNode;
	}
}

Node* Queue::dequeue()
{
	Node* temp = this->front;

	if (this->isEmpty())
	{
		cout << "The Queue is Emtpy,err Queue underflow" << endl;
	}
	else
	{
		if (this->front == this->rear)
		{
			this->rear = this->front = this->front->next;
		}
		else
		{
			this->front = this->front->next;
		}
	}
	return temp;
}

bool Queue::isEmpty()
{

	if (this->rear == nullptr and this->front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::emptyQueue()
{
	while (this->isEmpty()!= true)
	{
		this->dequeue();
	}
}

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

void AbbTree::graphTree(string nameFile)
{
	Queue* breadthQueue = new Queue();
	string auxTxtFile = "";

	ofstream txtFile;
	txtFile.open(nameFile+".txt");

	txtFile << "digraph tree{" << endl;
	txtFile << endl;

	txtFile << "rankdir = TB;" << endl;
	txtFile << "node [shape = record]" << endl;
	txtFile << "splines = polyline" << endl;
	txtFile << endl;

	breadthQueue->enqueue(this->root);

	while (breadthQueue->isEmpty() == false)
	{
		Node* currentNode = breadthQueue->dequeue();

		auxTxtFile += currentNode->data->data+"[label = \"<l>|";
		auxTxtFile +="<d>"+currentNode->data->data+"|<r>\"]\n";

		if (currentNode->data->leftNode != nullptr)
		{
			breadthQueue->enqueue(currentNode->data->leftNode);
		}

		if (currentNode->data->rightNode != nullptr)
		{
			breadthQueue->enqueue(currentNode->data->rightNode);
		}
	}

	breadthQueue->emptyQueue();

	breadthQueue->enqueue(this->root);

	txtFile << auxTxtFile;
	txtFile << endl;
	auxTxtFile = "";

	while (breadthQueue->isEmpty() == false)
	{
		Node* currentNode = breadthQueue->dequeue();

		if (currentNode->data->leftNode != nullptr)
		{
			breadthQueue->enqueue(currentNode->data->leftNode);

			auxTxtFile += currentNode->data->data + ":l";
			auxTxtFile += "->";
			auxTxtFile += currentNode->data->leftNode->data + "\n";
		}

		if (currentNode->data->rightNode != nullptr)
		{
			breadthQueue->enqueue(currentNode->data->rightNode);

			auxTxtFile += currentNode->data->data + ":r";
			auxTxtFile += "->";
			auxTxtFile += currentNode->data->rightNode->data + "\n";
		}
	}

	txtFile << auxTxtFile;
	breadthQueue->emptyQueue();
	txtFile << endl;
	txtFile << "}" << endl;
	txtFile.close();

	string strSystem = "\"dot -Tpng " + nameFile +".txt"+ " -o"+nameFile+".png";
	system(strSystem.c_str());
}
