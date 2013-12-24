#include "iostream"
#include "fstream"

using namespace std;

int main()
{
	cout << "Minimum spanning tree problem" << endl;
	ifstream in ("input.txt");
	int n = 0;
	in >> n;
	int **matrix = new int *[n];
	int **newMatrix = new int *[n];
	int *added = new int [n];
	
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int [n];
		newMatrix[i] = new int [n];
		added[i] = -1;
		
		for (int j = 0; j < n; j++)
			newMatrix[i][j] = 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> matrix[i][j];

	in.close();

	added[0] = 0;
	int min = 10000;
	int index = 1;
	int lineIndex = 0;
	int rowIndex;

	while (index != n)
	{
		for (int j = 0; j < index; j++)
			for (int i = 0; i < n; i++)
				if (matrix[added[j]][i] < min && matrix[added[j]][i] > 0)
				{
					min = matrix[added[j]][i];
					lineIndex = added[j];
					rowIndex = i;
				}

		index++;
		added[index - 1] = rowIndex;
		min = 10000;
		newMatrix[lineIndex][rowIndex] = matrix[lineIndex][rowIndex];
		newMatrix[rowIndex][lineIndex] = matrix[lineIndex][rowIndex];
		
		for (int i = 0; i < index; i++)
		{
			matrix[added[index - 1]][added[i]] = 0;
			matrix[added[i]][added[index - 1]] = 0;
		}
	}	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << newMatrix[i][j] << " ";

		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
		delete[] newMatrix[i];
	}

	delete[] matrix;
	delete[] added;
	delete[] newMatrix;

	cin >> n;
	return 0;
}