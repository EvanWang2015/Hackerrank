/*
Sherlock Valid String
Sherlock considers a string, s, to be valid if either of the following conditions are satisfied:
1. All characters in s have the same exact frequency. 
2. Deleting exactly 1 character from s will result in all its characters having the same frequency. 
*/
#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    // Complete this function
    vector<int> sv;
    sv.assign(26,0);
    for(int i=0; i<s.size(); i++)
    {
        sv[s.at(i)-'a']++;
    }
    int min=INT_MAX, max=0;
    int freMin =0;
    int freMax = 0;
    int length =0;
    for(int i=0; i<26; i++)
    {
        if(sv[i]!=0)
        {
            if(min>sv[i])
            {
                min=sv[i];
                freMin=0;
            }
            if(max<sv[i])
            {
                max = sv[i];
                freMax = 0;
            }
            
            if(min == sv[i])
            {
                freMin++;
            }
            if(max ==sv[i])
            {
                freMax++;
            }
            //cout<<to_string(i+'a')<< " "<<sv[i]<<endl;
        }
    }
    
   // if(freMin>1 && freMax>1 && freMin!=freMax) return "No";
    if(max==min)
        return "YES";
    else if(abs(max-min)>=1 && (freMin==1 || freMax==1) && (max*freMax+freMin*min==s.size()))
        return "YES";
    else 
        return "NO";
    //return ((abs(max-min)<=1) )  ? "YES":"NO";
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
