#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void del(stack<ll> &v,ll k){
    if(v.size()==0)
    return;
    if(k==1){
        v.pop();
        return;
    }
    ll temp=v.top();
    v.pop();
    del(v,k-1);
    v.push(temp);
}

int main(){
    ll n;
    cin>>n;
    stack<ll> v;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        v.push(temp);
    }
    del(v,n/2+1);
    for(ll i=0;i<n-1;i++){
        cout<<v.top();
        v.pop();
    }
    return 0;
}