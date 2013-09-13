#include <iostream>
using namespace std;

#include "compare.h"
#include "rdirect.h"

int shellSort_1(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Shell sort 1  **************************"<<endl;

	int ret,comp;
	ret = comp = 0;
	int step_size = size / 2;
	while (step_size > 0)
	{
		int step_swap = 0;
		cout << "step size = " << step_size << ":";
		for (int i = step_size; i < size; i += step_size)
		{
			int j = i;
			int temp = arr[i];
			for (j = i; j >= step_size && less_than(temp, arr[j-step_size], &comp); j -= step_size) 
			{
				arr[j] = arr[j-step_size];
				++ step_swap;
				++ ret;
			}
			if (j != i)
			{
				arr[j] = temp;
				++ step_swap;
				++ ret;
			}
			
		}
		step_size /= 2;
		for(int n = 0; n < size; ++n)
			cout << arr[n] << " ";
		cout << "swap " << step_swap << " times";
		cout<<endl;
	}
	cout << "compare :" << comp << " times\n";
	cout << "swap :" << ret << " times\n";

	return ret;
}

int shellSort_2(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Shell sort 2  **************************"<<endl;

	int ret,comp;
	ret = comp = 0;
	int step_size = 0;
	while (step_size < size)
	{
		step_size = step_size*3+1;
	}

	while (step_size > 0)
	{
		int step_swap = 0;
		cout << "step size = " << step_size << ":";
		for (int i = step_size; i < size; i += step_size)
		{
			int j = i;
			int temp = arr[i];
			for (j = i; j >= step_size && less_than(temp, arr[j-step_size], &comp); j -= step_size) 
			{
				arr[j] = arr[j-step_size];
				++ step_swap;
				++ ret;
			}
			if (j != i)
			{
				arr[j] = temp;
				++ step_swap;
				++ ret;
			}

		}
		step_size = (step_size-1)/3;
		for(int n = 0; n < size; ++n)
			cout << arr[n] << " ";
		cout << "swap " << step_swap << " times";
		cout<<endl;
	}
	cout << "compare :" << comp << " times\n";
	cout << "swap :" << ret << " times\n";

	return ret;
}