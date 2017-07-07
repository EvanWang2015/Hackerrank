/*
CountingSortIndex
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> a[100];
string str;;
int n,i,j,x;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    cin>>n;
    for(i=0;i<n/2;i++)
    {
        cin>>x;
        cin>>str;
        a[x].push_back("-");
    
    }
    
    for(;i<n;i++)
    {
        cin>>x;
        cin>>str;
        a[x].push_back(str);
    
    }
    
    for(i=0;i<100;i++)
    {
        x=a[i].size();
        for(j=0;j<x;j++)
            cout<<a[i][j]<<" ";    
    }
    return 0;

}
