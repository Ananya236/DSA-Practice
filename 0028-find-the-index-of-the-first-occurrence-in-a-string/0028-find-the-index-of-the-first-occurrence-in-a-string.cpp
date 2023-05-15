class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;
        int n = haystack.length();
        int m = needle.length();
        for(int st=0;st<=n-m;st++){
            if(haystack.substr(st,m) == needle)
                return st;
        }
        return -1;
    }
};