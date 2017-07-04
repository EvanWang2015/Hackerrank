/*
Anagram: Sid is obsessed with reading short stories. Being a CS student, he is doing some interesting frequency analysis with the books.
He choose strings S1 and S2 that |len(S1)-len(S2)|<=1.

*/
#include <bits/stdc++.h>

using namespace std;

int anagaram(string s){
    // Complete this function
    //cout<<s.size()%2<<endl;
    if(s.size()%2!=0)
    {
        return -1;
    }
    else
    {
        string s1 = s.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2);
        vector<int> s1v, s2v;
        s1v.assign(26,0);
        s2v.assign(26,0);
        int change=0;
        for(int i=0; i<s1.size(); i++)
        {
            s1v[s1.at(i)-'a']++;
            s2v[s2.at(i)-'a']++;
        }
        
        for(int i=0; i<26;i++){
            if(s1v[i]>s2v[i]&&s1v[i]!=0)
                change +=abs(s1v[i]-s2v[i]);
        }
        return change;
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagaram(s);
        cout << result << endl;
    }
    return 0;
}
