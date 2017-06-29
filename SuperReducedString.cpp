/*
Super reduced string

Steve has a string, s, consisting of n lowercase English alphabetic letters. In one operation, he can delete any pair of adjacent letters
with the same value. For example, string "aabcc" would become "bcc" after 1 operation, and "b" after the second operation.

if the final string is Empty, print Empty String.
*/

#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    // Complete this function
    for(int i=1; i<s.size(); i++){
        if(s[i]==s[i-1])
        {
            s = s.substr(0, i-1) + s.substr(i+1);
            i=0;
           // cout<<s<<endl;
        }
        

    }
    return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    if (result.size())
         cout << result << endl;
    else
        cout<<"Empty String"<<endl;
    return 0;
}
