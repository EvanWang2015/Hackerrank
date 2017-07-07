/*
However, for certain types of input, it is more efficient to use a non-comparison sorting algorithm. This will make it possible to sort lists even in linear time.
These challenges will cover Counting Sort, a fast way to sort lists where the elements have a small number of possible values, such as integers within a certain range. 
We will start with an easy task - counting.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int arr [100] ={0};
    cin>>n;
    int tem;        
    for(int i=0; i<n; i++)
    {
        cin>>tem;
        arr[tem]++;
    }
    


    for(int i=0; i<100; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
