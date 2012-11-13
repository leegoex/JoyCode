#include <iostream>
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

int main(int argc, char *argv[])
{
	int arr[10] = {5, 1, 8, 3, 2, 7, 0, 6, 4, 9};
	//insertion_sort2(arr, 10);
	shell_sort(arr, 10);
	int i = 0;
	for(i = 0; i < 10; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	system("pause");
	return 0;
}