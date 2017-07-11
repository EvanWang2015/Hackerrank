/*
Merge Sort for counting inversion

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
long long _mergeSort(vector<int>&arr, int temp[], int left, int right);
long long merge(vector<int> &arr, int temp[], int left, int mid, int right);

//sorts the input array and returns the number of inversions in the array
long long mergeSort(vector<int> arr, int array_size)
{
	int *temp = (int *)malloc(sizeof(int)*array_size);
	return _mergeSort(arr, temp, 0, array_size-1);
}


long long _mergeSort(vector<int> &arr, int temp[], int left, int right)
{
	int mid;
    long long inv_count = 0;
	if(right>left)
	{
		mid = (right+left)/2;

		//inversion count will sum of inversions in left-part, right-part and number of inversions in merging
		inv_count = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);

		//merge the two parts
		inv_count += merge(arr, temp, left, mid+1, right);
	}

	return inv_count;
}

long long merge(vector<int> &arr, int temp[], int left, int mid, int right)
{
	int i, j, k;
	long long inv_count = 0;
	i = left; //left subarrary
	j = mid; //right subarray
	k = left; //index for resultant merged subarray

	while((i<=mid-1) && (j<=right))
	{
		if(arr[i] <=arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
            inv_count = inv_count + (long long) mid-i;
		}

	}

	//copy the remaining elements of left subarray to temp*
	while(i<=mid-1)
	{
		temp[k++] = arr[i++];
	}

	while(j<=right)
	{
		temp[k++] = arr[j++];
	}

	for(i=left; i<=right; i++)
	{
		arr[i] = temp[i];
	}

	return inv_count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr;// ={9492052, 241944, 5743396, 5758608, 6053545};
        int tem;
        for(int i=0; i<n; i++)
        {
            cin>>tem;
            arr.push_back(tem);
        }

        long long shift=0;

        shift = mergeSort(arr, n);



        cout<<shift<<endl;
    }

    //cout<<"what?"<<endl;
    return 0;
}


