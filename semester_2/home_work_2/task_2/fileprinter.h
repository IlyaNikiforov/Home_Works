#pragma once
#include "fstream"
#include "iostream"
#include "printer.h"

using namespace std;

/// prints transfered matrix to file
class FilePrinter : public Printer
{
	public:
		void print();
};


