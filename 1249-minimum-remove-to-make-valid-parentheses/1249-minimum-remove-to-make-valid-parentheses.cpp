class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else if(s[i]==')') {
                if(open) open--;
                else s[i]='#';
            }
        }
        
        for(int i=n-1; i>=0 && open; i--){
            if(s[i]=='(') {
                open--;
                s[i]='#';
            }
        }
        
        string res;
        for(auto i: s) if(i!='#') res+=i;
        return res;
    }
};