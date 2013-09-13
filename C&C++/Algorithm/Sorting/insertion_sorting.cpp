#include <iostream>
using namespace std;

#include "compare.h"
#include "rdirect.h"

int insertionSort_1(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Insertion sort 1   **************************"<<endl;

	int ret,i,j,p,comp;
	ret = p = comp = 0;
	for(i = 1; i < size; ++i,++p)
	{
		int step_swap = 0;
		cout << "i = " << i << ":";
		if(less_than(arr[i], arr[p], &comp)) 
		{
			j = i;
			while(less_than(arr[j], arr[j-1], &comp) && j > 0) {
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				--j;
				++ step_swap;
				++ ret;
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

//该算法需要引入额外的空间为O(1)
int insertionSort_2(int *arr, int size)
{
	rdirect out("D:\\output.txt");

	cout<<"****************   Insertion sort 2   **************************"<<endl;

	int i,j,ret,comp;
	ret = comp = 0;
	for (i = 1; i < size; i++)
	{
		int step_swap = 0;
		cout << "i = " << i << ":";
		int temp = arr[i];
		j = i;
		for (j=i; j>0 && less_than(temp, arr[j-1], &comp); j--) {
			arr[j] = arr[j-1];
			++ step_swap;
			++ ret;
		}
		if (j!=i)
		{
			arr[j] = temp;
			++ step_swap;
			++ ret;
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