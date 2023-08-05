class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack == needle) return 0;
        // int n = haystack.length();
        // int m = needle.length();
        
        // for(int st=0;st<=n-m;st++){
        //     if(haystack.substr(st,m) == needle)
        //         return st;
        // }
        // return -1;
        
        // bool flag;
        // for(int i=0;i<n-m+1;i++){
        //     flag=true;
        //     for(int j=0;j<m;j++){
        //         if(haystack[i+j]!=needle[j]){
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag) return i;
        // }
        // return -1;
        
        return haystack.find(needle);
    }
};