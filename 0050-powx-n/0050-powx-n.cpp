class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        else if(n>0) {
            if(n&1) //n is odd
                return x * myPow(x*x,(n-1)/2);
            else
                return myPow(x*x, n/2);
        }
        else {
            if(n&1) //n is odd
                return 1/(x * myPow(x*x, -(n+1)/2));
            else
                return 1/myPow(x*x, -(n/2));
        }
    }
};