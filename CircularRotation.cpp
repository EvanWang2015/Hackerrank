/*
John Watson performs an operation called a right circular rotation on an array of integers, [a0, a1, ..., an-1]. After
performing one right circular rotation, the array is transformed from [a0, a1,..., a_n-1] to [an-1, a0,..., an-2].
Waston performs this operation k times. To test Sherlock's ability to identify the current element at a particular position in the
rotated array, Waston asks q queries, where each query consists of a single integer, m for which you must print the 
element at index m.
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
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
 // the key to this question is to find how many positions we need to change. 	
    int change = k%n;
    vector<int> a_new(n);
    for(int i=0; i<n; i++){
        if(change+i<n){
            a_new[change+i]=a[i];            
        }
        else{
            a_new[change+i-n]=a[i];
        }
    }
    for(int i=0; i<q; i++)
    {
        int m;
        cin >> m;
        cout<<a_new[m]<<endl;
    }      
    return 0;
}
