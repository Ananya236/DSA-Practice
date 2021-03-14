// GFG
// Longest Palindromic Subsequence
 
// Given a sequence, find the length of the longest palindromic subsequence in it.

// Example: If the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest palindromic subsequence in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

#include<bits/stdc++.h>
using namespace std;

int lps(string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;        // Take the string as input
        
        cout << lps(s1) << endl;
    }
    return 0;
}

// function to find longest palindromic subsequence
int lps(string s1){    
    int n=s1.length();
    string s2=s1;
    reverse(s2.begin(),s2.end());
    int t[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0) t[i][j]=0;
            else if(s1[i-1]==s2[j-1]) t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][n];
}
