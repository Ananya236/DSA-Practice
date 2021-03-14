// GFG
// Longest Repeating Subsequence 

// Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 

// Exampel 1:

// Input: str = "axxxy"
// Output: 2
// Explanation: The longest repeating subsequenece
// is "xx".

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string s1){
		    int n=s1.length();
            string s2=s1;
            int t[n+1][n+1];
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(i==0||j==0) t[i][j]=0;
                    else if(s1[i-1]==s2[j-1] && i!=j) t[i][j]=t[i-1][j-1]+1;
                    else t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
            return t[n][n];
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  