class Solution {
public:
    void findPermutation(vector<int>& nums, int index, vector<vector<int>>& res){
        int n = nums.size();
        if(index == n-1){
            res.push_back(nums);
            return;
        }

        // unordered_set<int> s;
        // s.insert(nums[index]);

        for(int i=index; i<n; i++){
            // if(!s.count(nums[i])){
            //     s.insert(nums[i]);
                swap(nums[index], nums[i]);
                findPermutation(nums, index+1, res);
                swap(nums[index], nums[i]);
            // }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPermutation(nums, 0, res);
        return res;
    }
};