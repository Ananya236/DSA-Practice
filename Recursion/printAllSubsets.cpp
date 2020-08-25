//Source Helper Destination

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(string i,string o){
    if(i.length()==0){
        cout<<o<<endl;
        return;
    }
    string o1=o;
    string o2=o;
    o2.push_back(i[0]);
    i.erase(i.begin());
    print(i,o1);
    print(i,o2);
    return;
}

int main(){
    string s;
    cin>>s;
    string o="";
    print(s,o);
    return 0;
}