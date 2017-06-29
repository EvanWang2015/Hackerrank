//============================================================================
// Name        : Algorithms.cpp
// Author      : Evan Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
//#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return (b, a%b);
}

int lcm(int a, int b){
    return (a*b)/(gcd(a,b));
}

int getTotalX(vector < int > a, vector < int > b){
    // Complete this function
    int l, g;
    l = a[0];
    for(vector<int>::iterator it=a.begin(); it!=a.end(); it++){
        l=lcm(*it,l);
    }

    cout << l <<endl;
    g = *(b.begin());
    for(vector<int>::iterator it = b.begin()+1; it!=b.end(); it++){
        g = gcd(*it, g);
    }

    int count = 0;
    for(int i= l, j=2; i<=g; i=l*j, j++){
        if(g/i==0)
            count++;
    }
    return count;
}

int main() {
    int n;
    int m;
    //cin >> n >> m;
    n = 2; m = 3;
    vector<int> a={2, 4};
//    for(int a_i = 0; a_i < n; a_i++){
//       cin >> a[a_i];
//    }
    vector<int> b={16, 32, 96};//(m);
    // for(int b_i = 0; b_i < m; b_i++){
       // cin >> b[b_i];
    // }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
