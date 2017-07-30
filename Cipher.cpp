/*
Cipher
Jack and Daniel are friends. THey want to encrypt their conversation so that they can save themselves from interception by a detective agency.

So they invent a new cipher. 
Every message is encoded to its binary representation B of length N.
Then it is written down K times, shifted by 0, 1, ..., K-1 bits.
If B = 1001010 and K = 4 it look so:
1001010
 1001010
  1001010
   1001010
-----------
1110100110
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, t;
    cin>>n>>t;
    
    string s;
    cin>>s;
    
    string res="";
    vector<int> nums(2);
    res=s.at(0);
    int start;
    for(int i=1; i<n; i++)
    {        
        nums[res[i-1]-'0']++;        
        if(nums[1]%2!=0)
        {
            if(s.at(i)=='1')
                res+="0";
            else
                res+="1";
        }
        else
        {
            if(s.at(i)=='1')
                res+="1";
            else
                res+="0";
        }
        
        if(i>=t-1)
            nums[res[i-t+1]-'0']--;  
    }
    cout<<res<<endl;
    return 0;
}
