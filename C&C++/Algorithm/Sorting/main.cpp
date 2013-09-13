#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

extern int bubbleSort_1(int *arr, int size);
extern int bubbleSort_2(int *arr, int size);
extern int bubbleSort_3(int *arr, int size);

extern int insertionSort_1(int *arr, int size);
extern int insertionSort_2(int *arr, int size);

extern int shellSort_1(int *arr, int size);
extern int shellSort_2(int *arr, int size);

extern int quickSort_1(int *arr, int size);
extern int quickSort_2(int *arr, int size);

extern int mergeSort(int *arr, int size);

extern int heapSort(int *arr, int size);

int main(int argc, char *argv[])
{
	srand(time(0)); ////use current time as seed for random generator

	const int num = 1000;

	int rand_arr[num] = {0};
	int rand_size = sizeof(rand_arr)/sizeof(int);
	int *arr = new int[rand_size];
	cout << "Initial array : ";
	for (int i = 0; i < rand_size; ++i)
	{
		rand_arr[i] = rand() % num;
		cout<< rand_arr[i] << " ";
	}
	cout<<endl;
	
	memcpy(arr, rand_arr, sizeof(rand_arr));
	bubbleSort_1(arr, rand_size);
	
	memcpy(arr, rand_arr, sizeof(rand_arr));
	bubbleSort_2(arr, rand_size);
	
	memcpy(arr, rand_arr, sizeof(rand_arr));
	bubbleSort_3(arr, rand_size);
	
	memcpy(arr, rand_arr, sizeof(rand_arr));
	insertionSort_1(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	insertionSort_2(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	shellSort_1(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	shellSort_2(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	quickSort_1(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	quickSort_2(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	mergeSort(arr, rand_size);

	memcpy(arr, rand_arr, sizeof(rand_arr));
	heapSort(arr, rand_size);

	return 0;
}
