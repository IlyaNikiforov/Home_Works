#pragma once

/// class, that transfers matrix and prints it
class Printer
{
	public:
		Printer() {}
		~Printer()
		{
			delete[] array;
		}

		/// virtual function, that print trnsfered matrix
		virtual void print() = 0;
		/// transfers matrix
		void transfer(int **matrix, int N);
	protected:
		/// this array is transfered matrix
		int *array;
		int sizeOfArray;
};


