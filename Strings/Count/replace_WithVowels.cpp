//#Hackerearth
//#Can you count?

//replace all underscores (if any) with vowels
//Each underscore can be replaced with any one of the vowel(s) that came before it.
//Count total number of distinct strings we can generate following the given rule.

//eg:
//i/p-ab_ae_
//o/p-2

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		set<char> vowels;
		ll total=1;
		for(int i=0;i<s.length();i++){
			if(s[i]=='_'){
				total*=vowels.size();
			}
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			vowels.insert(s[i]);
		}
		cout<<total<<"\n";
	}
	return 0;
}