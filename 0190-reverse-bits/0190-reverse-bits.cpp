class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for (int i=31; i>=0; i--) {
            int k=n>>i;
            if (k&1) // digit is 1;
                res+=pow(2,31-i);
        }
        
        return res;
    }
};