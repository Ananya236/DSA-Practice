class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq (nums.begin(), nums.end());
        pq.push(k);
        int res = 0;

        while(pq.size()>=2 && pq.top()<k){
            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            if(num1 * 2LL + num2 <= k)
                pq.push(num1 * 2 + num2);
            res++;
        }
        
        return res;
    }
};