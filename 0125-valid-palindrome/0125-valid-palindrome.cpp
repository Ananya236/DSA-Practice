class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(iswalnum(s[i])) s1+=tolower(s[i]);
        }
        
        int st=0, ed=s1.size()-1;
        
        while(st<=ed){
            if(s1[st]!=s1[ed]) return false;
            st++; ed--;
        }
        
        return true;
    }
};