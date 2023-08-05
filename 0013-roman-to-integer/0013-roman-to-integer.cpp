class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> rv = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int n=s.length();
        int res = rv[s[n-1]];
        
        for(int i=n-2; i>=0; i--){
            if(rv[s[i]]<rv[s[i+1]])
                res-=rv[s[i]];
            else res+=rv[s[i]];
        }
        
        return res;
    }
};