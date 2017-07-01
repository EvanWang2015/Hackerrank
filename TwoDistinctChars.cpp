/*
Two characters

String t always consists of two distinct alternating characters. For example, if string t's two distinct characters are x and y, then
t could be xyxyx, or yxyxy but not xxyy or xyyx.

You can convert some string s to string t by deleting characters from s. where you delete a character from s, you must delete all occurrences of it in s.
For example, if s = abaacdabd and you delete the character a, then the string becomes bdcdbd.
Given s, convert if the longest possible string t. Then print the length of string t on a new line; if no string t can be formed from s, print 0 instead.
*/

#include <bits/stdc++.h>

using namespace std;


template<typename A, typename B>
pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
multimap<B,A> flip_map(const std::map<A,B> &src)
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

bool nonDuplicate(string s){
    for (int i=0; i<s.size()-1; i++){
        if(s.at(i)==s.at(i+1))
            return false;
    }
    return true;
}
int maxLen(string s){
    // Complete this function  
    map<char, int> words;
    map<int,char>::reverse_iterator it;
    map<int,char>::reverse_iterator it2;
    char c;
    for(int i=0; i<s.size(); i++)
    {   
        words[s.at(i)]++;     
    } 
    
    int max_length =0;
    string twochar="";
    multimap<int, char> dst = flip_map(words); 
    multimap<int,char> dst2 = dst; //flip_map(words);
    //greedy algorithm to work through the map
    for(it = dst.rbegin(); it!=dst.rend();++it)
    {
       // cout << it->first << " and " << it->second <<endl;
        for(it2 = ++dst2.rbegin(); it2!=dst2.rend();it2++)
        {
             for(int i=0; i<s.size(); i++){
                 if(s.at(i)==it->second || s.at(i)==it2->second)
                     twochar = twochar +s.at(i);
             }
            
            if(nonDuplicate(twochar)){
                if(twochar.size()>max_length)
                    max_length = twochar.size();
            }
            twochar="";
        }       
    }
    return max_length;   
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
