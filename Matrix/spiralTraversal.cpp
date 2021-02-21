// GFG
// Spirally traverse a matrix

// Given a matrix of size R*C. Traverse the matrix in spiral form.

// Example :

// Input:
// R = 4, C = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int m, int n)
    {
        vector<int> v;
        int count = m * n;
        int l = 0, r = n - 1, t = 0, d = m - 1;

        while (count--)
        {
            // while(l<=r && t<=d){
            for (int i = l; i <= r; i++)
            {
                v.push_back(matrix[t][i]);
            }
            t++;
            if (t > d)
                break;
            for (int i = t; i <= d; i++)
            {
                v.push_back(matrix[i][r]);
            }
            r--;
            if (r < l)
                break;
            for (int i = r; i >= l; i--)
            {
                v.push_back(matrix[d][i]);
            }
            d--;
            if (d < t)
                break;
            for (int i = d; i >= t; i--)
            {
                v.push_back(matrix[i][l]);
            }
            l++;
            if (l > r)
                break;
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

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}