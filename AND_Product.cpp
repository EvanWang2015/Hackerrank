/*
AND PRODUCT
Consider two non-negative long integers, a and b, where a<=b.

The bitwise AND of all long integers in the inclusive range between a and b can be expressed as a&(a+1)&(a+2)&...&(b-1)&b
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
    cin>>n;
    while(n--)
    {
        unsigned long int a, b;
        cin>>a>>b;
        int t=b-a;
        unsigned long int res=a;
        int i=0;
        while(pow(2,i)<=t)
        {
            res = res & (unsigned long int)(a+pow(2,i));
            i++;            
        }
        res = res &b;
        cout<<res<<endl;
    }
    return 0;
}
