class Solution {
public:
    void solve(int n, int k, int target, int it, vector<int> op, vector<vector<int>> &v){
        if(k==0){
            if(target==0)
                v.push_back(op);
            return;
        }
        
        for(int i=it;i<=n;i++){
            if(i>target) return;
            op.push_back(i);
            solve(n,k-1,target-i,i+1,op,v);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>op;
        vector<vector<int>> v;
        solve(9,k,n,1,op,v);
        return v;
    }
};