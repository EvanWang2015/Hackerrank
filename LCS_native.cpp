/*
Dynamic Programming | longest Common Subsequence
Native Solution: complexity O(2^n)
Let L(x[0..m-1], Y[0..n-1]) be the length of LCS of the two sequences X and Y.
Following is the recursive defintion of L(X[0..m-1], Y[0..n-1])

1) The the last characters of both sequences match then 
L(X[0..m-1], Y[0..n-1]) = 1+L(X[0..m-2],Y{0..n-2])
2) If last characters of both sequences do not match then 
L(X[0..m-1], Y[0..n-1]) = MAX(L(X[0..m-2],Y[0..n-1]), L(X[0..m-1],Y[0..n-2])
*/

#include <bits/stdc++.h>

using namespace std;
int max(int a, int b)
{
    return a>b? a: b;
}
int commonChild(string& s1, string& s2, int m, int n){
    // Complete this function
    if(m==0 || n==0)
        return 0;
    
    if(s1.at(m-1)==s2.at(n-1))
        return 1 + commonChild(s1, s2, m-1, n-1);
    else
        return max(commonChild(s1,s2, m, n-1), commonChild(s1,s2, m-1,n));
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int m = s1.size();
    int n = s2.size();
    int result = commonChild(s1, s2, m,n);
    cout << result << endl;
    return 0;
}
