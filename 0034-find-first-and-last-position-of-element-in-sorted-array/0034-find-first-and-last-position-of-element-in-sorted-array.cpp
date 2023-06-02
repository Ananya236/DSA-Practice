class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high, int target){
        int mid;
        while(low <= high){
            mid = (low + high) >> 1;
            if(nums[mid]==target) return mid;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return mid;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        if(h==-1) return {-1,-1};
        int mid = binary_search(nums,l,h,target);
        cout<<mid;
        int st=-1,ed=-1;
        for (int i = mid; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                st = i;
            }
        }

        for (int i = mid; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                ed = i;
            }
        }
        return {st,ed};
    }
};