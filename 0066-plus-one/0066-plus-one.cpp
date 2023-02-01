class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        for(int i=n-1;i>=0;i--){
            if(c){
                digits[i]+=c;
                c=digits[i]/10;
                digits[i]%=10;
            }
        }
        if(c){
            vector<int> v;
            v.push_back(c);
            v.insert(v.end(), digits.begin(), digits.end());
            return v;
        }
        return digits;
    }
};