#include <iostream>
#include <string>
using namespace std;

void elem_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

//插入排序由N-1趟排序组成。对于i=1到N-1趟，插入排序保证从0到位置i上的元素为已排序状态。
//插入排序所表达的策略是：在第i趟排序，我们将位置i上的元素向左移至它在前i+1个元素中的正确位置上。
void insertion_sort1(int *arr, int size)
{
	int i, j, swap;
	for(i = 1; i < size; i++) {
		for(j = i; j >= 0; j--) {
			if(arr[j] < arr[j-1]) {
				elem_swap(&arr[j], &arr[j-1]);
				swap = 1;
			} else
				swap = 0;
			if(swap == 0)
				break;
		}
	}
}

void insertion_sort2(int *arr, int size)
{
	int i,j;
	for(i = 1; i < size; i++) {
		int tmp = arr[i];
		for(j = i; j > 0 && arr[j-1] > tmp; j--)
			arr[j] = arr[j-1];
		arr[j] = tmp;
	}
}

//谢尔排序是通过比较相距一定间隔的元素来工作；各趟比较所用的距离随着算法的进行而减小
//它针对插入排序的优化就是减少了对象交换的次数。因为它最终都要回归到处理增量为1的情况，
//而此时就与处理插入排序的情形一样了
//另外，关于增量序列，最好的通项公式是（数学公式，无法表达）
void shell_sort(int *arr, int size)
{
	int gap = size / 2;
	for (; gap > 0; gap /= 2)
	{
		int i,j;
		for (i = gap; i < size; i += gap)
		{
			int tmp = arr[i];
			for (j = i; j > 0 && arr[j-gap] > tmp; j -= gap)
				arr[j] = arr[j-gap];
			arr[j] = tmp;
		}

		cout<<"gap="<<gap<<": ";
		for(i = 0; i < size; i++)
			cout<<arr[i]<<' ';
		cout<<endl;
	}
}

//归并排序算法的基本操作时合并两个已排序的表。因为这两个表示已排序的，所以若将
//输出放到第3个表中则该算法可以通过对输入数据一趟排序来完成。
void mergesorted(int *arr, int *tmpArr, int l, int c, int r)
{
	int tmp = l;
	int lend = c-1;
	int elem = r - l + 1;

	while (l <= lend && c <= r) {
		if(arr[l] < arr[c])
			tmpArr[tmp++] = arr[l++];
		else
			tmpArr[tmp++] = arr[c++];
	}
	while (l <= lend)
		tmpArr[tmp++] = arr[l++];
	while(c <= r)
		tmpArr[tmp++] = arr[c++];

	int i = 0;
	for (i = 0; i < elem; i++,r--)
		arr[r] = tmpArr[r];
}

void mergesort(int *arr, int *tmpArr, int l, int r)
{
	if(l < r)
	{
		int c = (l + r) / 2;
		mergesort(arr, tmpArr, l, c);
		mergesort(arr, tmpArr, c+1, r);
		mergesorted(arr, tmpArr, l, c+1, r);
	}
}

void merge_sort(int *arr, int size)
{
	int *tmpArr = new int[size];
	mergesort(arr, tmpArr, 0, size-1);
	delete []tmpArr;
}

//快速排序
int median3(int *arr, int l, int r)
{
	int c = (l + r) / 2;
	if(arr[c] < arr[l])
		elem_swap(&arr[c], &arr[l]);
	if(arr[r] < arr[l])
		elem_swap(&arr[r], &arr[l]);
	if (arr[r] < arr[c])
		elem_swap(&arr[r], &arr[c]);

	elem_swap(&arr[c], &arr[r-1]);
	return arr[r-1];
}

void quicksort(int *arr, int l, int r)
{
	if(l + 10 <= r)
	{
		int pivot = median3(arr, l, r);
		int i = l, j = r-1;
		for (;;)
		{
			while(arr[++i] < pivot) {}
			while(arr[--j] > pivot) {}
			if(i < j)
				elem_swap(&arr[i], &arr[j]);
			else
				break;
		}
		elem_swap(&arr[i], &arr[r-1]);
		quicksort(arr, l, i-1);
		quicksort(arr, i+1, r);
	}
	else
		insertion_sort1(arr+l, r-l+1);
}

void quick_sort(int *arr, int size)
{
	quicksort(arr, 0, size-1);
}

int main(int argc, char *argv[])
{
	string str;
	cout<<"Please enter the algorithm(insertion1, insertion2, shell, merge, quick)";
	cout<<"\nor enter quit to exit the program:";
	cin>>str;
	while (str != "quit")
	{
		int arr[20] = {5, 15, 8, 3, 2, 17, 10, 6, 14, 19, 1, 13, 0, 12, 7, 4, 16, 11, 18, 9};
		int size = sizeof(arr)/sizeof(int);
		if(str == "insertion1") {
			insertion_sort1(arr, size);
		} else if(str == "insertion2") {
			insertion_sort2(arr, size);
		} else if(str == "shell") {
			shell_sort(arr, size);
		} else if(str == "merge") {
			merge_sort(arr, size);
		} else if(str == "quick") {
			quick_sort(arr, size);
		} else {
			cout<<"Unknown sorting algorithm\n";
		}
		int i = 0;
		for(i = 0; i < size; i++) 
			cout<<arr[i]<<' ';
		cout<<endl;
		cout<<"Please enter the sorting algorithm(insertion1, insertion2, shell, merge, quick):";
		cin>>str;
	}
	system("pause");
	return 0;
}