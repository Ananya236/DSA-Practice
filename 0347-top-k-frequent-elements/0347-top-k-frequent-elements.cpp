typedef pair<int,int> pi;

class Solution {
public:
    //using min heap
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> um;
    //     int n = nums.size();
    //     if(n==1) return nums;
    //     for(int i=0;i<n;i++){
    //         um[nums[i]]++;
    //     }
    //     priority_queue<pi, vector<pi>, greater<pi>> minh;
    //     for(auto i: um){
    //         minh.push(make_pair(i.second,i.first));
    //         if(minh.size()>k) minh.pop();
    //     }
    //     vector<int> res;
    //     while(minh.size()){
    //         pair<int,int> i = minh.top();
    //         minh.pop();
    //         res.push_back(i.second);
    //     }
    //     return res;
    // }
    
    //using bucket sort
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n = nums.size();
        if(n==1) return nums;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto it: um){
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=n;i>0 && k>0;i--){
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            k=k-bucket[i].size();
        }
        
        return res;
    }
};