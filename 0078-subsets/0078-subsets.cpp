class Solution {
public:
    void getSubsets(vector<int> nums, vector<int> op, vector<vector<int>> &v){
        if(nums.size()==0){
            v.push_back(op);
            return;
        }
        
        int temp = nums[nums.size()-1];
        nums.pop_back();
        getSubsets(nums,op,v);
        op.push_back(temp);
        getSubsets(nums,op,v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> v;
        
        getSubsets(nums, op, v);
        return v;
    }
};