class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPresent(n,false);
        
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<=n) isPresent[nums[i]-1]=true;
        }
        
        for(int i=0;i<n;i++){
            if(!isPresent[i]) return i+1;
        }
        
        return n+1;
    }
};