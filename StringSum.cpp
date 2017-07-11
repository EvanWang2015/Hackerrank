/*
Sum of two large strings
*/


string findSum(string str1, string str2)
{
    if(str1.length()>str2.length())
        swap(str1,str2);
    //Take an empty string for storing result
    string str="";
    //calculate the length of both strings
    int n1 = str1.length(), n2 = str2.length();
    //reverse both strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    
    int carry = 0;
    for(int i=0; i<n1; i++)
    {
        int sum = (str1[i]-'0')+(str2[i]-'0')+carry;
        str.push_back(sum%10+'0');
        
        carry = sum/10;
    }
    
    if(carry)
        str.push_back(carry+'0');
    
    //reverse resultant string
    reverse(str.begin(), str.end());
    
    return str;   
}