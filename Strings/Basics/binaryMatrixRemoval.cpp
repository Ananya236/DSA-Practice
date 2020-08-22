//#Hackerearth
//#Ashish and Binary Matrix

//You will be given n*m binary matrix. You need to tell if it is possible to delete a column such that after deleting that column, rows of the matrix will be unique. If yes than print "Yes" else print "No".

//eg:
//i/p- 101
//     000
//     100
//o/p- Yes

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,r,c;
	cin>>t;
	string s;
	while(t--){
		cin>>r>>c;
		set<string> s1;
		for(int i=0;i<r;i++){
			cin>>s;
			s1.insert(s);
		}
		if(s1.size()==r)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
}