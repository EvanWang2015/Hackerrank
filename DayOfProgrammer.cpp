/*
Marie invented a Time Machine and wants to test it by time-traveling to visiti Russia on the Day of the Programmer (the 
256th day of the year) during a year in the inclusive range from 1700 to 2700.
*/
#include <bits/stdc++.h>

using namespace std;
bool lepYear(int year){
    if(year/400 ==0 ||(year%4==0 && year%100!=0))
        return true;
    return false;
}
string solve(int year){
    // Complete this function
   // cout <<lepYear(year)<<endl;
    if(lepYear(year)){
        int day = 256-(31+29+31+30+31+30+31+31);
        return to_string(day)+".09."+to_string(year);
    }
    else{
        int day = 256-(31+28+31+30+31+30+31+31);
        return to_string(day)+".09."+to_string(year); 
    }
    
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}