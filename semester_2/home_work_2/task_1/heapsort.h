#pragma once
#include "sort.h"

class HeapSort : public Sort
{
public:
    HeapSort();
    void sort(int array[], int length);
private:
    int max(int a[], int i, int j);
    void swap(int &a, int &b);
    void heaping(int a[], int begin, int end);
};


