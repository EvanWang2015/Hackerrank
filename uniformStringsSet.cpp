
#include <bits/stdc++.h>
using namespace std;
//uniform strings using Set.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    //build the set
    set<int> st;
    int last = -1;
    int num = 0;
    for(int i = 0; i<s.length(); ++i)
    {
        if(s[i] == last)
        {
            num +=tolower(s[i])-'a'+1;
        }
        else
        {
            num = tolower(s[i])-'a'+1;
            last = s[i];
        }
        st.insert(num);
    }
    //retrieve from the set
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        if
            (st.count(x)) cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
        
    return 0;
}
