class Solution {
public:
    void solve(int n, int k, int it, vector<int> op, vector<vector<int>> &v){
        if(k==0){
            v.push_back(op);
            return;
        }
        
        for(int i=it;i<=n;i++){
            op.push_back(i);
            solve(n,k-1,i+1,op,v);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> op;
        vector<vector<int>> v;
        
        solve(n,k,1,op,v);
        
        return v;
    }
};