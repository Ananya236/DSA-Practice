class Solution {
public:
    void solve(vector<int> ip, vector<int> op, vector<vector<int>> &v, int target){
        if(target==0){
            v.push_back(op);
            return;
        }
        if(ip.size()==0) return;
        
        int num = ip[ip.size()-1];
        if(num>target){
            ip.pop_back();
            solve(ip,op,v,target);
        } else{
            op.push_back(num);
            solve(ip,op,v,target-num);
            op.pop_back();
            ip.pop_back();
            solve(ip,op,v,target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> op;
        vector<vector<int>> v;
        
        solve(candidates, op, v, target);
        
        return v;
    }
};