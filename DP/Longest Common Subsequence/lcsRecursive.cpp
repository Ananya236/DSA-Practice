// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

// Example :

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH” of
// length 3.

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// function to find longest common subsequence
int lcs(int x, int y, string s1, string s2){
    
    // using recursion
    if(x==0 || y==0) return 0;
    if(s1[x-1]==s2[y-1]) return lcs(x-1,y-1,s1,s2)+1;
    else return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
    
}
