//Eg:
//2 -> 
//()() , (())

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(string op,int o,int c){
    if(o==0 && c==0){
        cout<<op<<endl;
        return;
    }
    if(o<c && o>0){
        string op1=op+"(";
        print(op1,o-1,c);
        string op2=op+")";
        print(op2,o,c-1);
    }
    else if(o>0){
        string op1=op+"(";
        print(op1,o-1,c);
    }
    else{
        string op2=op+")";
        print(op2,o,c-1);
    }
    return;
}
 
int main(){
    int n;
    cin>>n;
    int o,c;
    o=c=n;
    if(n==0)
    return 0;
    string op="";
    print(op,o,c);
    return 0;
}