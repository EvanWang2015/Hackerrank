/*
Map Vector Merge overlapping segments
*/
// A C++ program for merging overlapping intervals
#include<bits/stdc++.h>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start, end;
};

// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(vector<Interval> &arr)
{
    // Test if the given set has at least one interval
    int n = arr.size();
    if (n <= 1)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals in increasing order of start time
    sort(arr.begin(), arr.end(), compareInterval);
 
    // push the first interval to stack
    s.push(arr[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);
 
        // Otherwise update the ending time of top if ending of current
        // interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    //cout << "\n The Merged Intervals are: ";
    arr.clear();
    while (!s.empty())
    {
        Interval t = s.top();
       // cout << "[" << t.start << "," << t.end << "] ";
        arr.push_back(t);
        s.pop();
    }
    return;
}
 
// Driver program
int main()
{
    map<int, vector<Interval>> train;
    //vector<Interval> arr =  { {6,8}, {1,9}, {2,4}, {4,7} };
    long n, m;
    int k;
    cin>>n>>m>>k;
    int r, c1, c2;
    map<int, vector<Interval>>::iterator it;
    
    for(int i=0; i<k; i++)  
    {
        cin>>r>>c1>>c2; 
        vector<Interval> &v = train[r];
        //train.insert(pair<int, vector<Interval>> (r,Interval(c1,c2)));
        //it = train.find(r);
        Interval tem;
        tem.start = c1;
        tem.end = c2;
        v.push_back(tem);
        mergeIntervals(v);
    }
    
    long occupied=0;
    //cout<<train.size()<<endl;
    vector<Interval>::iterator itt;
    for(it=train.begin(); it!=train.end(); it++) 
    {
        for(itt=it->second.begin(); itt!=it->second.end(); itt++)
        {
            occupied += itt->end - itt->start+1;
        }
    }
    
    cout<<m*n -occupied<<endl;
    return 0;
}
