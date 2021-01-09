// Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then output -1

// Example :

// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin
// and one 5 cent coin

#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	  int t[M+1][V+1];
      for(int i=0;i<=M;i++){
          for(int j=0;j<=V;j++){
              if(i==0) t[i][j]=INT_MAX-1;
              else if(j==0) t[i][j]=0;
              else if(i==1) {
                  if(j%coins[i-1]) t[i][j]=INT_MAX-1;
                  else t[i][j] = j/coins[i-1];
              }
              else if(coins[i-1]<=j) t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]);
              else t[i][j]=t[i-1][j];
          }
      }
      return t[M][V]>=INT_MAX-1?-1:t[M][V];
	} 	  
};

int main() 
{    
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;
        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];   
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";	     
    }
    return 0;
}