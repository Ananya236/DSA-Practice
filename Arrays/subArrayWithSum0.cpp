// GFG
// Subarray with 0 sum

// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

// Example :

// Input:
// 5
// 4 2 -3 1 6

// Output: 
// Yes

// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
bool subArrayExists(int arr[], int n)
{
    set<int> s;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(s.find(sum)!=s.end()||sum==0) return true;
        s.insert(sum);
    }
    return false;
}


