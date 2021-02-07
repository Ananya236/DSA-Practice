// Given two sequences, find the length of longest substring present in both of them. Both the strings are of uppercase.

// Example :

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.

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

// function to find longest common substring
int lcs(int x, int y, string s1, string s2){    
    //using iterative
    int t[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0||j==0) t[i][j]=0;
            else if(s1[i-1]==s2[j-1]) t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=0;  //whenever there is a mismatch, start count with 0
        }
    }
    int res = INT_MIN;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(t[i][j]>res) res=t[i][j];
        }
    }
    return res;
}
