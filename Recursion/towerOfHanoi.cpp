//Source Helper Destination

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void move(int n,char s,char h,char d){
    if(n==1){
        cout<<"Disc "<<n<<": "<<s<<" -> "<<d<<endl;
        return;
    }
    move(n-1,s,d,h);
    cout<<"Disc "<<n<<": "<<s<<" -> "<<d<<endl;
    move(n-1,h,s,d);
    return;
}

int main(){
    int n;
    cin>>n;
    char s='A',h='B',d='C';
    move(n,s,h,d);
    return 0;
}