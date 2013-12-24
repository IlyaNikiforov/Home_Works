#include "iostream"
#include "strings.h"

using namespace std;

enum operation 
{
	doCreate = -1,
	doAdd,
	doRemove,
	doCopy,
	doCut,
	doLength,
	isEqual,
	isEmpty,
	doPrint,
};

bool isCommand (int temp)
{
	return (temp >= operation::doCreate) && (temp <= operation::doPrint); 
}

int main()
{
	cout << "My string" << endl;
	
	int com = doAdd;
	String *string = strCreate();

	while (isCommand(com))
	{
		cout << "What would you like to do?" << endl;
		cout << "-1: Create string" << endl;
		cout << "0: Add string to your string" << endl;
		cout << "1: Delete string" << endl;
		cout << "2: Clone your string" << endl;
		cout << "3: Cut your string from .. to .." << endl;
		cout << "4: Print size of your string" << endl;
		cout << "5: Check equality of strings" << endl;
		cout << "6: Is your string empty?" << endl;
		cout << "7: Print your string" << endl;
		cout << "Everything else: exit" << endl;

		cin >> com;

		if (com == operation::doRemove)
		{
			strDelete(string);
		}

		else if (com == operation::doCopy)
		{
			String *clone = strClone(string);
			strDelete(clone);
			delete clone;
		}
		
		

		else if (com == operation::doCut)
		{
			cout << "Enter beginning and ending of new string" << endl;
			int i = 0;
			int j = 0;
			cout << "Enter beginning: ";
			cin >> i;
			cout << "Enter ending: ";
			cin >> j;
			strCut(string, i, j);
		}

		else if (com == operation::doLength)
			cout << strLen(string) << endl;

		else if (com == operation::isEqual)
		{
			cout << "Enter string to check" << endl;
			String *newstr = new String;
			char *a = new char[1000];
			cin >> a;
			newstr->begin = a;
			newstr->length = strLen(newstr);
			cout << strIsEqual(string, newstr) << endl;
			strDelete(newstr);
			delete newstr;
		}

		else if (com == operation::isEmpty)
			cout << strIsEmpty(string) << endl;

		else if (com == operation::doCreate || com == operation::doAdd)
		{
			if (com == operation::doCreate)
				cout << "Enter string you would like to create:" << endl;
			else 
				cout << "Enter string you would like to add:" << endl;
			
			String *newstr = new String;
			char *a  = new char[1000];
			cin >> a;
			newstr->begin = a;
			newstr->length = strLen(newstr);
			strAdd(string, newstr);
		}

		else if (com == operation::doPrint)
			strPrint(string);

		cout << "It is done!" << endl << endl;
	}

	strDelete(string);
	delete string;

	int n = 0;
	cin >> n;
	return 0;
}
