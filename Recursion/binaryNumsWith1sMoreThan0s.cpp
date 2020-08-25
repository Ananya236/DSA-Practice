//Print all binary numbers on N bits with no of 1's greater than 0's for all prefixes

//Eg:
//3 -> 
// 111
// 110
// 101

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(string op,int o,int z,int n){
    if(n==0){
        cout<<op<<endl;
        return;
    }
    if(o>z){
        string op1=op+"1";
        print(op1,o+1,z,n-1);
        string op2=op+"0";
        print(op2,o,z+1,n-1);
    }
    else{
        string op1=op+"1";
        print(op1,o+1,z,n-1);
    }
    return;
}
 
int main(){
    int n;
    cin>>n;
    int o,z;
    o=z=0;
    if(n==0)
    return 0;
    string op="";
    print(op,o,z,n);
    return 0;
}