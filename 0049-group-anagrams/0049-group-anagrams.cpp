class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string, vector<string>> um;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            um[s].push_back(strs[i]);
        }
        
        for(auto i: um){
            v.push_back(i.second);
        }
        
        return v;
    }
};