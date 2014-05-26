#pragma once

class TicTacToe
{
	public:
		TicTacToe(int value, int valueToWin);
		~TicTacToe();
		void setValue(int i, int j);
		bool DoesPlayerWins();
		int returnTurn();
		void returnWinningCombination(int **matrix);
	private:
		bool whooseTurn;
		int size;
		int winSize;
		int **field;
		int **winningCombination;
};

