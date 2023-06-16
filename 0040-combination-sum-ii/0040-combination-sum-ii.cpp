class Solution {
public:
    //using set -> MLE
//     void solve(vector<int> ip, vector<int> op, set<vector<int>> &s, int target){
//         if(target==0){
//             s.insert(op);
//             return;
//         }
//         if(ip.size()==0) return;
        
//         int num = ip[ip.size()-1];
//         ip.pop_back();
//         solve(ip,op,s,target);
//         if(num<=target){
//             op.push_back(num);
//             solve(ip,op,s,target-num);
//         }
//     }
    
    void solve(vector<int> ip, vector<int> op, vector<vector<int>> &v, int target, int id){
        if(target==0){
            v.push_back(op);
            return;
        }
        
        for(int i=id; i<ip.size();i++){
            if(i>id && ip[i-1]==ip[i]) continue;
            if(ip[i]>target) return;
            op.push_back(ip[i]);
            solve(ip,op,v,target-ip[i],i+1);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> op;
        // set<vector<int>> s;        
        vector<vector<int>> v;    
        
        sort(candidates.begin(),candidates.end());
        
        solve(candidates, op, v, target, 0);        
            
        // for(auto i: s) v.push_back(i);
        
        return v;
    }
};