#include "iostream"
#include "list.h"
#include "pylonimal.h"

using namespace std;

enum command
{
	doCreate,
	doAdd,
	doValue,
	isEqual
};

bool isCommand (int temp)
{
	return (temp >= command::doCreate && temp <= command::isEqual);
}

int main()
{
	cout << "Pylominal problem" << endl;
	int temp = 0;
	List *pyl = createList();

	while (isCommand(temp))
	{
		cout << "what would you like to do?" << endl;
		cout << "0: create pylnimal" << endl;
		cout << "1: add one more pylonimal to exciting" << endl;
		cout << "2: calculate the value of pylonimal at" << endl;
		cout << "3: check the equality of pylonimals" << endl;
		cout << "everything else: exit" << endl;

		cin >> temp;

		if (temp == command::doCreate)
		{
			cout << "enter new elements of pylonimal like this: 'value' (space) 'degree'" << endl;
			cout << "if you entered all elements, press 0 and exit" << endl;
			bool isContinue = 1;
			double value = 0;
			int degree = 0;
			while (isContinue)
			{
				cout << "enter value and degree" << endl;
				cin >> value >> degree;
				addSortedElement(pyl, value, degree);
				cout << "continue? (yes = 1) (no = 0)" << endl;
				cin >> isContinue;
			}
		}

		else if (temp == command::doAdd)
		{
			cout << "you should create new pylonimal to add" << endl;
			cout << "enter new elements of pylonimal like this: 'value' (space) 'degree'" << endl;
			cout << "if you entered all elements, press 0 and exit" << endl;
			bool isContinue = 1;
			double value = 0;
			int degree = 0;
			List *pyl2 = createList();
			while (isContinue)
			{
				cout << "enter value and degree" << endl;
				cin >> value >> degree;
				addSortedElement(pyl2, value, degree);
				printList(pyl2);
				cout << "continue? (yes = 1) (no = 0)" << endl;
				cin >> isContinue;
			}

			pylAdd(pyl, pyl2);
		}

		else if (temp == command::doValue)
		{
			cout << "at which point you want to calculate pylonimal?" << endl;
			double point = 0;
			cin >> point;
			cout << pylValue(pyl, point) << endl;
		}

		else if (temp == command::isEqual)
		{
			cout << "you should create new pylonimal to add" << endl;
			cout << "enter new elements of pylonimal like this: 'value' (space) 'degree'" << endl;
			cout << "if you entered all elements, press 0 and exit" << endl;
			bool isContinue = 1;
			double value = 0;
			int degree = 0;
			List *pyl2 = createList();
			while (isContinue)
			{
				cout << "enter value and degree" << endl;
				cin >> value >> degree;
				addSortedElement(pyl2, value, degree);
				printList(pyl2);
				cout << "continue? (yes = 1) (no = 0)" << endl;
				cin >> isContinue;
			}

			cout << pylIsEqual(pyl, pyl2) << endl;
			removeList(pyl2);
			delete pyl2->first;
			delete pyl2;
		}

		printList(pyl);
		cout << "it is done!" << endl;
	}
	
	removeList(pyl);
	delete pyl->first;
	delete pyl;
	int n = 0;
	cin >> n;
	return 0;
}