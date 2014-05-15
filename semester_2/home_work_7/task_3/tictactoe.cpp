#include "tictactoe.h"

TicTacToe::TicTacToe(int value, int valueToWin)
{
	whooseTurn = 1;
	winSize = valueToWin;
	size = value;
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
					return true;
			}
			j -= temp;
			temp = 0;

			while (i < size && field[i][j] == value)
			{
				temp++;
				i++;
				if (temp == winSize)
					return true;
			}
			i -= temp;
			temp = 0;

			while (j < size && i < size && field[i][j] == value)
			{
				temp++;
				i++;
				j++;
				if (temp == winSize)
					return true;
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
					return true;
			}
			i -= temp;
			j += temp;
			temp = 0;
		}

	return false;
}


