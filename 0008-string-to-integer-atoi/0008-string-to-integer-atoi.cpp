class Solution {
public:
    int myAtoi(string s) {
        int len = s.length();
        if(!len) return 0;
        
        int i=0;
        while(i<len && s[i]==' ') i++;
        
        int isNeg = 0;
        if(s[i]=='-') {
            isNeg=1;
            i++;
        }
        else if(s[i]=='+') i++;
        
        int num = 0;
        while(i<len && s[i]>='0' && s[i]<='9'){
            int digit = s[i]-'0';
            int max_num = INT_MAX/10;
            
            // Integer.MAX_VALUE = 2147483647
            
            if(num<max_num || (num==max_num && digit<=7))
                num = num*10 + digit;
            else
                return isNeg ? INT_MIN : INT_MAX;  
            i++;
        }
        
        return isNeg ? -num : num;
    }
};