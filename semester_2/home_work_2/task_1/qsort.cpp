#include "qsort.h"

void QSort::sort(int array[], int length)
{
	qsort(array, 0, length - 1);
}

void QSort::qsort(int array[], int begin, int end)
{
	int k = 0;

	if (array[begin] >= array[begin + 1])
		k = array[begin];
	else
		k = array[begin + 1];

	int i = begin;
	int j = end;
	int swap = 0;

	while (i <= j)
	{
		while (k > array[i])
			i++;
		while (k < array[j])
			j--;

		if (i <= j)
		{
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			i++;
			j--;
		}

	}

	if (j > begin)
		qsort(array, begin, j);
	if (i < end)
		qsort(array, i, end);
}



