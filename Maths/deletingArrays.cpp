//#HackerEarth 
//#Deleting Arrays

// You are given two integers N and K denoting the number of elements in the array and an arbitrary integer respectively. 
// You can perform the following operations:

// Select an index i.
// Delete the ith element.
// Delete K elements to the left of it if they exist or you can delete all the elements if the number of elements to the left of it is less than K.
// Delete K elements to the right of it if they exist or you can delete all if the number of elements to the right of it is less than K.

// Your task is to delete all the elements of the array using the minimum number of provided operations.

// INPUT
// 1
// 4 1
// OUTPUT 
// 2
// Explanation
// There are 4 elements if we choose 2nd index we can remove 1st,2nd and 3rd in first operation. In second operation we can choose 4th index and remove it. 

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
	while(t--){
        // n = number of elements of the array
		// k = arbitary integer denoting the no of elements should be deleted
		cin>>n>>k;

        // k>=n then choose any index only 1 operation required
		if(k>=n) cout<<"1\n";
        //we can always delete 2*k + 1 element in this case in operation
		else cout<<(n/(2*k+1))+(n%(2*k+1)!=0)<<"\n";  //ceil(n/(2*k+1))
	}
	return 0;
}