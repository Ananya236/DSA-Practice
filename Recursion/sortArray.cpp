#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void insert(vector<ll> &v,ll temp){
    if(v.size()==0||v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int temp1 = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(temp1);
    return;
}

void sort(vector<ll> &v){
    if(v.size()==0)
    return;
    ll temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,temp);
    return;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v);
    for(ll i=0;i<n;i++){
        cout<<v[i];
    }
    return 0;
}