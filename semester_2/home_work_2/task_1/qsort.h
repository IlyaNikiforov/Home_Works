#pragma once
#include "sort.h"

class QSort : public Sort
{
public:
	QSort();
	void sort(int array[], int length);
private:
	void qsort(int array[], int begin, int end);
};

