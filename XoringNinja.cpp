/*
Xoring Ninja
Problem: An XOR operation on a list is defined here as the xor of all its elements(e.g.: XOR({A,B,C}) = A XOR B XOR C}

The XorSum of set S is defined here as the sum of the XORs of all S's non-empty subsets. If we refer to the set of S's non-empty
subsets as S', this can be expressed as:

XorSum(S) = SUM(XOR(S_i)
FOr example: given set S = {n1,n2}

. The set of all possible non-empty subsets is:
	S={{n1},{n2},{n1,n2}}
. The XorSum of the non-empty subsets is then calcluated as follows:
	XorSum(S) = n1 + n2 + (n1 XOR n2)
	
The solution:
	This problem is not suitable for brute force, since the constraint limit is very strict. A set with 10^5 elements have 2^(10^5) subsets. 
	Thus, it is infeasible to go through them one by one. 
	
	However, one thing to notice is that each bit which has 1 contributes to the whole sum by exactly half times of the total subsets. Because there
	will be either 1 or 0 on each bit. When we do xor there will be either 1 or 0 being added to the whole sum. To do this is to test each bit where there is a 1.
	
	If there is, it contributes to the whole sub by (2^(N-1))*(2^(i-1)), where N is the number of subsets and i is the bit position i-th from the right-hand side. So we do 
	the test by using OR operation on all input, then we get the number which represents the bits have '1' on from all input. 
	Then we said before that each bit contribute to whole sum by exactly half of the time, which is 2^(N-1).
	
Summation:
	. Let A = x1 or x2 or x2 or ... or xn
	. sum = 2^(N-1) * A
*/

#include<iostream>

using namespace std;
#define MOD 1000000007
long long sum;
long long power(int n)
{
    long long ans=1;
    for(int i=0;i<n;i++){
        ans=(ans*2)%1000000007;
    }
    return ans;
}

int main()
{
	int t;
	long n;
	cin>>t;
	while(t--)
	{
        sum=0;
        cin>>n;
        long long ar[n];
			
        for(int i=0;i<n;i++)
            cin>>ar[i];
            
        long long orAll=0;
           
        for(int i=0; i<n; i++)
        {
            orAll = orAll | ar[i];
        }
        
        sum = orAll*power(n-1)%1000000007;
        cout<<sum<<endl;
	}
	return 0;
}