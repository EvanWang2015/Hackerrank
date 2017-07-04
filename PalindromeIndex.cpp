/*
Palindrome Index
Given a string, S, of lowercase letters, determine the index of the character whose removal will make S a palindrome.
If S is already a palindrome or no such character exists, then print -1.
THere will always be a valid solution, and any correct answer is acceptable. For example, if S = "bcbc", we can either remove 'b' at index 0 or 'c' at index 3.
*/

#include <bits/stdc++.h>

using namespace std;
bool palindrome(string& s)
{
    int mid;
    mid = (s.size()%2==0) ? s.size()/2 : s.size()/2+1;
    for(int i=0; i<mid; i++)
    {
        if(s.at(i)!=s.at(s.size()-1-i))
            return false;
    }
    return true;

}

int palindromeIndex(string s){
    // Complete this function

    
    int l = 0;
    int r = s.size()-1;
    
    while(l<r)
    {
        if(s.at(l)==s.at(r))
        {
            l++;
            r--;
        }
        else{
            break;
        }
    }
    
    if(l>=r)
        return -1;
    else
    {
        int left = l+1;
        int right = r;
        while(left<right)
        {
            if(s.at(left)==s.at(right))
            {
                left++;
                right--;
            }
            else
                break;
        }        
        if(left>=right)
            return l;
        else
            return r;
        
        
        
    }
    //memorize where it stops
    
    
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
