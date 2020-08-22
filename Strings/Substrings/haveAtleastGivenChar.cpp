//#HACKEREARTH 
//#47's Strings

//Count Substrings containing atleast character x or character y
//can be extended to any no of characters

// eg: 
//i/p- $bcd
//o/p- 4

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll countSubStr(string s, char x,char y) 
{ 
	ll res = 0, count = 0; 
	ll n=s.length();
	for (ll i = 0; i < n; i++) { 
		if (s[i] == x || s[i] == y) {  
            // Number of sub-strings from position of current x or y to the end of s
			res += ((count + 1) * (n - i)); 
			count = 0; 
		} 
		else
            // To store the number of characters before x or y
			count++; 
	} 
	return res; 
} 
  
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
		cout<<countSubStr(s,'$','&')<<"\n";
	}
	return 0;
}