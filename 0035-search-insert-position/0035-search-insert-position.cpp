class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, ed = nums.size(), mid;
        if(target>nums[ed-1]){
            return ed;
        }
        while(st<=ed){
            mid=(st+ed)/2;
            if(nums[mid]==target){  
                return mid;
            }
            if(target<nums[mid]){     
                ed=mid-1;    
            }else{
                st=mid+1;        
            }
          
        }
        return st;
    }
};