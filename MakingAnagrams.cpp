/*
Making Anagrams
Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters
can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency.
*/
#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1, string s2){
    // Complete this function
    vector<int> sv1,sv2;
    sv1.assign(26,0);
    sv2.assign(26,0);
    int change =0;
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
        change = change+abs(sv1[i]-sv2[i]);
    }
    return change;
    
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = makingAnagrams(s1, s2);
    cout << result << endl;
    return 0;
}
