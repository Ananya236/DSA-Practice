//#Hackerearth
//#Secret Messages!

//Encrypt the messages with a key, K, such that the character of the messages are now shifted K times towards right of their initial value.
//Convert numbers and alphabets while leaving special characters as it is.

//eg:
//i/p-
//1
//7 4
//Aanya12
//o/p- Eerce56

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n,k;
	cin>>t;
	string s;
	while(t--){
		cin>>n>>k;
		cin>>s;
		for(ll i=0;i<n;i++){
			if(s[i]>=97 && s[i]<=122){
				s[i]=char((s[i]+k-97)%26+97);
			}
			else if(s[i]>=65 && s[i]<=90){
				s[i]=char((s[i]+k-65)%26+65);
			}
			else if(s[i]>=48 && s[i]<=57){
				s[i]=char((s[i]+k-48)%10+48);
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}