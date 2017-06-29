/*
ACM ICPC Team

You are gien a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not.
Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>         // std::bitset

using namespace std;

int bit_count(string s1, string s2){
    int count=0;
    for(int i=0; i<s1.size(); i++){
        if(s2.at(i)=='1' || s1.at(i)=='1') 
            count++;
    }
    return count;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    
    int max_topics=-1;
    int group_count=0;
    for (int i=0; i<n; i++)
    {
        
        for(int j=i+1; j<n; j++)
        {           
            int result = bit_count(topic[i], topic[j]); 
            
            if(max_topics==result) 
            {
                group_count++;
            }
            if(max_topics<result)
            {
                max_topics = result;
                group_count = 1;
            }
                 
            

        }
    }
    cout <<max_topics<<endl;
    cout <<group_count<<endl;
    return 0;
}
