// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

// Example :

// Input:
// n = 4 , m = 3
// S[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.

#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
      long long int t[m+1][n+1];
      for(long long int i=0;i<=m;i++){
          for(long long int j=0;j<=n;j++){
              if(j==0 && i==0) t[i][j]=1;
              else if(i==0) t[i][j]=0;
              else if(S[i-1]<=j) t[i][j]=t[i][j-S[i-1]]+t[i-1][j];
              else t[i][j]=t[i-1][j];
          }
      }
      return t[m][n];
    }
};

int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    return 0;
}  