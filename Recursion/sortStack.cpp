#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void insert(stack<ll> &v,ll temp){
    if(v.size()==0||v.top()>=temp){
        v.push(temp);
        return;
    }
    int temp1 = v.top();
    v.pop();
    insert(v,temp);
    v.push(temp1);
    return;
}

void sort(stack<ll> &v){
    if(v.size()==0)
    return;
    ll temp=v.top();
    v.pop();
    sort(v);
    insert(v,temp);
    return;
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
    sort(v);
    for(ll i=0;i<n;i++){
        cout<<v.top();
        v.pop();
    }
    return 0;
}