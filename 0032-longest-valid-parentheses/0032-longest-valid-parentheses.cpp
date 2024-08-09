class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen=0, curlen=0, count=0, n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                if(count){
                    count--;
                    curlen += 2;
                }else{
                    curlen = 0;
                }
                if(!count){
                    maxlen = max(maxlen,curlen);
                }
            }else{
                count++;
            }
        }
        curlen=0; count=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='('){
                if(count){
                    count--;
                    curlen += 2;
                }else{
                    curlen = 0;
                }
                if(!count){
                    maxlen = max(maxlen,curlen);
                }
            }else{
                count++;
            }
        }
        return maxlen;
    }
};