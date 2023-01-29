class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
           m[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int num = target-nums[i];
            if(m.find(num) != m.end() && m[num] != i){
                return {i, m[num]};
            }
        }
        return {};
    }
};