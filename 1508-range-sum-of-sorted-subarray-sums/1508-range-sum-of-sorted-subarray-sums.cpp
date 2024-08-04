class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        
        for(int i=0; i<n; i++){
            int curr = 0;
            for(int j=i; j<n; j++){
                curr += nums[j];
                sums.push_back(curr);
            }
        }
        
        sort(sums.begin(), sums.end());
        
        int res=0;
        for(int i=left-1; i<=right-1; i++){
            res+=sums[i]%1000000007;
            res%=1000000007;
        }
        
        return res;
    }
};