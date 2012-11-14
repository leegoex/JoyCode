#include <iostream>
using namespace std;

void elem_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

//����������N-1��������ɡ�����i=1��N-1�ˣ���������֤��0��λ��i�ϵ�Ԫ��Ϊ������״̬��
//�������������Ĳ����ǣ��ڵ�i���������ǽ�λ��i�ϵ�Ԫ��������������ǰi+1��Ԫ���е���ȷλ���ϡ�
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

//л��������ͨ���Ƚ����һ�������Ԫ�������������˱Ƚ����õľ��������㷨�Ľ��ж���С
//����Բ���������Ż����Ǽ����˶��󽻻��Ĵ�������Ϊ�����ն�Ҫ�ع鵽��������Ϊ1�������
//����ʱ���봦��������������һ����
//���⣬�����������У���õ�ͨ�ʽ�ǣ���ѧ��ʽ���޷���
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

//�鲢�����㷨�Ļ�������ʱ�ϲ�����������ı���Ϊ��������ʾ������ģ���������
//����ŵ���3����������㷨����ͨ������������һ����������ɡ�
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

//��������
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
	int arr[10] = {5, 1, 8, 3, 2, 7, 0, 6, 4, 9};
	//insertion_sort2(arr, 10);
	//shell_sort(arr, 10);
	//merge_sort(arr, 10);
	quick_sort(arr, 10);
	int i = 0;
	for(i = 0; i < 10; i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
	system("pause");
	return 0;
}