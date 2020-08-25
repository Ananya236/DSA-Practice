//ABC -> 
//A BC , AB C, A B C , ABC

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(string i,string o){
    if(i.length()==0){
        cout<<o<<endl;
        return;
    }
    string o1=o+" ";
    o1.push_back(i[0]);
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
    if(s.length()==0)
    return 0;
    string o="";
    o.push_back(s[0]);
    s.erase(s.begin());
    print(s,o);
    return 0;
}