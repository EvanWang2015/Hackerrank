/*
Big string sorting_simple
*/

#include <bits/stdc++.h>

using namespace std;

bool myfunction(string s1, string s2)
{
    int a=s1.size();
    int b = s2.size();
    if(a == b)
        return s1<s2;
    else
        return a<b;
}
int main() {
    int n;
    cin>>n;
    vector <string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    
    sort(arr.begin(),arr.end(),myfunction);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    
    return 0;
}
