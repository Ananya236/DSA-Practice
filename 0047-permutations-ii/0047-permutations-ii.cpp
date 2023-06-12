class Solution {
public:
    void solve(vector<int> nums, vector<int> op, set<vector<int>> &s,int n){
        if(nums.size()==0){
            s.insert(op);
            return;
        }
        
        int num = nums[nums.size()-1];
        nums.pop_back();
        
        vector<int> temp(n);
        
        for(int i=0;i<n;i++){
            if(op[i]==-11){
                temp=op;
                temp[i]=num;
                solve(nums,temp,s,n);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> op(n, -11);
        set<vector<int>> s;
        
        solve(nums, op, s, n);
        
        vector<vector<int>> v;
        
        for(auto i: s){
            v.push_back(i);
        }
        
        return v;
    }
};