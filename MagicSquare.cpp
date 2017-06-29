/*
Forming a Magic Square
The resulting magic square must contain distinct integers in the inclusive range [1,9].
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> magicArray=  {{{8,1,6},{3,5,7},{4,9,2}},
                                          {{6,1,8},{7,5,3},{2,9,4}},
                                          {{4,9,2},{3,5,7},{8,1,6}},
                                          {{2,9,4},{7,5,3},{6,1,8}},
                                          {{8,3,4},{1,5,9},{6,7,2}},
                                          {{4,3,8},{9,5,1},{2,7,6}},
                                          {{6,7,2},{1,5,9},{8,3,4}},
                                          {{2,7,6},{9,5,1},{4,3,8}}};

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    int sum=0;
    vector<int> dif(8,0);
    for(int s_i = 0;s_i < 3;s_i++){
       sum = 0;
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];           
       }
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<3; j++){
            for (int z =0; z<3; z++){
             dif[i]= abs(magicArray[i][j][z]-s[j][z]) + dif[i];   
            }
        }
    }
    sort(dif.begin(), dif.end());
    //  Print the minimum cost of converting 's' into a magic square
    cout<<dif[0];
    return 0;
}
