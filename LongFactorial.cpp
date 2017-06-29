/*Super long factorial*/
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> d;
    d.push_back(1);
    
    for (int i = 2; i <= n; ++i) {
    //Multiplication for each digit in the vector
        for (auto it = d.begin(); it != d.end(); ++it)
            *it =*it * i;

        int carry=0;
        for(int i=0; i<d.size(); i++)
        {
            if(d[i]>=10)
            {
                carry = d[i]/10;
                d[i] = d[i]%10;
                if(i+1>=d.size())
                    d.push_back(carry);
                else
                    d[i+1]=d[i+1]+carry;
            }
        }        
    }
    for (auto it = d.rbegin(); it != d.rend(); ++it)
        cout << *it;   
    return 0;
}