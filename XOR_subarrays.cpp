/*
Sansa and XOR

Sansa has an array. She wants to find the value obtained by XOR-ing the continuous subarrays, followed by XOR-ing the values thus obtained. 
Can you help her in this task?
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        if(n%2==0)
            cout<<0<<endl;
        else
        {
            int res=arr[0];
            for(int i=1; i<n; i++)
            {
                if(i%2==0)
                    res = res^arr[i];
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
