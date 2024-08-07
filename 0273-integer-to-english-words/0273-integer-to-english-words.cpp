class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string result = "";
        int thNum = 0;
        
        while(num){
            int curr = num % 1000;
            string tempRes = "";
            
            if(curr) {
                int hdNum = curr/100;
                if(hdNum) tempRes += ones[hdNum] + " Hundred ";
                curr = curr % 100;
                if(curr >= 20) {
                    tempRes += tens[curr/10] + " ";
                    curr = curr % 10;
                }
                if(curr) tempRes += ones[curr] + " ";
                
                tempRes += thousands[thNum] + " ";
            }
            
            result = tempRes + result;
            thNum++;
            num = num/1000;
        }
        
        return result.substr(0, result.find_last_not_of(" ") + 1);
    }
};