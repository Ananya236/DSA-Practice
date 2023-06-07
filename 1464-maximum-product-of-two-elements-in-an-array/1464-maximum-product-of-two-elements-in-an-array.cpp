class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int , vector<int>, greater<int>> minh;
        
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>2) minh.pop();
        }
        
        int n1 = minh.top()-1;
        minh.pop();
        int n2 = minh.top()-1;
        return n1*n2;
    }
};