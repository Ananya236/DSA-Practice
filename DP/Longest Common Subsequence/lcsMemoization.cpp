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
int lcsMemo(int x,int y,string s1,string s2,int **t){
    if(x==0 || y==0) return 0;
    if(t[x][y]!=-1) return t[x][y];
    if(s1[x-1]==s2[y-1]) t[x][y]=lcsMemo(x-1,y-1,s1,s2,t)+1;
    else t[x][y]=max(lcsMemo(x-1,y,s1,s2,t),lcsMemo(x,y-1,s1,s2,t));
    return t[x][y];
}

int lcs(int x, int y, string s1, string s2){

    //using memoization
    int **t;
    t= new int *[x+1];
    for(int i=0;i<=x;i++)
    t[i]=new int[y+1];
    for (int i = 0; i <= x; i++) 
        for (int j = 0; j <= y; j++) 
            t[i][j] = -1; 
    return lcsMemo(x,y,s1,s2,t);
    
}
