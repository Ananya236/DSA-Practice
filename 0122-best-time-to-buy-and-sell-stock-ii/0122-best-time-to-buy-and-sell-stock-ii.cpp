class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int n = prices.size();
//         int minP = prices[0];
//         int currProfit = 0;
        
//         for(int i=1;i<n;i++){
//             if(prices[i]<prices[i-1]) {
//                 minP=prices[i];
//                 totalProfit+=currProfit;
//                 currProfit=0;
//             }
//             else {
//                 currProfit = prices[i]-minP;
//             }
//         }
        
//         return totalProfit+currProfit;
        
        
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                totalProfit+=prices[i]-prices[i-1];
            }
        }
        
        return totalProfit;
    }
};