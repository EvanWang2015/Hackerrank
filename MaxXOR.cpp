/*
Mamimizing XOR

Given two integers, L and R, find the maximul vlaue of A xor B, where A and B satisfy the following condition:
L<=A<=B<=R
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */

int maxXor(int l, int r) {
    
    int MaXor = 0;
    //int tem;
    unsigned int tem;
    for(int i=l; i<=r; i++)
    {
        for(int j=i; j<=r; j++)
        {
            unsigned int a = i;
            unsigned int b = j;
            tem= a^b;
            if( tem > MaXor)
            {
                MaXor=tem;
           // cout<<"what?";
             }
        }         
    }
    
    return MaXor;

}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
