//#Hackerearth
//#Nobita and String

//Reverse the string word by word

//eg:
//i/p- hello word program
//o/p- program word hello

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
	string s;
	while(getline(cin,s)){		
		reverse(s.begin(),s.end());
		size_t start=0;
		size_t end=s.find(" ",start);
		while(end!=string::npos){
			reverse(s.begin()+start,s.begin()+end);
			start=end+1;
			end=s.find(" ",start);
		}
		reverse(s.begin()+start,s.end());
		cout<<s<<"\n";
	}
	return 0;
}