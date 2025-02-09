class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> goodPairFreq;
        long long n = nums.size();
        long long goodPairs = 0, totalPairs = n*(n-1)/2;

        for(int i=0; i<n; i++){
            int key = nums[i]-i;
            goodPairs += goodPairFreq[key];
            goodPairFreq[key]++;
        }

        return totalPairs - goodPairs;
    }
};