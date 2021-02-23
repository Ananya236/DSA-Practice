// Leetcode
// Merge intervals overlapping with each other

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example :

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return intervals;
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            if (v.empty()) //empty result vector
                v.push_back(intervals[i]);
            else if (v.back()[1] < intervals[i][0]) //non overlapping case
                v.push_back(intervals[i]);
            else //overlapping case
                v.back()[1] = max(v.back()[1], intervals[i][1]);
        }
        return v;
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
        vector<vector<int>> intervals;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> intervals[i][j];
            }
        }
        Solution ob;
        auto ans = ob.merge(intervals);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << intervals[i][j];
            }
        }
    }
    return 0;
}