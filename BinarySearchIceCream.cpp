/*
BinarySearch
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;            
       }
};
 
bool compare(IceCream a, IceCream b)
{
    return a.flavor<b.flavor;
}

int binarySearch(int first, int last, vector<IceCream>&arr, int search) {
   int l=first, r=last;
   int m;
   while(l<=r)
   {
       m = (l+r)/2;
       if(arr[m].flavor==search)
           return arr[m].index;
       if(arr[m].flavor<search)
           l=m+1;
       else
           r=m-1;
   }
   
   return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        
        
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index)<< endl;
                    break;

                }
            }
            else
            {
                int index = binarySearch( 0, i-1, arr, search);
                 if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                 }
            }

        }
    
    }
    return 0;
}


