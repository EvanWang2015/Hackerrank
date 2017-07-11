/*
Radio transmitter installation
Hackerland is a one-dimensional city with n houses, when each house i is located at some x_i on the x-aixs. The 
Mayor wants to install transmitters on the roof of the city's houses. Each transmitter has a range, k, meaning it can transmit a signal to all
houses <=k units of distance away. 

Given a map of hackerland and the value of k, can you find the minimum number of transmitters needed to cover every house in the city?
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    
    sort(x.begin(), x.end());
    
    int num =0;
    int start;
    for(int i=0; i<n;i++)
    {
        start = x[i];
        //cout<<"start: "<<x[i]<<endl;
        while(i+1<n && x[i+1]-start<=k)
        {
            i++;
        }
        num++;
        start = x[i];
        //cout<<"Station: "<< x[i]<<endl;
        while(i+1<=n-1 && x[i+1]-start<=k)
        {
            i++;
            
        }
       
        
    }

    cout<<num<<endl;
    return 0;
}

