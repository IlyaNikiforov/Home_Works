#include "iostream"
#include "fstream"

using namespace std;

bool isEmpty(int *whatIsGone, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (whatIsGone[i] != 0)
			return 0;
	}

	return 1;
}

void step(int n, int *whatIsGone, int **adjacencyTable, int i, char &let)
{
	cout << let << ": " << i << endl;
	let++;
	whatIsGone[i] = 0;
	
	for (int l = 0; l < n; l++)
		if (adjacencyTable[i][l] == 1 && whatIsGone[l] == 1)
			step(n, whatIsGone, adjacencyTable, l, let);
}

int main()
{
	cout << "Graph bypass" << endl;
	cout << "Enter name of file" << endl;
	ifstream in;
	char str[100];
	cin >> str;
	in.open(str);
	
	if (!in.is_open())
		return 0;
	
	int n = 0;
	in >> n;
	int m = 0;
	in >> m;
	
	int **adjacencyTable = new int *[n];
	
	for (int i = 0; i < n; i++)
		adjacencyTable[i] = new int [n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adjacencyTable[i][j] = 0;
	
	int k = 0;
	int j = 0;

	for (int l = 0; l < m; l++)
	{
		in >> k >> j;
		adjacencyTable[k][j] = 1;
		adjacencyTable[j][k] = 1;
	}

	int *whatIsGone = new int [n];
	
	for (int i = 0; i < n; i++)
		whatIsGone[i] = 1;
	
	char let = 'a';

	int i = 0;
	int count = 0;

	while (!isEmpty(whatIsGone, n))
	{
		i = 0;
		while (whatIsGone[i] != 1)
			i++;
		count++;
		cout << count << ": " << endl;
		step(n, whatIsGone, adjacencyTable, i, let);
		let = 'a';
	}

	cout << "There are " << count << " connected components in graph" << endl;

	for (int i = 0; i < n; i++)
		delete[] adjacencyTable[i];

	delete[] adjacencyTable;
	delete[] whatIsGone;

	in.close();
	cin >> n;
	return 0;
}