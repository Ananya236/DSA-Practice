// GFG
// Minimize heights difference (negative heights)

// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height can be a negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

// Example :

// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5
// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int temp = arr[n-1]-arr[0];
        int mn,mx;
        for(int i=1;i<n;i++){
            mn=min(arr[0]+k,arr[i]-k);
            mx=max(arr[i-1]+k,arr[n-1]-k);
            temp=min(temp,mx-mn);
        }
        return temp;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} 