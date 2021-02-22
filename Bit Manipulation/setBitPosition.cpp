// GFG
// Find position of the only set bit

// Given a number N having only one ‘1’ and all other ’0’s in its binary representation, find position of the only set bit. If there are 0 or more than 1 set bit the answer should be -1. Position of  set bit '1' should be counted starting with 1 from LSB side in binary representation of the number.

// Example :

// Input:
// N = 2
// Output:
// 2
// Explanation:
// 2 is represented as "10" in Binary.
// As we see there's only one set bit
// and it's in Position 2 and thus the
// Output 2.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N) {
        if(N&(N-1) || N==0) return -1;
        else{
            int cnt=0;
            while(N){
                cnt++;
                if(N&1) return cnt;
                N=N>>1;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} 