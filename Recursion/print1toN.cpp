#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(ll n){
    if(n==1){
        cout<<"1\n";
        return;
    }
    print(n-1);
    cout<<n<<"\n";
}

int main(){
    ll n;
    cin>>n;
    print(n);
    return 0;
}