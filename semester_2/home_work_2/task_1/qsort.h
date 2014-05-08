#pragma once
#include "sort.h"

/// class of quick sort
class QSort : public Sort
{
public:
	void sort(int array[], int length);
private:
	void qsort(int array[], int begin, int end);
};

