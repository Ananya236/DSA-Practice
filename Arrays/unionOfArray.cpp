// GFG
// Union of two arrays

// Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

// Example :

// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3

// Output: 
// 5

// Explanation: 
// 1, 2, 3, 4 and 5 are the
// elements which comes in the union set
// of both arrays. So count is 5.

#include <bits/stdc++.h>
using namespace std;

int doUnion(int *, int , int *, int);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	   
	    cout << doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)  {
    set<int> s;
    for(int i=0;i<n;i++) s.insert(a[i]);
    for(int j=0;j<m;j++) s.insert(b[j]);
    return s.size();
}