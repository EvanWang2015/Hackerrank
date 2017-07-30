/*
You are given n non-negative integers, a_0, a_1, .., a_n-1. We define the score for some permutation (p) of length n
to be the maximum of a_p_i xor a_p_i+1 for 0<=i<n-1.

Find the permutation with the minimum possible score and print its score.

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <bitset>
#include <stdlib.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<string> arr(n);
    unsigned int temp;
    unsigned int max = 0;
    unsigned int min = INT_MAX;
    for(int i=0; i<n; i++)
    {
        cin>>temp;        
        arr[i]=bitset<30> (temp).to_string(); 
        if(max<temp)
            max=temp;
    }
    
    int maxBits = 0;
    //cout<<max<<endl;
    while(max)
    {
        maxBits++;
        max = max>>1;
    }
    
    sort(arr.begin(), arr.end());
    
    int bitN, rowN;
    bool flag = false;
    //cout<<maxBits<<endl;
    for(int i=30-maxBits; i<=29; i++)
    {
        for(int j=0; j<n-1; j++)
        {
           if(arr[j].at(i)!=arr[j+1].at(i))
            {
                bitN=i;
                flag = true;
                rowN=j;
                break;
            }
            
        }
        
        if(flag)
           break;
    }
    
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int res = INT_MAX;
    
    for(int i=0; i<=rowN; i++)
    {
        for(int j=rowN+1; j<n; j++)
        {
            a = bitset<30>(arr[i]).to_ullong();
            b = bitset<30>(arr[j]).to_ullong();
            temp = a^b;
            if(temp<res)
                res=temp;            
        }
    }
    //res=res;
    cout<<res<<endl;
   
    return 0;
}
