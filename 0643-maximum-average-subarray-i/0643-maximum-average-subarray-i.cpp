class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxAvg=INT_MIN;
        int i=0,j=0,n=nums.size();
        
        while(j<n){
            sum+=nums[j];
            if(j-i+1 == k){
                double avg = sum/k;
                if(avg>maxAvg) maxAvg = avg;
                sum-=nums[i];
                i++;
            }
            j++;
        }
        
        return maxAvg;
    }
};