/*
Maximum Palindromes.

A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as it does forward.

On her 7th birthday, Sandy's uncle, Richie Rich, offered her an n-digit check which she refused because the number was not a palindrome. 
Richie then challenged Sandy to make the number palindromic by changing no more than k digits. 
*/
#include <bits/stdc++.h>

using namespace std;

void richieRich(string s, int n, int k){
    // Complete this function
    vector<int> sNew;
    sNew.assign(s.size(),0);
    int len = s.size();
    int change = 0;
    int mid = len/2;
    for(int i=0; i<mid; i++)
    {
        if(s.at(i)==s.at(len-1-i))
        {
            sNew[i] = sNew[len-1-i] = s.at(i)-'0';
        }
        else
        {
            if(s[i]>s[len-1-i])
            {
                sNew[i] = sNew[len-1-i] = s.at(i)-'0';
            }
            else
            {
                sNew[i] = sNew[len-1-i] = s.at(len-1-i)-'0';
            }
            change++;
        }
    }
    if(len%2!=0)
    {
        sNew[mid] = s.at(mid)-'0';
    }
    
    if(change>k)
        cout<<-1;
    else{
       k = k-change;
       int j = 0;
       while(k)
       {
           if(k==1)
           {
               
               while((s.at(j)==s.at(len-j-1) || sNew[j]==9) && j<mid)
                   j++;
               
               if(j<mid)
               {
                   sNew[j] =9;
                   sNew[len-j-1] =9;
               }
               else
               {sNew[mid]=9;
                break;}
               k--;
           }
           
           else //k>=2
           {
              while(sNew[j]==9 && j<mid)
                  j++;
               
              if(j<mid)
              {
                  if(s.at(j)!=s.at(len-j-1))
                {
                  k--;
                  sNew[j] = sNew[len-j-1] =9;
                }
                else
                {
                   k= k-2;
                   sNew[j] = sNew[len-j-1] =9;
                }
              }
             else
             {
                   sNew[mid] =9;
                   break;
             }
               
               
           }
          
       }
        for(int i=0; i<s.size(); i++)
           cout<<sNew[i]; 
    }
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    richieRich(s, n, k);
    //cout << result << endl;
    return 0;
}
