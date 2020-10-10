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