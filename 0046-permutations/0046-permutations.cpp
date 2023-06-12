class Solution {
public:
    void solve(vector<int> nums, vector<int> op, vector<vector<int>> &v, int n){
        if(nums.size()==0) {
            v.push_back(op);
            return;
        }
        int num = nums[nums.size()-1];
        nums.pop_back();
        
        for(int i=0;i<n;i++){
            if(op[i]==-11)
            {
                vector<int> temp(n);
                temp = op;
                temp[i]=num;
                solve(nums,temp,v,n);
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        vector<int> op(n,-11);
        solve(nums,op,v,n);
        return v;
    }
};