class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            maxh.push(stones[i]);
        }
        
        while(maxh.size()>1){
            int a=maxh.top();
            maxh.pop();
            int b = maxh.top();
            maxh.pop();
            if(a>b)
            maxh.push(a-b);                
        }
        
        if(maxh.size()) return maxh.top();
        return 0;
    }
};