//Breaking a record
/*
Maria plays n games of college basketball in a season. Because she wants to go pro, she tracks her points scored per game sequentially in an array defined as score =[s_0, s_1,..., s_n-1]. 
After each game , she checks to see if score  breaks her record for most or least points scored so far during that season.
Given Maria's array of  for a season of  games, find and print the number of times she breaks her record for most and least points scored during the season.
Note: Assume her records for most and least points at the start of the season are the number of points scored during the first game of the season.
*/

#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    // Complete this function
    //record[0] is highest 
    //record[1] is lowest 
 
    vector<int> record={0, 0}; 
    int max =s[0];
    int min = s[0];

    for (vector<int>::iterator it =(s.begin())+1; it !=s.end(); it++){
        if(*it>max)
        {
            max = *it;
            record[0]++;
        }
        
        if(*it<min)
        {
            min= *it;
            record[1]++;
        }
    }
    return record;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
