// GFG
// Intersection of two arrays

// Given two arrays A and B respectively of size N and M, the task is to print the count of elements in the intersection (or common elements) of the two arrays.

// For this question, the intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

// Example :

// Input:
// 5 3
// 89 24 75 11 23
// 89 2 4

// Output: 
// 1

// Explanation: 
// 89 is the only element 
// in the intersection of two arrays.

#include<bits/stdc++.h>
using namespace std;
int NumberofElementsInIntersection (int a[], int b[], int n, int m );

// Given two arrays A and B and their sizes N and M respectively 
int NumberofElementsInIntersection (int a[], int b[], int n, int m )
{
    set<int> s;
    for(int i=0;i<n;i++) s.insert(a[i]);
    int ans = 0;
    for(int i = 0 ; i < m ; i++) {
        if(s.find(b[i]) != s.end()) {
            ans++;
            s.erase(b[i]);
        }
    }
    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
			
		cout << NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
} 