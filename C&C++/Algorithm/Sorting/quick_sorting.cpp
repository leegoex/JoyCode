#include <iostream>
#include "compare.h"
#include "rdirect.h"

static int comp = 0;
static int swap_times = 0;

static void swap_pivot(int *p, int *e)
{
	++ swap_times;
	int temp = *p;
	*p = *e;
	*e = temp;
}

static int median3(int *arr, int l, int r)
{
	int mid = (l+r)/2;
	if (less_than(arr[mid], arr[l], &comp))
		swap_pivot(&arr[mid], &arr[l]);
	if (less_than(arr[r], arr[mid], &comp))
		swap_pivot(&arr[r], &arr[mid]);
	if (less_than(arr[mid], arr[l], &comp))
		swap_pivot(&arr[mid], &arr[l]);

	swap_pivot(&arr[mid], &arr[r-1]);

	return arr[r-1];
}

static int quick_sort_1(int *arr, int l, int r, int size)
{
	if (l >= r)
		return -1;
	int pivot = (l+r)/2;

	//swap the pivot to end
	swap_pivot(&arr[pivot], &arr[r]);

	int left = l;
	int right = r-1; //because the pivot swap to the end, so the right index need to decrease 1

	while (/*left < right*/1)
	{
		while (less_than(arr[left], arr[r], &comp)) ++ left;
		while(less_than(arr[r], arr[right], &comp)) -- right;

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			++ left;
			-- right;
			++ swap_times;
		}
		else
			break;
	}

	swap_pivot(&arr[r], &arr[left]);

	for(int n = 0; n < size; ++n)
		cout << arr[n] << " ";
	cout<<endl;
	
	quick_sort_1(arr, l, left-1, size);
	quick_sort_1(arr, left+1, r, size);
	return 0;
}

static int quick_sort_2(int *arr, int l, int r, int size)
{
	if (l >= r)
		return -1;
	int pivot = median3(arr, l, r); //choosing the median of the first, middle and last element of the partition for the pivot

	int left = l;
	int right = r-1; //because the pivot swap to the end, so the right index need to decrease 1

	while (/*left < right*/1)
	{
		while (less_than(arr[left], /*arr[r-1]*/pivot, &comp)) ++ left;
		while(less_than(pivot, arr[right], &comp)) -- right;

		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			++ left;
			-- right;
			++ swap_times;
		}
		else
			break;
	}

	swap_pivot(&arr[r-1], &arr[left]);

	for(int n = 0; n < size; ++n)
		cout << arr[n] << " ";
	cout<<endl;

	quick_sort_2(arr, l, left-1, size);
	quick_sort_2(arr, left+1, r, size);
	return 0;
}

int quickSort_1(int *arr, int size)
{
	comp = 0;
	swap_times = 0;

	rdirect out("D:\\output.txt");

	cout<<"****************   Quick sort 1   **************************"<<endl;

	quick_sort_1(arr, 0, size-1, size);

	cout << "compare :" << comp << " times\n";
	cout << "swap :" << swap_times << " times\n";

	return 0;
}

int quickSort_2(int *arr, int size)
{
	comp = 0;
	swap_times = 0;

	rdirect out("D:\\output.txt");

	cout<<"****************   Quick sort 2  **************************"<<endl;

	quick_sort_2(arr, 0, size-1, size);

	cout << "compare :" << comp << " times\n";
	cout << "swap :" << swap_times << " times\n";

	return 0;
}