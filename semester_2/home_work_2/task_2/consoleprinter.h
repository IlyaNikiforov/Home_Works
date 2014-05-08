#pragma once
#include "iostream"
#include "printer.h"

/// prints transfered matrix to console
class ConsolePrinter : public Printer
{
	public:
		void print();
};

