// Find Pair Given Difference 

// Given an unsorted array Arr[] and a number N. You need to write a program to find if there exists a pair of elements in the array whose difference is N.

// Example:
// Input:
// 2
// 6 78
// 5 20 3 2 5 80
// 5 45
// 90 70 20 80 50
// Output:
// 1
// -1

#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,diff;
    cin>>t;
    while(t--){
        cin>>n>>diff;
        vector<int> v(n);
        bool found=false;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++){
            auto it = find(v.begin(),v.end(),abs(v[i]-diff));
            if(it!=v.end()) {found=true; break;}
        }
        if(found)
        cout<<1<<endl;
        else
        cout<<-1<<endl;
    }
	return 0;
}