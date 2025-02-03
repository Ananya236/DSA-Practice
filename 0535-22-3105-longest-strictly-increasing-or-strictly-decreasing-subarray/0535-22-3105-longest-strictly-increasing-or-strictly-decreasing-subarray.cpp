class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1, inc = 1, dec = 1;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]>nums[i]){
                inc++; dec=1;
            } else if(nums[i+1]<nums[i]){
                dec++; inc=1;
            } else{
                inc=1; dec=1;
            }
            int currMax=max(inc,dec);
            maxLen=max(maxLen,currMax);
        }

        return maxLen;
    }
};