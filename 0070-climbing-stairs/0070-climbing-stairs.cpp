class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> v(n);
        v[0]=1;
        v[1]=2;
        for(int i=2;i<n;i++){
            v[i]=v[i-1]+v[i-2];
        }
        return v[n-1];
    }
};