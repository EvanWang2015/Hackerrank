/*
Game of Thrones-1
To lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lower case English letters. Help him figure out
whether any anagram of the string can be a palindrome or not.
*/
#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s){
    // Complete this function
    vector<int> sv;
    sv.assign(26,0);
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        sv[s.at(i)-'a']++;
    }
    
    if(s.size()%2==0)
    {
        for(int i=0; i<26; i++)
        {
            if(sv[i]%2!=0)
                return "NO";
        }
        return "YES";
    }
    else
    {
        for(int i=0; i<26; i++)
        {
            if(sv[i]%2!=0)
                flag++;
        }
        if(flag!=1)
            return "NO";
        return "YES";                               
    }  
}

int main() {
    string s;
    cin >> s;
    string result = gameOfThrones(s);
    cout << result << endl;
    return 0;
}
