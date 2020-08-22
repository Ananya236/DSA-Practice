//Given a string S. Your task is to remove all duplicates characters from the string S.
//String S contains only lowercase characters ['a'-'z'].

//eg: 
//i/p- programming
//o/p- progamin

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	vector<int> l(26,0);   //frequency vector
	for(ll i=0;i<s.length();i++){
		if(l[s[i]-'a'])
		continue;
		else{
			l[s[i]-'a']=1;
			cout<<s[i];
		}
	}
	return 0;
}