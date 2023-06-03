class Solution {
public:
    string getResult(string num){
        string res = "";
        int n=num[0], ct=1;
        for(int i=1;i<num.length();i++){
            if(num[i]==num[i-1]) ct++;
            else {
                res += to_string(ct);
                res += n;
                n=num[i];
                ct=1;
            }
        }
        res += to_string(ct);
        res += n;
        return res;
    }
    
    string countAndSay(int n) {
        string ans = to_string(1);
        for(int i=2;i<=n;i++){
            ans = getResult(ans);
        }
        return ans;
    }
};