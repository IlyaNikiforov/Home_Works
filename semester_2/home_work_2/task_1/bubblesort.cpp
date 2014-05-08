#include "bubblesort.h"

void BubbleSort::sort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j +1])
			{
				array[j] += array[j + 1];
				array[j + 1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];
			}
		}
	}
}
