class Solution {
public:
    void findPermute(vector<int>& nums, int index, vector<vector<int>>&res){
        int n=nums.size();
        if(index == n-1) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for(int i=index; i<n; i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
                swap(nums[index], nums[i]);
                findPermute(nums, index+1, res);
                swap(nums[index], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        findPermute(nums, 0, res);
        return res;
    }
};