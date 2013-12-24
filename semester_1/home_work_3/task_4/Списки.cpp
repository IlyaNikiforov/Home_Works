// Списки.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
#include "list.h"

using namespace std;

enum command 
{
	add = 1,
	removeEl,
	print,
	removeLi,
};

bool isCorrectInput(int n)
{
	return ((n == add) || (n == removeEl) || (n == print) || (n == removeLi));
	
}

int main()
{
	cout << "Dynamic array sorting" << endl;
	List *list = new List;
	createList(list);
	int n = 1;
	while (isCorrectInput(n))
	{
		cout << "What would you like to do?" << endl;
		cout << "1: add an element to your array" << endl;
		cout << "2: delete an element from your array" << endl;
		cout << "3: Print your array" << endl;
		cout << "4: clear your array" << endl;
		cout << "Everything else: exit" << endl;
		cin >> n;
		system("cls");

		if (n == add)
		{	
			cout << "Enter your new element:" << endl;
			int k = 0;
			cin >> k;
			addElement(list, k);
		}

		else if (n == removeEl)
		{
			cout << "Enter the element, which you want to delete" << endl;
			int k = 0; 
			cin >> k;
			removeElement(list, k);
		}

		else if (n == print)
			printList(list);

		else if (n == removeLi)
			removeList(list);
		
		cout << endl <<  "It is done!" << endl;
		cout << endl;
	}

	removeList(list);
	delete list->first;
	delete list;
	cin >> n;
	return 0;
}

