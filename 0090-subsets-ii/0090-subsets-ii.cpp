class Solution {
public:
    void solve(vector<int> nums, vector<int> op, set<vector<int>> &s){
        if(nums.size()==0){
            s.insert(op);
            return;
        }
        
        int num = nums[nums.size()-1];
        nums.pop_back();
        
        solve(nums,op,s);
        op.push_back(num);
        solve(nums,op,s);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> op;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        
        solve(nums,op,s);
        
        vector<vector<int>> v;
        
        for(auto i: s) v.push_back(i);
        
        return v;
    }
};