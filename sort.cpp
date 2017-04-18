#include <stdio.h>
#include "sort.h"


void insertSort(int arr[], int arrLen)//≤Â»Î≈≈–Ú
{
	int key = 0;
	int i = 0, j = 0, k;
	for(i = 1; i < arrLen; i++)
	{
		key = arr[i];
		j = i -1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+] = key;
	}
}

void bubbleSort(int arr [ ],int len)//√∞≈›≈≈–Ú
{
	int i, j, tmp;
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - i - 1; j++)
		{
			if(a[j] > a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}		
		}
	}
}

void selectSort((nt arr[], int len)//—°‘Ò≈≈–Ú
{
	int i , j , max, idenx;
	for(i = 0; i < len ; i++)
	{
		max = i;
		for(j = i+1; j < len; j++)
		{
			if(arr[max] < a[j])
			{
				max = j;
			}
		}
		if (i != max)
		{
			int tmp  = a[i];
			arr[i] = arr[max];
			arr[max] = tmp;
		}
		
	}
}

void merge(int arr[], int start , int mid, int end)
{
	int leftLen = mid - start +1;
	int rightLen = end  - mid;

	int leftArr[leftLen] , rightArr[rightLen];

	int i , j , k;
	for(i = 0; i < leftLen; i++)
		leftArr[i] = arr[start + i];
	for(j = 0; j < rightLen; j++)
		rightArr[j] = arr[mid + 1 + j];

	i = j = k = 0;
	while(i < leftLen && j < rightLen)
	{
		if(leftArr[i] < rightArr[j])
			arr[k++] = leftArr[i++];
		else
			arr[k++] = rightArr[j++];
	}

	while(i < leftLen)
		arr[k++] = leftArr[i++];
	while(j < rightLen)
		arr[k++] = rightArr[j++];
	
	return 0;
	
	
}
void sort(int arr[], int start, int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;
		sort(start , mid);
		sort(mid + 1, end);
		merge(arr, start ,mid ,end);
	}
	return;
}


