class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0, cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) {
                nums[++k]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};