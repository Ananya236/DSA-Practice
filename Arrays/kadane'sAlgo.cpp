// GFG
// Kadane's Algorithm 

// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Example :

// Input:
// N = 5
// arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.

#include<bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int a[], int n){
    int max_sum=a[0],curr=a[0];
    for(int i=1;i<n;i++){
        curr=max(a[i],curr+a[i]);
        max_sum=max(curr,max_sum);
    }
    return max_sum;
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}