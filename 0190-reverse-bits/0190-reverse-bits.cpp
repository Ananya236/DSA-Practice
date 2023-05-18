class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bin;
        for (int i=31; i>=0; i--) {
            int k=n>>i;
            if (k&1)
                bin.push_back(1);
            else
                bin.push_back(0);
        }
        
        uint32_t res=0;
        for(int i=0;i<32;i++){
            res+=bin[i]*pow(2,i);
        }
        return res;
    }
};