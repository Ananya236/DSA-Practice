// Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

// Example :

// Input: N = 2, W = 3
// val[] = {1, 1}
// wt[] = {2, 1}
// Output: 3
// Explaination: Pick the 2nd element thrice.

#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
//using iterative approach(top-down)
{
    int t[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0) t[i][j]=0;
            else if(wt[i-1]<=j) t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
            else t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 