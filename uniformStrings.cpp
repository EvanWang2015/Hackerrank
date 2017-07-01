/*
Uniform strings
*/
//the logic to use map is fine. However, it can be expensive. 

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int char_toValue(string s){
    int value = 0;
    for(int i=0; i<s.size(); i++)
    {
        value =value + int(s.at(i))-int('a')+1;
    }
   // cout<<"string: " <<s << " value: " <<value <<endl;
    return value;
}
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<string, int> uniform;
    string subString;
    int startP =0;
    int endP =0;
    //cout<<"total size of string: " << s.size()<<endl;
     for(int i=0; i<s.size(); )
     {
         startP =i;
         endP = i+1;
         uniform[string(1,s.at(i))]++;
         //cout<<s.at(i)<<endl;
         while(endP<s.size()  && s.at(i)==s.at(i+1))
          {
              i++; 
              endP++;
              subString = s.substr(startP,endP-startP);
              uniform[subString]++;
              //cout<<subString<<endl;
          }                 
         i=endP;
     }
    
    for(map<string, int>::iterator it=uniform.begin(); it!=uniform.end(); it++)
    {
        int i=0;
        it->second=char_toValue(it->first);
        cout <<"index" << i++<<" "<<  char_toValue(it->first)<<endl;
    }
    vector<int> looking;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin>>x; 
        looking.push_back(x);                    
    }
    sort(looking.begin(), looking.end());
    

    return 0;
}
