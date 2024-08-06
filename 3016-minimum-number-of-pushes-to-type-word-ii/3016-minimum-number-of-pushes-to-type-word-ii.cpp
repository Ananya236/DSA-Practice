class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(char c: word) freq[c]++;
        
        priority_queue<int> pq;
        for(auto m: freq) pq.push(m.second);
        
        int pushCount = 0, index = 0;
        while(!pq.empty()){
            int pushReq = 1 + (index/8);
            pushCount += pushReq * pq.top();
            pq.pop();
            index++;
        }
        
        return pushCount;
    }
};