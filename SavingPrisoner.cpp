/*
Saving the Prisoner
Separate M candies to N prisoner from Sth person. FInd out who will get the last candy?
*/

#include <bits/stdc++.h>

using namespace std;

long saveThePrisoner(int n, int m, int s){
    // Complete this function
    return ((s+m-1)%n)? (s+m-1)%n:n;
}

int main() {
    int t;
    cin >> t;
    //t = 1;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        int s;
        cin >> n >> m >> s;
        long result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
    return 0;
}

