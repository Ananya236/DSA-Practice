class Solution {
public:
    string prefix(string s1, string s2){
        string pre = "";
        for(int i=0,j=0; i<s1.size()&&j<s2.size(); i++,j++){
            if(s1[i]==s2[j]) pre+=s1[i];
            else break;
        }
        return pre;
    }
    
//     string divide(vector<string>& strs, int st, int ed){
//         if(st==ed)
//             return strs[st];
//         else {
//             int mid = (st+ed)/2;
//             string sl = divide(strs,st,mid);
//             string sr = divide(strs,mid+1,ed);
//             return prefix(sl,sr);
//         }
//     }
    
//     string longestCommonPrefix(vector<string>& strs) {
//         int n = strs.size();
//         if(n==0) return "";
//         return divide(strs,0,n-1);
//     }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        
        string pre = strs[0];
        
        for(int i=1;i<n;i++){
            pre = prefix(pre, strs[i]);
            if(pre=="") return pre;
        }
        
        return pre;
    }
};