class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=1, ed=height.size();
        int maxWater=0;
        while(st<=ed){
            int h1=height[st-1] , h2=height[ed-1];
            int water=(ed-st)*min(h1,h2);
            if(water>maxWater) maxWater=water;
            if(h1<h2) st++; else ed--;
        }
        return maxWater;
    }
};