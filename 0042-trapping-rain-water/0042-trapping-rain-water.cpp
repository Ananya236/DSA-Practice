class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lm(n) , rm(n);
        lm[0] = height[0];
        rm[n-1] = height[n-1];
        
        for(int i=1;i<n;i++) lm[i] = max(lm[i-1],height[i]);
        for(int i=n-2;i>=0;i--) rm[i] = max(rm[i+1], height[i]);
        
        int water = 0;
        for(int i=1;i<n-1;i++){
            int maxh = min(lm[i],rm[i]);
            water += maxh - height[i];
        }
        
        return water;
    }
};