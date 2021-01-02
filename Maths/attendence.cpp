//#Codechef
//#Minimum Attendence Requirement

// A semester in Chef's University has 120 working days. 
// The University's requirement is that a student should be present for at least 75% of the working days in the semester. If not, the student is failed.
// Chef has been taking a lot of holidays, and is now concerned whether he can pass the attendance requirement or not. 
// N working days have already passed, and you are given N bits - B1, B2, …, BN. Bi = 0 denotes that Chef was absent on the ith day, and Bi = 1 denotes that Chef was present on that day.

// Can Chef hope to pass the requirement by the end of the semester?

//e.g.:
// Input:
// 3
// 50
// 00000000000000000000000000000000000000000000000000
// 50
// 01010101010101010101010101010101010101010101010101
// 2
// 01
// Output:
// NO
// YES
// YES


#include <iostream>
using namespace std;

int main() {
	int t,n,p;
	char a;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    p=120-n;
	    while(n--)
	    {
	        cin>>a;
	        if(a=='1')
	        p++;
	    }
	    if(p<90)
	    cout<<"NO"<<endl;
	    else
	    cout<<"YES"<<endl;
	}
	return 0;
}
