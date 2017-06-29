/*How many times you have to turn your pages
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int p){
    // Complete this function
    int front =0;
    int back = 0;
    if(p%2==0){
        front = (p+1)/2;
    }
    else{
        front = (p+1)/2-1;
    }
    //open the book from the backside
    if(n%2 ==0 && p%2!=0){
        back = (n-p)/2+1;
    }
    else{
        back = (n-p)/2;
    }
    
    //cout<<"front: " << front <<endl;
   //cout << "back: " << back<<endl;
    if(front<back)
        return front;
    else
        return back; 
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}

