// Leetcode
// Find the Duplicate Number

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// Example :

// Input: nums = [1,3,4,2,2]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // unordered_set<int> set;
        // for(int i=0;i<n;i++){
        //     if(set.find(nums[i])==set.end())
        //         set.insert(nums[i]);
        //     else
        //         return nums[i];
        // }
        // return -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        }
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i <= n; i++)
        {
            cin >> nums[i];
        }
        Solution ob;
        auto ans = ob.findDuplicate(nums);
        cout << ans << "\n";
    }
    return 0;
}