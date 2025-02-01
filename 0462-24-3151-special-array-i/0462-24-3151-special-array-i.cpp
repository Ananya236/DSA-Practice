class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool isOdd = nums[0] & 1;

        for(int i=1; i<nums.size(); i++){
            bool currOdd = nums[i]&1;
            if((isOdd && currOdd) || (!isOdd && !currOdd)) return false;
            isOdd = currOdd;
        }

        return true;
    }
};