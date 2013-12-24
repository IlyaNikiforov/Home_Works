
#include "iostream"
#include "fstream"
#include "strings.h"
#include "list.h"
#include "hash.h"

using namespace std;


int main()
{
	cout << "Programm checks two files and creates third file with equal for first two files strings" << endl;

	const int sizeOfHash = 5;
	List **list = hashCreate(sizeOfHash);

	String *str = strCreate();

	ifstream in;
	
	in.open("input1.txt");

	if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}
	
	while (!in.eof())
	{
		char *a = new char [1000];
		in.getline(a, 1000);
		delete[] str->begin;
		str->begin = a;
		str->length = strLen(str);
		hashAdd(str, list, sizeOfHash);
	}

	//hashPrint(list, sizeOfHash);
	//cout << endl;

	in.close();
	
	in.open("input2.txt");

		if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	ofstream out;

	out.open("output.txt");

	while (!in.eof())
	{
		char *a = new char [1000];
		in.getline(a, 1000);
		delete[] str->begin;
		str->begin = a;
		str->length = strLen(str);
		if (hashExist(str, list, sizeOfHash))
			out << str->begin << endl;
	}
	
	in.close();

	cout << endl << endl << "It is done!"
		 << endl << "output file is \"output.txt\"" << endl;

	out.close();

	strDelete(str);
	delete str;

	hashDelete(list, sizeOfHash);

	int n = 0;
	cin >> n;
	return 0;
}

