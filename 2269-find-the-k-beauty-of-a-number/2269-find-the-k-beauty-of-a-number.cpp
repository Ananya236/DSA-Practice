class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num), subS = "";
        int i=0,j=0,n=s.length(),res = 0;
        
        while(j<n){
            subS += s[j];
            
            if(j-i+1==k){
                int n = stoi(subS);
                if(n && num%n==0) res++;
                subS = subS.substr(1);
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};