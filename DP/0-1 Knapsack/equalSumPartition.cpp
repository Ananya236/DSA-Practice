// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Example:

// Input: 
// N = 4
// arr = {1, 5, 11, 5}
// Output: 
// YES
// Explaination: 
// The two parts are {1, 5, 5} and {11}.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum%2==0){
            int s=sum/2;
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
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  