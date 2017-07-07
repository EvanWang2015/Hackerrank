/*
Sherlock and Anagrams
Given a string S, find the number of "unordered anagrammatic pairs" of substrings. In other words, find the numer of unordered pairs 
of substrings of S that are anagrams of each other.
Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string.
*/
#include <bits/stdc++.h>

using namespace std;
int check_anagram(string s1, string s2)
{
   vector<int> sv1, sv2;
   sv1.assign(26,0);
   sv2.assign(26,0);
   for(int i=0; i<s1.size(); i++)
   {       
       sv1[s1.at(i)-'a']++;
       
   }
    for(int i=0; i<s2.size(); i++)
   {
        sv2[s2.at(i)-'a']++;
       
   }
   
   for(int i=0; i<26; i++)
   {
       if(sv1[i]!=sv2[i])
           return 0;
   }
   return 1;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        
        string s;
        string sub1, sub2;

        cin>>s;
        
        int count = 0;
        int n=s.size();
        for(int len=1; len<n; len++)
        {
            for(int i = 0; i<n-len; i++)
            {
                sub1 = s.substr(i,len);

                for(int j =i+1; j<n-len+1; j++)
                {
                    sub2 = s.substr(j, len);

                    if(check_anagram(sub1,sub2)>0)
                     count++;                    
                }
            }     
        }
        
        cout <<count<<endl;
    }

    

    return 0;
}

