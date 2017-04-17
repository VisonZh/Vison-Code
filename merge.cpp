#include<iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


void merge(int arr[], int start, int mid, int end)
{
	int leftLen = mid - start + 1;
	int rightLen = end - mid;
	//int *leftArr = new int[leftLen];
	//int *rightArr =new int[right];
	int leftArr[leftLen];
	int rightArr[rightLen];
	int i , j, k;
	for( i = 0; i < leftLen; i++)
		leftArr[i] = arr[start + i];
	for( j = 0; j < rightLen; j++)
		rightArr[j] = arr[mid + 1 + j];

	i = j = 0;
	k = start;
	while(i < leftLen && j < rightLen)
	{
		if(leftArr[i] < rightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = rightArr[j++];
		}
	}

	while(i < leftLen)
		arr[k++] = leftArr[i++];
	while(j < rightLen)
		arr[k++] = rightArr[j++];

}
void sort(int arr[], int start, int end)
{
	int mid ;
	if(start < end)
	{
		mid = (start + end) / 2; 
		sort(arr,start, mid);
		sort(arr,mid + 1, end);
		merge(arr, start, mid , end);
	}
}

void printArr(int arr[], int len)
{
	int i ;
	for(i = 0; i< len ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;


}
void CreateRandArr(int arr[], int len)
{
	srand(time(NULL));
	for(int i = 0; i< len ; i++)
	{
		arr[i] = rand()%100+1;
	}

}

int main(void)
{
	//int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
	int *arr;
	int arrLen;
	cout << "Please input a array lenth:";
	cin >> arrLen;
	arr = new int[arrLen];
	memset(arr, 0 , sizeof(int));
	printArr(arr, arrLen);

	CreateRandArr(arr,arrLen);
	printArr(arr, arrLen);

	int start = 0; 
	int end = sizeof(arr)/sizeof(arr[0]) - 1;
	printf("start = %d, end = %d\n", start, end);
	sort(arr, 0 , arrLen - 1);
	printArr(arr, arrLen);

}
