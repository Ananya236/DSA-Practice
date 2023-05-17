class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i: nums){
            if(s.count(i)) return true;
            s.insert(i);
        }
        return false;
    }
};