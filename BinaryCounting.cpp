/*
Counter Game 

Louise and Richard play a game. THey have a counter set to N. In every game, Louise gets the first turn and the turns alternate thereafter. 
In the game, they perform the following operations.
. if N is not a power of 2, reduce the counter by the largest power of 2 less than N.
. If N is a power of 2, reduce the counter by half of N. 

The best part of the code is the way how you count the number of 1s.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int setBits(unsigned long long int n)
{
    int count =0; 
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n;
        cin>>n;
        
        //cout<<setBits(n)<<endl;
        if(setBits(n-1) & 1) 
            printf("Louise\n");
        else
            printf("Richard\n");
    }

        
    return 0;
}
