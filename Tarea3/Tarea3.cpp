// Tarea3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include "Structures.h"

using namespace std;

AbbTree* searchTree;
int main()
{
	cout << "\t ----- Tarea 3 -----"<< endl;
	searchTree = new AbbTree();

	cout << "print in order" << endl;
	searchTree->showInorder();
	
	cout << endl;

	cout << "Insert luigi" << endl;
	searchTree->insert("luigi");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << "Insert luigi,hammer,mario,peach,pow,fermim" << endl;
	searchTree->insert("luigi");
	searchTree->insert("hammer");
	searchTree->insert("mario");
	searchTree->insert("peach");
	searchTree->insert("pow");
	searchTree->insert("fermim");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << endl;

	cout << "delete peach" << endl;
	searchTree->deleteNode("peach");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << endl;

	cout << "insert shy_guy,edd" << endl;
	searchTree->insert("shy_guy");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();
	

	cout << "delete pow" << endl;
	searchTree->deleteNode("pow");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << "insert Boo,Kamek, star, whomp" << endl;
	searchTree->insert("Boo");
	searchTree->insert("Kamek");
	searchTree->insert("star");
	searchTree->insert("whomp");
	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << "delete shy_guy" << endl;
	searchTree->deleteNode("shy_guy");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << endl;

	cout << "delete mario" << endl;
	searchTree->deleteNode("mario");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
