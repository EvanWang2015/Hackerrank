/*
Two Strings

Given two strings, a and b, determine if they share a common substring.
*/
#include <bits/stdc++.h>

using namespace std;

string twoStrings(string s1, string s2){
    // Complete this function
    vector<int> sv1,sv2;
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
        if(sv1[i]>0 && sv2[i]>0)
            return "YES";
    }
    return "NO";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        string result = twoStrings(s1, s2);
        cout << result << endl;
    }
    return 0;
}

