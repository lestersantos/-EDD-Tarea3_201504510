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

	cout << "Insert Kraken" << endl;
	searchTree->insert("kraken");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << "Insert kraken,dina,apple,era,zira,homero,moe,bart" << endl;
	searchTree->insert("kraken");
	searchTree->insert("dina");
	searchTree->insert("apple");
	searchTree->insert("era");
	searchTree->insert("zira");
	searchTree->insert("homero");
	searchTree->insert("moe");
	searchTree->insert("bart");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << endl;

	/*cout << "delete moe" << endl;
	searchTree->deleteNode("moe");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();

	cout << endl;

	cout << "delete homero" << endl;
	searchTree->deleteNode("homero");

	cout << endl;

	cout << "print in order" << endl;
	searchTree->showInorder();
	*/

	cout << "delete kraken" << endl;
	searchTree->deleteNode("kraken");

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
