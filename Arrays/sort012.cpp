// GFG
// Sort an array of 0s, 1s and 2s.

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example :

// Input: 
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated 
// into ascending order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int a[], int n)
    {
        int st = 0, end = n - 1;
        int i = 0;
        while (i <= end)
        {
            if (a[i] == 0)
            {
                swap(a[st], a[i]);
                st++;
                i++;
            }
            else if (a[i] == 2)
            {
                swap(a[i], a[end]);
                end--;
            }
            else
                i++;
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}