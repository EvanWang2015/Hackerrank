/*
Missing Numbers
Found miss matched frequency in two arrays
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin>>n; 
    
    map<int, int> arr1;
    map<int, int> arr2;
    map<int, int> dif; 
    int tem;
    for(int i=0; i<n; i++)
    {
        cin>>tem;
        arr1[tem]++;
    }
    
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>tem;
        arr2[tem]++;
    }
   
    map<int, int>::iterator it, it2;
    it = arr1.begin();
    it2 = arr2.begin();
    
    for(; it!=arr1.end() && it2!=arr2.end(); ++it, ++it2)
    { 
        tem = abs(it->second - it2->second);
        //cout<<it->first << " and "<<it->second<<" ";
        //cout<<it2->first<<" and "<<it2->second<<endl;
        if(tem!=0)
        {
            dif.insert(pair<int, int>(it->first,tem));
        }
    }
   // cout<<arr1.size() <<" and "<<arr2.size()<<endl;
   //cout<<dif.size()<<endl;
 
    
    
    for(it = dif.begin(); it!=dif.end(); ++it)
    {
        cout<<it->first<<" ";
    }
    return 0;
}
