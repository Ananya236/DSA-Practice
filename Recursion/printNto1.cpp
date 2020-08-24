#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(ll n){
    if(n==1){
        cout<<"1\n";
        return;
    }
    cout<<n<<"\n";
    print(n-1);
}

int main(){
    ll n;
    cin>>n;
    print(n);
    return 0;
}