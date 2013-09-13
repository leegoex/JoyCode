#include <iostream>

#include "compare.h"
#include "rdirect.h"

static int comp = 0;
static int swap_times = 0;

//归并排序使用最优的比较次数，但很难用于主存排序中，因为需要引入额外的存储空间
static int merge_sort(int *arr, int l, int r, int *temp, int size)
{
	if (l >= r)
		return -1;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid, temp, size);
	merge_sort(arr, mid+1, r, temp, size);

	int i,j,index;
	i = l;
	j = mid+1;
	index = l;
	while (i<=mid && j<=r)
	{
		if (less_than(arr[i], arr[j], &comp))
		{
			temp[index++] = arr[i++];
			++ swap_times;
		}
		else
		{
			temp[index++] = arr[j++];
			++ swap_times;
		}
	}
	while (i <= mid)
	{
		temp[index++] = arr[i++];
		++ swap_times;
	}
	while(j <= r)
	{
		temp[index++] = arr[j++];
		++ swap_times;
	}

	for (i = l, index=l; i <= r; ++i)
	{
		arr[i] = temp[index++];
	}
	return 0;

}

int mergeSort(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Merge sort   **************************"<<endl;

	comp = 0;
	swap_times = 0;

	int *temp = new int[size];

	merge_sort(arr, 0, size-1, temp, size);

	for (int n = 0; n < size; ++n)
		cout<< arr[n] << " ";
	cout<<endl;

	delete []temp;

	cout << "compare :" << comp << " times\n";
	cout << "swap :" << swap_times << " times\n";

	return 0;
}