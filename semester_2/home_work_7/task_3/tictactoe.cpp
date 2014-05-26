#include "tictactoe.h"

TicTacToe::TicTacToe(int value, int valueToWin)
{
	whooseTurn = 1;
	winSize = valueToWin;
	size = value;
	winningCombination = new int *[2];
	winningCombination[0] = new int [valueToWin];
	winningCombination[1] = new int [valueToWin];
	field = new int *[size];
	for (int i = 0; i < size; i++)
		field[i] = new int [size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			field[i][j] = -1;
}

TicTacToe::~TicTacToe()
{
	for (int i = 0; i < size; i++)
		delete field[i];
	delete[] field;
	delete winningCombination[0];
	delete winningCombination[1];
	delete[] winningCombination;
}

int TicTacToe::returnTurn()
{
	return whooseTurn;
}

void TicTacToe::setValue(int i, int j)
{
	field[i][j] = whooseTurn;
	whooseTurn = 1 - whooseTurn;
}

bool TicTacToe::DoesPlayerWins()
{
	int temp = 0;
	int value = 1 - whooseTurn;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			while (j < size && field[i][j] == value)
			{
				temp++;
				j++;
				if (temp == winSize)
				{
					for (int k = 0; k < winSize; k++)
					{
						j--;
						winningCombination[0][k] = i;
						winningCombination[1][k] = j;
					}
					return true;
				}
			}
			j -= temp;
			temp = 0;

			while (i < size && field[i][j] == value)
			{
				temp++;
				i++;
				if (temp == winSize)
				{
					for (int k = 0; k < winSize; k++)
					{
						i--;
						winningCombination[0][k] = i;
						winningCombination[1][k] = j;
					}
					return true;
				}
			}
			i -= temp;
			temp = 0;

			while (j < size && i < size && field[i][j] == value)
			{
				temp++;
				i++;
				j++;
				if (temp == winSize)
				{
					for (int k = 0; k < winSize; k++)
					{
						j--;
						i--;
						winningCombination[0][k] = i;
						winningCombination[1][k] = j;
					}
					return true;
				}
			}
			i -= temp;
			j -= temp;
			temp = 0;

			while (i < size && j >= 0 && field[i][j] == value)
			{
				temp++;
				i++;
				j--;
				if (temp == winSize)
				{
					for (int k = 0; k < winSize; k++)
					{
						j++;
						i--;
						winningCombination[0][k] = i;
						winningCombination[1][k] = j;
					}
					return true;
				}
			}
			i -= temp;
			j += temp;
			temp = 0;
		}

	return false;
}

void TicTacToe::returnWinningCombination(int **matrix)
{
	for (int i = 0; i < winSize; i++)
	{
		matrix[0][i] = winningCombination[0][i];
		matrix[1][i] = winningCombination[1][i];
	}
}


