//Eg:
//ab -> 
//ab , Ab , aB , AB

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

void print(string i,string o){
    if(i.length()==0){
        cout<<o<<endl;
        return;
    }
    if(isalpha(i[0])){
        string o1=o;
        o1.push_back(i[0]);
        string o2=o;
        o2.push_back(islower(i[0])?toupper(i[0]):tolower(i[0]));
        i.erase(i.begin());
        print(i,o1);
        print(i,o2);
    }
    else{
        string o1=o+i[0];
        i.erase(i.begin());
        print(i,o1);
    }
    return;
}

int main(){
    string s;
    cin>>s;
    if(s.length()==0)
    return 0;
    string o="";
    print(s,o);
    return 0;
}