class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), nonSortCnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i]>nums[(i+1) % n]) nonSortCnt++;
            if(nonSortCnt == 2) return false;
        }

        return true;
    }
};