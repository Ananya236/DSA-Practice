// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

// Example :

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3

#include<bits/stdc++.h>
using namespace std;

int knapMemo(int W, int wt[], int val[], int n, int** t){
    if(n==0 || W==0) return 0;
    if(t[n][W]!=-1) return t[n][W];
    if(wt[n-1]<=W) t[n][W] = max(val[n-1]+knapMemo(W-wt[n-1],wt,val,n-1,t),knapMemo(W,wt,val,n-1,t));
    else t[n][W] = knapMemo(W,wt,val,n-1,t);
    return t[n][W];
}

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
//using memoization(bottom-up)
{
    int** t; 
    t = new int*[n+1];
    for (int i = 0; i <= n; i++) 
        t[i] = new int[W + 1]; 
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= W; j++) 
            t[i][j] = -1; 
    return knapMemo(W,wt,val,n,t);
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