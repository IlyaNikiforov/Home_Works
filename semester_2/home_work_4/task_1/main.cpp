#include "stringtest.h"
#include "hashtest.h"
#include "hash.h"
#include "iostream"
#include "hashfunction1.h"
#include "hashFunction2.h"

using namespace std;

int main()
{
	StringTest stringTest;
	QTest::qExec(&stringTest);
	HashTest hashTest;
	QTest::qExec(&hashTest);

	enum states
	{
		add,
		find,
		del,
		statistic,
		change
	};

	int choice = add;
	cout << "Enter size of hash" << endl;
	int sizeOfHash = 0;
	cin >> sizeOfHash;
	bool typeOfHash = 0;
	HashFunction *hash1 = new HashFunction1;
	HashFunction *hash2 = new HashFunction2;
	Hash *hash = new Hash(sizeOfHash, hash1);
	while (choice >= add && choice <= change)
	{
		cout << "What would you like to do?" << endl;
		cout << "0: add new value to hash" << endl;
		cout << "1: find existing value in hash" << endl;
		cout << "2: delete value from hash" << endl;
		cout << "3: get statistics" << endl;
		cout << "4: change hash function" << endl;
		cout << "everything else: exit" << endl;

		cin >> choice;

		if (choice == add)
		{
			cout << "Enter your word" << endl;
			char str[100];
			cin >> str;
			Strings *newStr = new Strings;
			newStr->add(str);
			hash->add(newStr);
		}

		else if (choice == find)
		{
			cout << "Enter your word" << endl;
			char str[100];
			cin >> str;
			Strings *newStr = new Strings;
			newStr->add(str);
			cout << hash->find(newStr) << endl;
		}

		else if (choice == del)
		{
			cout << "Enter your word" << endl;
			char str[100];
			cin >> str;
			Strings *newStr = new Strings;
			newStr->add(str);
			hash->del(newStr);
		}

		else if (choice == statistic)
		{
			hash->statistic();
		}

		else if (choice == change)
		{
			if (typeOfHash == 0)
				hash->changeHashFunction(hash2);
			else hash->changeHashFunction(hash1);
		}

		hash->print();
	}

	delete hash1;
	delete hash2;
	delete hash;
	return 0;
}
