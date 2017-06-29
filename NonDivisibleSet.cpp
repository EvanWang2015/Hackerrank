/*
Non-dividible subset

Given a set, S, of n distinct integers, print the size of a maximal subset, S', of S where the sum of any 2 numbers in S' is not evenly divisible by k
*/
//Approach 1: brute-force method, however, it causes time-out when dataset is too large. 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin>>n>>k;
    
    vector<int> subSet;
    vector<int> set;
    int max_subSet =0;
    int temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        set.push_back(temp);
    }
    
    for(int i=0; i<n; i++){
        subSet.push_back(set[i]);
        //cout<<"i= "<<i<<" "<< set[i]<<" ";
        for(int j =0; j<n; j++)
        {
            if(i!=j)
            {
                bool flag = true;
                for(vector<int>::iterator it=subSet.begin(); it!=subSet.end(); it++)
                {
                    if((*it+set[j])%k==0)
                    {
                        flag = false;
                        break;
                    }
                }
                
                if(flag)
                {
                    subSet.push_back(set[j]);
                    //cout<<set[j]<<" ";
                }
                
            }
        }
        
        //cout<<endl;
        if(max_subSet<subSet.size())
            max_subSet = subSet.size();
        subSet.clear();
    }
    
   cout<<max_subSet<<endl;
    
    return 0;
}

