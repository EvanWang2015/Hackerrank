/*
Fraudulent Activity Notifications
Deque application in finding median 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void SortInsertion(vector<double> &v, double elem){
    int n = v.size();
    int l = 0; int r = n,m;
    while(r - l > 1){
        m = (l+r)/2;
        if(v[m] <= elem)
            l = m;
        else
            r = m;
    }
    v.insert(v.begin()+m,elem);
}

void SortDelete(vector<double> &v, double elem){
    int n = v.size();

    int l = 0,r = n,m;
    while(r-l > 1){
        m = (l+r)/2;
        if(v[m] <= elem)
            l = m;
        else r = m;
    }
    v.erase(v.begin()+m-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,d,res = 0;
    cin >> n >> d;
    vector<double> AN(n),AD(d);
    for(int i = 0; i < n; i ++) cin >> AN[i];
    AD.assign(AN.begin(),AN.begin()+d);
    sort(AD.begin(),AD.end());
    for(int i = d; i < n; i++){                
        double mean;
        if(d % 2 == 1){
            mean = AD[d/2];            
        }
        else{
            double d1 = AD[d/2 -1];
            double d2 = AD[d/2];
            mean = (d1+d2)/2;
        }        
        if(2*mean <= AN[i]) 
            res++;
        SortDelete(AD,AN[i-d]);
        SortInsertion(AD,AN[i]);
    }
    cout << res;
    return 0;
}