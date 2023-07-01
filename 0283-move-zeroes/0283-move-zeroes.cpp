class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        vector<int> temp(n,0);
        int t=0;
        for(int i=0;i<n;i++){
            if(nums[i]) temp[t++]=nums[i];
        }
        nums=temp;
    }
};