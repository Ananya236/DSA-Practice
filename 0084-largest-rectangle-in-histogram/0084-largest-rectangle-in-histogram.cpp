class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<pair<int,int>> sl, sr;
        vector<int> nsl,nsr;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(sl.empty()) nsl.push_back(-1);
            else{
                if(sl.top().first<arr[i]) nsl.push_back(sl.top().second);
                else{
                    while(!sl.empty() && sl.top().first>=arr[i]) sl.pop();
                    if(sl.empty()) nsl.push_back(-1);
                    else nsl.push_back(sl.top().second);
                }
            }
            sl.push({arr[i],i});
        }
        
        for(int i=n-1;i>=0;i--){
            if(sr.empty()) nsr.push_back(n);
            else{
                if(sr.top().first<arr[i]) nsr.push_back(sr.top().second);
                else{
                    while(!sr.empty() && sr.top().first>=arr[i]) sr.pop();
                    if(sr.empty()) nsr.push_back(n);
                    else nsr.push_back(sr.top().second);
                }
            }
            sr.push({arr[i],i});
        }
        
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int w = nsr[n-i-1] - nsl[i] -1;
            maxArea = max(maxArea,w*arr[i]);
        }
        
        return maxArea;
    }
};