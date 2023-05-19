class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i=0;i<32;i++){
            int t = n>>i;
            res+=t&1;
        }
        return res;
    }
};