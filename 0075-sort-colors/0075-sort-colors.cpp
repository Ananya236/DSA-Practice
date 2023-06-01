class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0, ed=nums.size()-1, it=0;
        while(it<=ed){
            if(nums[it]==0){
                swap(nums[it],nums[st]);
                st++;
                it++;
            }
            else if(nums[it]==2){
                swap(nums[it],nums[ed]);
                ed--;
            }
            else it++;
        }
    }
};