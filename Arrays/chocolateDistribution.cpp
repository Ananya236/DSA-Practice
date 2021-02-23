// GFG
// Chocolate distribution problem

// Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
// 1. Each student gets one packet.
// 2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.

// Example:
// Input:
// 2
// 8
// 3 4 1 9 56 7 9 12
// 5
// 7
// 7 3 2 4 9 12 56
// 3

// Output:
// 6
// 2

// Explanation:
// Testcase 1: The minimum difference between maximum chocolates and minimum chocolates is 9-3=6

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for (int i=0;i<n;i++)
	    cin>>v[i];
	    int k;
	    cin>>k;
	    sort(v.begin(),v.end());
	    int minD=v[k-1]-v[0];
	    for(int i=1;i<=n-k;i++){
	        int d=v[i+k-1]-v[i];
	        //cout<<d<<" ";
	        if(minD>d)
	        minD=d;
	    }
	    cout<<minD<<"\n";
	}
	return 0;
}