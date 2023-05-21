class Solution {
public:
    int mySqrt(int x) {
        int res=0;
        for(int i=1;i<=x;i++){
            if(i>x/i) break;
            res=i;
        }
        return res;
    }
};