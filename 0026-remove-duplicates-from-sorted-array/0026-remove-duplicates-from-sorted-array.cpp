class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i,j=0;
        if(n==0)
            return j;
        for(i=1;i<n;i++){
            if(nums[i]!=nums[j]){
                nums[++j]=nums[i];
            }                
        }
        return j+1;
    }
};