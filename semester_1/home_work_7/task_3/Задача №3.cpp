#include "iostream"
#include "fstream"
#include "list.h"
#include "strings.h"
#include "hash.h"

using namespace std;

void wordCorrect(String *string)
{
	if (string->begin[0] >= 'A' && string->begin[0] <= 'Z')
		string->begin[0] = string->begin[0] + 32;

	if (string->begin[string->length - 1] < 'A' || 
	   string->begin[string->length - 1] > 'z' || 
	   (string->begin[string->length - 1] > 'Z' && string->begin[string->length - 1] < 'a'))
			strCut(string, 0, string->length - 1);
}

int main()
{
	cout << "Programm counts amount of words in text" << endl;
	ifstream in ("input.txt");
	
	if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	const int sizeOfHash = 100;
	List **hashTable = hashCreate(sizeOfHash);

	String *str = strCreate();
	

	while (!in.eof())
	{
		char *a = new char [100];
		in >> a;
		strDelete(str);
		delete str;
		str = charToStr(a);
		wordCorrect(str);
		hashAdd(str, hashTable, sizeOfHash);
	}

	hashPrint(hashTable, sizeOfHash);

	cout << endl << "max length: " << hashMaxLength(hashTable, sizeOfHash)
		<< endl << "mean length: " << hashMeanLength(hashTable, sizeOfHash)
		<< endl << "word amount: " << hashWordAmount(hashTable, sizeOfHash) 
		<< endl << "load factor: " << hashLoadFactor(hashTable, sizeOfHash)
		<< endl << "empty values: " << hashEmptyValues(hashTable, sizeOfHash) << endl;
	
	strDelete(str);
	delete str;

	hashDelete(hashTable, sizeOfHash);

	int n = 0;
	cin >> n;

	return 0;
}