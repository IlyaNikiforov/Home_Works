#include "iostream"
#include "sort.h"
#include "qsort.h"
#include "heapsort.h"
#include "bubblesort.h"

using namespace std;

enum KindOfSort
{
	quick = 1,
	heap,
	bubble
};

int main()
{
	cout << "Sorting programm" << endl;
	cout << "Enter your array. If you want to finish, enter -1000" << endl;

	int maxSize = 1000;
	int *array = new int [maxSize];
	int size = 0;
	while (true)
	{
	   cin >> array[size];
	   if (array[size] == -1000)
		   break;
	   size++;
	}

	cout << "Your array:" << endl;
	for (int j = 0; j < size; j++)
		cout << array[j] << " ";
	cout << endl;
	cout << "Choose the way of sorting:" << endl
		 << "1: quick sort" << endl
		 << "2: heap sort" << endl
		 << "3: bubble sort" << endl;
	int choice = 0;
	cin >> choice;

	Sort *sorter;

	if (choice == KindOfSort::quick)
		sorter = new QSort;

	else if (choice == KindOfSort::heap)
		sorter = new HeapSort;

	else if (choice == KindOfSort::bubble)
		sorter = new BubbleSort;

	sorter->sort(array, size);

	for (int j = 0; j < size; j++)
		cout << array[j] << " ";

	delete[] array;
	delete sorter;
	return 0;
}
