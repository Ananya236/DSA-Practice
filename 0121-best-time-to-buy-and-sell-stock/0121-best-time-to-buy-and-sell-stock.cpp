class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int profit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<minp) minp=prices[i];
            else{
                if(prices[i]-minp > profit) profit = prices[i]-minp;
            }
        }
        return profit;
    }
};