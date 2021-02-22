// GFG
// Minimum number of jumps

// Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Example :

// Input:
// N=11 
// arr=1 3 5 8 9 2 6 7 6 8 9 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to last.

#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    int jumps=0, upcoming=0, current=0;
    for(int i=0;i<n;i++){
        upcoming=max(upcoming, i+arr[i]);
        if(i==current){
            jumps++;
            current=upcoming;
        }
        if(current >= n-1) break;
    }
    if(current<n-1) return -1;
    else return jumps;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}