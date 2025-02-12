class Solution {
    int maxDigitSum = 81;
public:
    int maximumSum(vector<int>& nums) {
        vector<int> maxDigitSumNums (maxDigitSum+1, 0);
        int result = -1;

        for (int num: nums){
            int sum=0, temp = num;
            while(temp){
                sum += temp%10;
                temp /= 10;
            }

            if(maxDigitSumNums[sum])
                result = max(result, maxDigitSumNums[sum]+num);
            maxDigitSumNums[sum] = max(maxDigitSumNums[sum], num);
        }

        return result;
    }
};