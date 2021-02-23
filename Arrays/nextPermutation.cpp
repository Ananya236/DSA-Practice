// Leetcode
// Next Permutation

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

// Example :

// Input: nums = [1,2,3]
// Output: [1,3,2]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),m; 
        bool swap=false;
        for(int i=0;i<n-1;i++)
        {
		//Finding element where descending order is not followed
            if(nums[n-1-i]>nums[n-2-i])
            {
             //Searching for element bigger than the decreasing element
                for(m=n-1;m>=n-2-i;m--)
                {
                    if(nums[n-2-i]<nums[m])
                    {
					//Swapping
                    int temp=nums[n-2-i];
                    nums[n-2-i]=nums[m];
                    nums[m]=temp;
                        break;
                    }
                }
				//Sorting
                sort(nums.begin()+n-1-i,nums.end());
                swap=true;
                break;
            }
        }
        if(swap==false)
            sort(nums.begin(),nums.end());
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution ob;
        ob.nextPermutation(nums);
    }
    return 0;
} 