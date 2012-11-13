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