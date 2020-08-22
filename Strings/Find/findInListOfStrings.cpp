//#Hackerearth
//#Password

//Given a list of strings. Find the string whose reverse is also present in the list.
//Print the length of the correct string and its central letter.

//eg:
//i/p- 
//abc
//def
//feg
//cba
//o/p- 3 b

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		string key = v[i];
		reverse(key.begin(),key.end());
		if (find(v.begin(), v.end(), key) != v.end()){
			cout<<v[i].length()<<" "<<v[i][(v[i].length())/2];
			break;
		}
	}
	return 0;
}