#include <iostream>
#include <string>
#include "mcomplex.h"
using namespace std;

template<typename T>
void elem_swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//����������N-1��������ɡ�����i=1��N-1�ˣ���������֤��0��λ��i�ϵ�Ԫ��Ϊ������״̬��
//�������������Ĳ����ǣ��ڵ�i���������ǽ�λ��i�ϵ�Ԫ��������������ǰi+1��Ԫ���е���ȷλ���ϡ�
template<typename T>
void insertion_sort(T *arr, int size)
{
	int i,j;
	for(i = 1; i < size; i++) {
		T tmp = arr[i];
		for(j = i; j > 0 && arr[j-1] > tmp; j--)
			arr[j] = arr[j-1];
		arr[j] = tmp;
	}
}

//л��������ͨ���Ƚ����һ�������Ԫ�������������˱Ƚ����õľ��������㷨�Ľ��ж���С
//����Բ���������Ż����Ǽ����˶��󽻻��Ĵ�������Ϊ�����ն�Ҫ�ع鵽��������Ϊ1�������
//����ʱ���봦��������������һ����
//���⣬�����������У���õ�ͨ�ʽ�ǣ���ѧ��ʽ���޷���
template<typename T>
void shell_sort(T *arr, int size)
{
	int gap = size / 2;
	for (; gap > 0; gap /= 2)
	{
		int i,j;
		for (i = gap; i < size; i += gap)
		{
			T tmp = arr[i];
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

//�鲢�����㷨�Ļ�������ʱ�ϲ�����������ı���Ϊ��������ʾ������ģ���������
//����ŵ���3����������㷨����ͨ������������һ����������ɡ�
template<typename T>
void mergesorted(T *arr, T *tmpArr, int l, int c, int r)
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

template<typename T>
void mergesort(T *arr, T *tmpArr, int l, int r)
{
	if(l < r)
	{
		int c = (l + r) / 2;
		mergesort(arr, tmpArr, l, c);
		mergesort(arr, tmpArr, c+1, r);
		mergesorted(arr, tmpArr, l, c+1, r);
	}
}

template<typename T>
void merge_sort(T *arr, int size)
{
	T *tmpArr = new T[size];
	mergesort(arr, tmpArr, 0, size-1);
	delete []tmpArr;
}

//��������
template<typename T>
T& median3(T *arr, int l, int r)
{
	int c = (l + r) / 2;
	if(arr[c] < arr[l])
		elem_swap(arr[c], arr[l]);
	if(arr[r] < arr[l])
		elem_swap(arr[r], arr[l]);
	if (arr[r] < arr[c])
		elem_swap(arr[r], arr[c]);

	elem_swap(arr[c], arr[r-1]);
	return arr[r-1];
}

template<typename T>
void quicksort(T *arr, int l, int r)
{
	if(l + 10 <= r)
	{
		T pivot = median3(arr, l, r);
		int i = l, j = r-1;
		for (;;)
		{
			while(arr[++i] < pivot) {}
			while(arr[--j] > pivot) {}
			if(i < j)
				elem_swap(arr[i], arr[j]);
			else
				break;
		}
		elem_swap(arr[i], arr[r-1]);
		quicksort(arr, l, i-1);
		quicksort(arr, i+1, r);
	}
	else
		insertion_sort(arr+l, r-l+1);
}

template<typename T>
void quick_sort(T *arr, int size)
{
	quicksort(arr, 0, size-1);
}

int main(int argc, char *argv[])
{
	string str;
	cout<<"Please enter the algorithm(insertion, shell, merge, quick)";
	cout<<"\nor enter quit to exit the program:";
	cin>>str;
	while (str != "quit")
	{
		//int arr[20] = {5, 15, 8, 3, 2, 17, 10, 6, 14, 19, 1, 13, 0, 12, 7, 4, 16, 11, 18, 9};
		//int size = sizeof(arr)/sizeof(int);
		//char arr[26] = {'f','w','g','z','c','t','d','b','q','e','r','y','u','i','o','p','a','s','h','j','k','l','x','v','n','m'};
		//int size = sizeof(arr)/sizeof(char);
		mcomplex arr[20] = {mcomplex(15, 5), mcomplex(7, 15), mcomplex(9, 8), mcomplex(1, 3), mcomplex(13, 2), 
			mcomplex(2, 17), mcomplex(5, 10), mcomplex(17, 6), mcomplex(0, 14), mcomplex(4, 19), mcomplex(19, 1), 
			mcomplex(8, 13), mcomplex(10, 0), mcomplex(3, 12), mcomplex(18, 7), mcomplex(11, 4), mcomplex(12, 16), 
			mcomplex(6, 11), mcomplex(14, 18), mcomplex(16, 9)};
		int size = sizeof(arr)/sizeof(mcomplex);
		if(str == "insertion") {
			insertion_sort(arr, size);
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
		cout<<"Please enter the sorting algorithm(insertion, shell, merge, quick):";
		cin>>str;
	}
	system("pause");
	return 0;
}