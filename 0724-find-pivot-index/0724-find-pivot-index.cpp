class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum =0;
        for(int i: nums) totalSum += i;
        
        int lSum=0;
        for(int i=0;i<nums.size();i++){
            if(lSum == totalSum-lSum-nums[i]) return i;
            lSum+=nums[i];
        }
        return -1;
    }
};