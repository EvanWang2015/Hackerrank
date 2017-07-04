/*
String Construction

Amanda has a string, s, of m lowercase letters that she wants to copy into a new string, p. She can perform the following operations any number of times to
construct string p:

1) Append a character to the end of string p at cost of 1 dollar.
2) Choose any substring of p and append it to the end of p at no charge.
*/

#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s){
    // Complete this function
    vector<int> sv;
    sv.assign(26,0);
    int op=0;
    for(int i=0; i<s.size(); i++)
    {
        if(sv[s.at(i)-'a']==0)
        {
            sv[s.at(i)-'a']++;
            op++;
        }           
    }
    return op;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = stringConstruction(s);
        cout << result << endl;
    }
    return 0;
}
