// GFG
// Reverse an array

#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        int i=0,j=n-1;
        while(i<=j){
            int temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        // reverse(a.begin(),a.end());
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<'\n';
    }
	return 0;
}