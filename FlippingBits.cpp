/*
Flipping bits

You will be given a list of 32 bits unsigned integers. You are required to output the list of the unsigned integers you
get by flipping bits in its binary representation.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    
    
    cin>>n;
    while(n--)
    {
        bitset<32> input;
        unsigned int sample;
        cin>>sample;
        //input.flip();
        //unsigned long ul = input.to_ulong();
        cout<<(unsigned )~sample<<endl;
    }
    return 0;
}
