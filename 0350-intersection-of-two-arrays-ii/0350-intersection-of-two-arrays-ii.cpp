class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(1001,0);
        int n=nums1.size(), m=nums2.size();
        
        for(int i=0;i<n;i++)
            freq[nums1[i]]++;
        
        vector<int> com;
        for(int i=0;i<m;i++){
            if(freq[nums2[i]]){
                com.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        
        return com;
    }
};