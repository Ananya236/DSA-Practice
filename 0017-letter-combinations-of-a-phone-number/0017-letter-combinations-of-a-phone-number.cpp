class Solution {
public:
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void solve(string digits, int index, string op, vector<string> &v){
        if(index==digits.size()) {
            v.push_back(op);
            return;
        }
        
        string curr = phone[digits[index]-'0'];
        string temp = op;
        
        for(int i=0; i<curr.size();i++) {
            temp+=curr[i];
            solve(digits, index+1, temp, v);
            temp=op;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> v;
        solve(digits, 0, "", v);
        return v;
    }
};