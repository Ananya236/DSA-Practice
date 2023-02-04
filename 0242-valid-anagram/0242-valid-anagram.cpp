class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss=s.size();
        int st=t.size();
        if(ss!=st) return false;
        vector<int> fs(26),ft(26);
        for(int i=0;i<ss;i++) fs[s[i]-'a']++;
        for(int i=0;i<st;i++) ft[t[i]-'a']++;
        for(int i=0;i<26;i++){
            if(fs[i]!=ft[i]) return false;
        }
        return true;
    }
};