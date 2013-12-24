


int max(int a[], int i, int j)
{
	if (a[i] >= a[j])
		return i;
	else
		return j;
}

void swap(int &a, int &b)
{
	int p = 0;
	p = a;
	a = b;
	b = p;
}

void heaping(int a[], int begin, int end)
{
	int p = 0;
	
	if (2 * begin + 2 <= end)
		p = max(a, 2 * begin + 1, 2 * begin + 2);
	else 
		p = 2 * begin + 1;
	
	while ((a[begin] < a[p]) && (begin * 2 + 1 <= end))
	{
		swap(a[begin], a[p]);
		begin = p;
			
		if (2 * begin + 2 <= end)
			p = max(a, 2 * begin + 1, 2 * begin + 2);
		else if (2 * begin + 1 <= end)
			p = 2 * begin + 1;
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heaping(a, i, n - 1);

	for (int i = n - 1; i >= 1; i--)
	{
		swap(a[0], a[i]);
		heaping(a, 0, i - 1);
	}
}

void quickSort(int a[], int begin, int end)
{
	int k = 0;
	
	if (a[begin] >= a[begin + 1])
		k = a[begin];
	else 
		k = a[begin + 1];
	
	int i = begin;
	int j = end;
	int swap = 0;
	
	while (i <= j)
	{
		while (k > a[i])
			i++;
		while (k < a[j])
			j--;

		if (i <= j)
		{
			swap = a[j];
			a[j] = a[i];
			a[i] = swap;
			i++;
			j--;
		}
		
	}

	if (j > begin)
		quickSort(a, begin, j);
	if (i < end)
		quickSort(a, i, end);
	}