class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product = nums[i]*nums[j];
                mp[product]++;
            }
        }

        int result = 0;
        for(auto it: mp){
            int productCnt = it.second;
            if(productCnt >=2){
                result += productCnt * (productCnt-1) * 2 * 2;
            }
        }

        return result;
    }
};