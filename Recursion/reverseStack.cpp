#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void insert(stack<ll> &v,ll k){
    if(v.size()==0){
        v.push(k);
        return;
    }
    ll temp=v.top();
    v.pop();
    insert(v,k);
    v.push(temp);
    return;
}

void rev(stack<ll> &v){
    if(v.size()==1){
        return;
    }
    ll temp=v.top();
    v.pop();
    rev(v);
    insert(v,temp);
    return;
}

int main(){
    ll n;
    cin>>n;
    if(n==0)
    return 0;
    stack<ll> v;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        v.push(temp);
    }
    rev(v);
    for(ll i=0;i<n;i++){
        cout<<v.top();
        v.pop();
    }
    return 0;
}