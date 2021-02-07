// Given two sequences, print the longest subsequence present in both of them. Both the strings are of uppercase.

// Example :

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input Sequences
// “ABCDGH” and “AEDFHR” is “ADH”

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

string lcs(int, int, string, string);

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

// function to print longest common subsequence
string lcs(int x, int y, string s1, string s2){    
    //using iterative
    int t[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            if(i==0||j==0) t[i][j]=0;
            else if(s1[i-1]==s2[j-1]) t[i][j]=t[i-1][j-1]+1;
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    string s;
    while(x!=0 && y!=0){
        if(s1[x-1]==s2[y-1]){
            s.push_back(s1[x-1]);
            x--;y--;
        }else{
            if(t[x-1][y]>t[x][y-1]) x--;
            else y--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
