#include <iostream>
using namespace std;

#include "compare.h"
#include "rdirect.h"

//��ð�������㷨��������ֱ��ʵ�ֵ��㷨�����㷨��Ҫ���ıȽϴ����ͽ�������
//����ԭ����Ϊ�պ�����ʱ���������
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

//���㷨��ÿ����ѭ���ڣ�����������ֵ����һ��λ���ǹ̶��ģ������Ǹ����е�����Ԫ��
//�����㷨������ı�������Ҫ���еĽ��������ͱȽϴ�����
//���㷨һһ����ԭ����Ϊ�պ�����ʱ���������
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

//���㷨��ÿ����ѭ���ڣ����ȶ�λ���Ԫ�ص��±꣬��ѡ�����Ԫ�أ�Ȼ���ٽ��б�Ҫ�Ľ���
//���㷨����������Ԫ�صĽ������������ڴ���Զ����������ͣ����ܻ������Ե�����
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