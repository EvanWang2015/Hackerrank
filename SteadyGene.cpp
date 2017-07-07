/*
Steady Gene

A gene is represented as a string of length n (where n is divisible by 4), composed of letters A, C, T, and G. It is considered to be steady
if each of the four letters occurs exactly n/4 times. For example, GACT and AAGTGCCT are both steady genes.

Bear Lima is a famous biotechnology scientist who epecializes in modifying bear DNA to make it steady. Help Limak find the length of the smallest possible substring 
that the can replace to make the string to be steady.
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
    cin >>n;
    string s;
    cin >>s;
    //s = "TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC";
   // cout<<s.size()<<endl;
    int begin = 0;
    int last = s.size();
    //ACTG
    vector<int> count(26);
    int maxSize = s.size()/4;
    for(int i=0; i<s.size(); i++)
    {
        begin = i;
        count[s.at(i)-'A']++;
        if(count[s.at(i)-'A']>maxSize)
        {
            begin--;
            count[s.at(i)-'A']--;
            break;
        }
    }
    int Minlength = s.size()-begin-1;
    int current;
    for (; begin<last && begin>=0; begin--)
    {       
        while(true && last>begin)
        {
            last--;
            count[s.at(last)-'A']++;
            
            if(count[s.at(last)-'A']>maxSize)
            {
                count[s.at(last)-'A']--;
                last++;               
                current= s.size()-(begin+1) - (s.size()-last);
                Minlength = Minlength < current? Minlength : current;
                break;
            }
        }
        count[s.at(begin)-'A']--;
    }
    
    if(begin>last)
        Minlength = 0;
    
    cout<<Minlength<<endl;
    return 0;
}
