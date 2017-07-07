/*
Quicksort, the last element as the pivot
*/
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    
    for(int j=low; j<=high-1; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return (i+1);
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
    return 0;
}
