//#Hackerearth
//#Largest Balanced String

// An empty sequence is balanced.
// A sequence of the form (A) or [A] or {A} is balanced if A is balanced.
// A sequence of the form AB is balanced if A and B both are balanced.
// You are given a string A, consisting of '(', ')', '[', ']', '{' and '}' only.
// You have to find the maximum length of the balanced string after performing some valid operation(s).
// Valid operations are
// Remove any character from string A
// Swap any two adjacent characters of string A
// You can perform these valid operations in any order and any numbers of times.

//eg:
//i/p-))[]]((
//o/p-6

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
		map<char,int> m;
		for(int i=0;i<s.length();i++){
			m[s[i]]++;
		}
		int l= min(m['('],m[')'])+min(m['{'],m['}'])+min(m['['],m[']']);
		cout<<l*2<<"\n";
	}
	return 0;
}