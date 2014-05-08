#include "printer.h"
#include "iostream"

using namespace std;

//Printer::Printer();

void Printer::transfer(int **matrix, int N)
{
	sizeOfArray = N * N;
	array = new int [N * N];

	int p = N * N;
	int i = N / 2;
	int j = N / 2;
	int l = 0;

	for (int k = 0; k <= N; k++)
	{
		if (k % 2)
		{
			for (int m = 0; m < k; m++, i++)
			{
				l++;
				if (l > p)
					break;
				//cout << matrix[i][j] << " ";
				array[l - 1] = matrix[i][j];
			}
			for (int m = 0; m < k; m++, j++)
			{
				l++;
				if (l > p)
					break;
				//cout << matrix[i][j] << " ";
				array[l - 1] = matrix[i][j];
				}
		}

		else
		{
			for (int m = 0; m < k; m++, i--)
			{
				l++;
				if (l > p)
					break;
				//cout << matrix[i][j] << " ";
				array[l - 1] = matrix[i][j];
			}

			for (int m = 0; m < k; m++, j--)
			{
				l++;
				if (l > p)
					break;
				//cout << matrix[i][j] << " ";
				array[l - 1] = matrix[i][j];
			}
		}

	}
}
