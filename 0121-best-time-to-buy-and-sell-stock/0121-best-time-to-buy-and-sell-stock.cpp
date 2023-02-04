class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0];
        int profit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<minp) minp=prices[i];
            else{
                if(prices[i]-minp > profit) profit = prices[i]-minp;
            }
        }
        return profit;
    }
};