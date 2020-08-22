//#Hackerearth
//#Terrible Chandu

//print the reverse of a given string.

//eg:
//i/p- abcde
//o/p- edcba

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
		reverse(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}