#include "consoleprinter.h"
#include "iostream"

using namespace std;


void ConsolePrinter::print()
{
	for (int i = 0; i < sizeOfArray; i++)
		cout << array[i] << " ";
}
