//#Hackerearth
//#UpUp

//In each word which starts from lowercase Latin letter replace starting letter with uppercase Latin letter.

//eg:
//i/p-Wish you were here
//o/p-Wish You Were Here

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin,s);
	s[0]=toupper(s[0]);
	for(int i=1;i<s.length();i++){
		if(s[i]==' ')
		s[i+1]=toupper(s[i+1]);
	}
	cout<<s;
	return 0;
}