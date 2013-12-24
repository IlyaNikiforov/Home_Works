#include "iostream"
#include "fstream"

using namespace std;

void changeWay(int **way, int k, int j, int m)
{
	int i = 0;
	
	while (way[k][i] != -1)
	{
		way[j][i] = way[k][i];
		i++;
	}
	
	way[j][i] = j;

	while (i < m)
	{
		i++;
		way[j][i] = -1;
	}

	/*cout << endl;
	int l = 0;
	while (way[j][l] != j)
	{
		cout << way[j][l] + 1 << "->";
		l++;
	}
	cout << way[j][l] + 1;*/
}

void shortWay(int **a, int *b, int n, int m, int k, int max, int **way)
{
	int *c = new int [n];

	for (int i = 0; i < n; i++)
	{
		b[i] = max;
		c[i] = 0;
	}

	b[k] = 0;

	int min = max;

	for (int l = 0; l < n; l++)
	{
		for (int j = 0; j < n; j++)
			if (b[j] > b[k] + a[k][j])
			{
				b[j] = b[k] + a[k][j];
				changeWay(way, k, j, m);
			}

		c[k] = 1;
		min = max;

		for (int i = 0; i < n; i++)
			if (c[i] == 0 && b[i] < min)
			{	
				min = b[i];
				k = i;
			}
	}

	//for (int i = 0; i < n; i++)
		//cout << b[i] << " ";

	delete[] c;
}

int main()
{
	cout << "Graph bypass in shortest way" << endl;
	ifstream in ("input.txt");

	if (!in)
	{
		cout << "Error reading from file" << endl;
		int n = 0;
		cin >> n;
		return 1;
	}

	int n = 0;
	in >> n;
	int m = 0;
	in >> m;
	m *= 2;
	int **a = new int *[n];
	int *b = new int [n];
	int *done = new int [n];
	int **way = new int *[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int [n];
		done[i] = 0;
		way[i] = new int[m];
	}

	int i = 0;
	int j = 0;
	int k = 0;
	const int max = 1000000000;

	cout << max << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = max;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			way[i][j] = -1;

	way[0][0] = 0;

	while (!in.eof())
	{
		in >> i >> j >> k;
		a[i - 1][j - 1] = k;
		a[j - 1][i - 1] = k;
	}

	k = 0;
	b[k] = 0;
	int min = 0;
	int l = 0;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Length of way: " << b[k] << endl;
		shortWay(a, b, n, m, k, max, way);
		done[k] = i + 1;
		min = max;
		cout << i + 1 << ": " << k + 1 << endl;
		while (way[k][l] != k)
		{
			cout << way[k][l] + 1 << "->";
			l++;
		}
		cout << way[k][l] + 1;
		cout << endl;
		l = 0;
		for (int j = 0; j < n; j++)
			if (done[j] == 0 && b[j] < min)
			{	
				min = b[j];
				k = j;
			}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
		delete[] way[i];
	}

	delete[] a;
	delete[] way;

	delete[] done;
	delete[] b;

	cin >> n;
	
	return 0;
}