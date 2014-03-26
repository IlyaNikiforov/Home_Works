#include "iostream"
#include "sort.h"
#include "qsort.h"
#include "heapsort.h"
#include "bubblesort.h"

using namespace std;

int main()
{
    cout << "Sorting programm" << endl;
    cout << "Enter your array. If you want to finish, enter -1000" << endl;

    int MaxSize = 1000;
    int *array = new int [MaxSize];
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
    int choise = 0;
    cin >> choise;

    if (choise == 1)
    {
        QSort qSort;
        qSort.sort(array, size);
    }

    else if (choise == 2)
    {
        HeapSort heapSort;
        heapSort.sort(array, size);
    }

    else if (choise == 3)
    {
        BubbleSort bubbleSort;
        bubbleSort.sort(array, size);
    }

    for (int j = 0; j < size; j++)
        cout << array[j] << " ";

    delete array;

    return 0;
}
