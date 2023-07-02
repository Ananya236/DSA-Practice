class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length()-1, n2=num2.length()-1;
        string res="";
        int carry=0;
        while(n1>=0 && n2>=0){
            int no1 = num1[n1--]-'0', no2 = num2[n2--]-'0';
            int sum = no1+no2+carry;
            carry = sum/10;
            int num = sum%10;
            res=to_string(num)+res;
        }
        
        while(n1>=0) {
            int no1 = num1[n1--]-'0';
            int sum = no1+carry;
            carry = sum/10;
            int num = sum%10;
            res=to_string(num)+res;
        }
        while(n2>=0) {
            int no2 = num2[n2--]-'0';
            int sum = no2+carry;
            carry = sum/10;
            int num = sum%10;
            res=to_string(num)+res;
        }
        
        if(carry) res=to_string(carry)+res;
        
        return res;
    }
};