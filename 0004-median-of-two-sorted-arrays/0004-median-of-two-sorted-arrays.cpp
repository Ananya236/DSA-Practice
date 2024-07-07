class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<int> merged(n+m);
        int i1=0, i2=0, i=0;
        while(i1<n && i2<m){
            if(nums1[i1]<nums2[i2])
                merged[i++] = nums1[i1++];
            else if(nums2[i2]<nums1[i1])
                merged[i++] = nums2[i2++];
            else{
                merged[i++] = nums1[i1++];
                merged[i++] = nums2[i2++];
            }
        }
        while(i1<n){
            merged[i++] = nums1[i1++];
        }
        while(i2<m){
            merged[i++] = nums2[i2++];
        }

        int mid = (n+m)/2;
        if((n+m)%2 == 0) return double((merged[mid-1] + merged[mid])/2.0);
        return merged[mid];
    }
};