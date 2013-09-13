#include <iostream>
using namespace std;

#include "compare.h"
#include "rdirect.h"

//按冒泡排序算法基本概念直接实现的算法，该算法需要最多的比较次数和交换次数
//，在原序列为刚好逆序时，消耗最大
int bubbleSort_1(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Bubble sort 1   **************************"<<endl;

	int ret,i,j,temp,comp;
	ret = comp = 0;
	i = size-1;
	while(i > 0)
	{
		int step_swap = 0;
		cout << "i = " << i << ":";
		for(j = 0; j < i; ++j)
		{
			if(less_than(arr[j+1], arr[j], &comp))
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				++ ret;
				++ step_swap;
			}
		}
		for(int n = 0; n < size; ++n)
			cout << arr[n] << " ";
		cout<<"swap " << step_swap << " times";
		cout<<endl;

		--i;
	}
	cout << "compare :" << comp << " times\n";
	cout << "swap :" << ret << " times\n";

	return ret;
}

//该算法在每次外循环内，发生交换的值，有一个位置是固定的，而不是概念中的相邻元素
//，该算法并不会改变排序需要进行的交换次数和比较次数，
//与算法一一样在原序列为刚好逆序时，消耗最大
int bubbleSort_2(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Bubble sort 2   **************************"<<endl;

	int ret,i,j,temp,comp;
	ret = comp = 0;
	for (i = 0; i < size-1; ++i)
	{
		int step_swap = 0;
		cout << "i = " << i << ":";
		for (j = i; j < size; ++j)
		{
			if (less_than(arr[j], arr[i], &comp))
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				++ ret;
				++ step_swap;
			}
		}
		for(int n = 0; n < size; ++n)
			cout << arr[n] << " ";
		cout << "swap " << step_swap << " times";
		cout<<endl;
	}
	cout << "compare :" << comp << " times\n";
	cout << "swap :" << ret << " times\n";

	return ret;
}

//该算法在每次外循环内，首先定位最大元素的下标，即选择最大元素，然后再进行必要的交换
//该算法减少了数据元素的交换次数，对于大的自定义数据类型，性能会有明显的提升
int bubbleSort_3(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Bubble sort 3   **************************"<<endl;

	int ret,i,j,temp,comp;
	ret = comp = 0;
	int top = size - 1;
	for(i = size-1; i > 0; --i)
	{
		int step_swap = 0;
		cout << "i = " << i << ":";
		for (j = 0; j < i; ++j)
		{
			if (less_than(arr[top], arr[j], &comp))
			{
				top = j;
			}
		}

		if (less_than(arr[i], arr[top], &comp))
		{
			temp = arr[top];
			arr[top] = arr[i];
			arr[i] = temp;
			++ ret;
			++ step_swap;
		}
		for(int n = 0; n < size; ++n)
			cout << arr[n] << " ";
		cout << "swap " << step_swap << " times";
		cout<<endl;
	}
	cout << "compare :" << comp << " times\n";
	cout << "swap :" << ret << " times\n";

	return ret;
}