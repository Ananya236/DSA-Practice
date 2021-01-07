// Given an array of non-negative integers and a value difference, determine number of subsets(partitions) of the given set with difference between the partition equal to given difference.

// Example:

// Input: 
// N = 4
// arr = {1, 1, 2, 3}
// diff = 1
// Output: 
// 3

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countSubsetSumDiff(int n, int arr[], int diff)
    {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum<diff || (sum-diff)%2 !=0) return 0;
        //let s1 and s2 be the 2 partitions
        //s1+s2 = sum
        //abs(s1-s2) = diff
        //to find number of subsets with sum = (sum+diff)/2
    
        int s = (sum+diff)/2;
        int t[n+1][s+1];                 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(i==0 && j==0) t[i][j]=1;
                else if(i==0) t[i][j]=0;
                else if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][s];     
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,diff;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>diff;
        Solution ob;
        cout<<ob.countSubsetSumDiff(N, arr, diff);
    }
    return 0;
}  