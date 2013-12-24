// Задача №5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cycledList.h"

using namespace std;


int main()
{
	cout << "Cycled List problem" << endl;
	cout << "Enter the size of your list" << endl;
	int n = 0;
	cin >> n;
	cout << "Enter the size of step" << endl;
	int k = 0; 
	cin >> k;
	List *list = new List;
	ListElement *elem = new ListElement;
	elem->value = 1;
	elem->next = nullptr;
	list->first = elem;
	//createList(list);

	for (int i = n; i > 1; i--)
	{
		addElement(list, i);
	}

	cout << endl;
	printList(list);
	cout << endl;
	int p = 0;

	for (int i = n; i > 0; i--)
	{
		printList(list);
		cout << endl;
		cout << (p + i - n) % i << endl;
		removeElement(list, (p + i - n) % i);
		p += k;
		cout << endl;
	}
	cin >> n;
	delete list->first;
	delete list;
	return 0;
}

