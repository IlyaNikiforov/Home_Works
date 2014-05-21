#pragma once

template <typename type1>
class BubbleSort
{
	public:
		template <typename type2>
		void sort(type1 array[], const int &sizeOfArray, type2 &compare);
};

template <typename type1>
template <typename type2>
void BubbleSort<type1>::sort(type1 array[], const int &sizeOfArray, type2 &compare)
{
	for (int i = 0; i < sizeOfArray; i++)
		for (int j = 0; j < sizeOfArray - i - 1; j++)
			if (compare(array[j], array[j + 1]))
			{
				type1 temp;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
}
