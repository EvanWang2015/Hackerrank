/*finding the most common birds*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    // Complete this function
    map<int,int> count;
    auto it = count.begin();
    for(int i=0; i<ar.size(); i++){
        
        it = count.find(ar[i]);
        if(it==count.end() || count.empty()){
            //it not exist in the map yet
            count.insert(pair<int,int>(ar[i], 1));
        }
        else{
            count[ar[i]]++;
        }
    }
    
    int max=0;
    int type =-1;
    // << count.size() << endl;
    for(it = count.begin(); it!=count.end(); it++){
        if(it->second > max)
        {
            max = it->second;
            type = it->first;
        }
        
    }
    return type;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
