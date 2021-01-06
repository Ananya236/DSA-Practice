// Given an array of non-negative integers and a value sum, determine if there is a subset of the given set with sum equal to given sum.

// Example:

// Input: 
// N = 4
// arr = {1, 5, 11, 5}
// sum = 6
// Output: 
// YES

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subsetSum(int n, int arr[], int s)
    {
        bool t[n+1][s+1];                 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(j==0) t[i][j]=true;
                else if(i==0) t[i][j]=false;
                else if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][s]?1:0;     
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,sum;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>sum;
        Solution ob;
        if(ob.subsetSum(N, arr, sum))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  