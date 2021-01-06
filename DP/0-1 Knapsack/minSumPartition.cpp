// Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11   

#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
	    int s=0;
	    for(int i=0;i<n;i++) s+=arr[i];
	    bool t[n+1][s+1];                 
        for(int i=0;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(j==0) t[i][j]=true;
                else if(i==0) t[i][j]=false;
                else if(arr[i-1]<=j) t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        int diff=INT_MAX;
        for(int i=0;i<=s;i++){
            if(t[n][i]) diff=min(diff,abs(s-2*i));
        }
        return diff;
	} 
};

int main() 
{      
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
} 