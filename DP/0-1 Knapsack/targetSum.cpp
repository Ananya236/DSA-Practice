// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example :

// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(int n, int nums[], int S) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        } 
        if(sum<S || (sum-S)%2 !=0) return 0;
        int s = (sum+S)/2;
        int t[n+1][s+1];                 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(j==0 && i==0) t[i][j]=1;
                else if(i==0) t[i][j]=0;
                else if(nums[i-1]<=j) t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
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
        int N,sum;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>sum;
        Solution ob;
        cout<<ob.findTargetSumWays(N,arr, sum);
    }
    return 0;
}  