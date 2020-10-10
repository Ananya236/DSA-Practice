//#Codeforces
//#Juggling Letters

// You are given n strings s1,s2,…,sn consisting of lowercase Latin letters.

// In one operation you can remove a character from a string si and insert it to an arbitrary position in a string sj (j may be equal to i). You may perform this operation any number of times. Is it possible to make all n strings equal?

//eg:
//i/p-
// 2
// 2
// caa
// cbb
// 3
// cba
// cba
// cbb
//o/p-
// YES
// NO

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main(){
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<s.length();j++)
            freq[s[j]-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(freq[i]%n!=0){
                flag=1;
                break;
            }
        }
        if(flag)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    return 0;
}