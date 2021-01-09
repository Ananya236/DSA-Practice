#include<bits/stdc++.h>
using namespace std;

// Returns the maximum price that can be earnde with a rod of length n 
int rodCut(int W, int wt[], int val[], int n) 
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
        int n,W;
        cin>>n;
        W=n;
        
        int val[n];
        int wt[n];
        
        //inserting the prices
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the lengths
        for(int i=0;i<n;i++)
            wt[i]=i+1;
        
        //calling method rodCut
        cout<<rodCut(W, wt, val, n)<<endl;
        
    }
	return 0;
} 