class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int> st;
        int res=0;
        for(int i=0;i<n-res;i++){
            for(int j=i;j<n;j++){
                if(st.count(s[j])) {
                    int len = st.size();
                    if(len>res) res=len;
                    st.clear();
                    break;
                }
                st.insert(s[j]);
            }
        }
        int len = st.size();
        if(len>res) res=len;
        return res;
    }
};