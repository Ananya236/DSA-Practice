typedef pair<int,int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n = nums.size();
        if(n==1) return nums;
        for(int i=0;i<n;i++){
            if(um.find(nums[i]) != um.end())
                um[nums[i]]++;
            else um[nums[i]] = 1;
        }
        priority_queue<pi, vector<pi>, greater<pi>> maxh;
        for(auto i: um){
            maxh.push(make_pair(i.second,i.first));
            if(maxh.size()>k) maxh.pop();
        }
        vector<int> res;
        while(maxh.size()){
            pair<int,int> i = maxh.top();
            maxh.pop();
            res.push_back(i.second);
        }
        return res;
    }
};