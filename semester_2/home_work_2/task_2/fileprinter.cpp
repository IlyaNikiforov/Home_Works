#include "fileprinter.h"

void FilePrinter::print()
{
	ofstream out("output.txt");
	out << "HUI" << endl;
	for (int i = 0; i < sizeOfArray; i++)
		out << array[i] << " ";
	out.close();
}
