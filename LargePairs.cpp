//============================================================================
// Name        : Test.cpp
// Author      : Evan Wang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// C++ program to find sum of two large numbers.
#include<bits/stdc++.h>
using namespace std;

string to_string(int t)
{
	stringstream ss;
	ss<<t;
	return ss.str();
}

bool mycompare(string& s1, string &s2)
{
    return s1<s2;
}
// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate lenght of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i=0; i<n1; i++)
	{
		// Do school mathematics, compute sum of
		// current digits and carry
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		// Calculate carry for next step
		carry = sum/10;
	}

	// Add remaining digits of larger number
	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry+'0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

// Driver code
int main()
{
	//string str1 = "6";
	//string str2 = "5";
	//cout << findSum(str1, str2);


	int n, k;
	ifstream file("C:/Users/Evan/Desktop/Quant Study/Quant Preparation/C++Coding/Test/Debug/test2.txt");
	if(file)
	{
		//cout<<"already exists"<<endl;
	}

	//cout<<file.good()<<endl;

	string line;
	int value;
	int lineNum=0;
	string tem;
	vector<string> arr;
	while(std::getline(file, line))
	{
		if(lineNum==0)
		{
			stringstream  lineStream(line);
			lineStream>>n;
			lineStream>>k;
			lineNum++;

		}
		else
		{
			stringstream  lineStream(line);
			while(lineStream >> tem)
			{
							// Add the integers from a line to a 1D array (vector)
				arr.push_back(tem);
			}
		}
	}

	sort(arr.begin(), arr.end(), mycompare);
	int num =0;
	string kst = to_string(k);

	for(int i=0; i<arr.size(); i++)
		{
			tem = findSum(kst,arr[i]);

			for(int j=i+1; j<arr.size(); j++)
			{
				if(tem==arr[j])
				{
					num++;
					break;
				}

				if(tem<arr[j])
				{
					break;
				}
			}

		}
	cout<<num<<endl;

    //cout<<n<<" "<<k<<endl;
    //cout<<arr.size()<<endl;
	return 0;
}

