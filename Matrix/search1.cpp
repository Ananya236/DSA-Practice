// Leetcode
// Search a 2D Matrix

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row. 

// Example :

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix.size()*matrix[0].size();
        if(h==0) return false;
        int n=matrix[0].size();
        h=h-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[mid / n][mid % n] == target) return true;
            else if(matrix[mid / n][mid % n] < target) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int target;
        cin>>target;

        Solution ob;
        bool result = ob.searchMatrix(matrix, target);
        cout << result;
    }
    return 0;
}