// Geeks for Geeks
// Peak Element

// A peak element in an array is the one that is not smaller than its neighbours.
// Given an array of size N, find the index of any one of its peak elements.
 

// Example :

// Input:
// N = 3
// arr[] = {1,2,3}
// Output: 2 
// Explanation: index 2 is 3.
// It is the peak element as it is 
// greater than its neighbour 2.

#include<bits/stdc++.h>
using namespace std;

/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
   if(n==1) return 0;
   if(arr[0]>arr[1]) return 0;
   if(arr[n-1]>arr[n-2]) return n-1;
   for(int i=1;i<n-1;i++){
       if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) return i;
   }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		int A = peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
		if(n==1 and A==0)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		cout<<f<<endl;
		}
		
	}

	return 0;
} 