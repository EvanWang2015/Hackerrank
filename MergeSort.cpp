/*
MergeSort Counting Inversion
*/

#include<bits/stdc++.h>
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

//sorts the input array and returns the number of inversions in the array
int mergeSort(int arr[], int array_size)
{
	int *temp = (int *)malloc(sizeof(int)*array_size);
	return _mergeSort(arr, temp, 0, array_size-1);
}


