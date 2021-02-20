// GFG
// Minimum and maximum of array elements

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.second << " " << pp.first << endl;
    }
    return 0;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long,long long> p(a[0],a[0]);
    for(int i=1;i<n;i++){
        if(a[i]<p.first) p.first=a[i];
        if(a[i]>p.second) p.second=a[i];
    }
    return p;
}