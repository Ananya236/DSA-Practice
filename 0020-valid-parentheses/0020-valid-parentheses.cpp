class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n&1) return false;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(!st.empty()){
                if(s[i]==')' && st.top()=='(')
                    st.pop();
                else if(s[i]=='}' && st.top()=='{')
                    st.pop();
                else if(s[i]==']' && st.top()=='[')
                    st.pop();
                else return false;
            }
            else return false;
        }
        return st.empty();
    }
};