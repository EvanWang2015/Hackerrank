/*
QuickSort

Like Merge sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions that given array around the picked pivot.

There are many different versions of quicksort that pick pivot in different ways. 

*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

void swap(int* a, int* b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    
    for(int j=low+1; j<=high; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i],&arr[low]);

    return (i);
}

void quickSort(vector <int> &arr, int low, int high) {
   // Complete this function
    if(low<high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
