// Leetcode
// Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// Example :

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // vector<int> ::iterator it;
        // it=find(nums.begin(),nums.end(),target);
        // if(it==nums.end())
        //     return -1;
        // else
        //     return it-nums.begin();

        int low = 0, high = nums.size() - 1, mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int target;
        cin >> target;
        Solution ob;
        ob.search(nums, target);

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }

        cout << endl;
    }
    return 0;
}