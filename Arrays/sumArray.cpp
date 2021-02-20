// GFG
// Sum of array elements
 
#include <bits/stdc++.h>
using namespace std;

int sumElement(int arr[], int n)
{
    return accumulate(arr, arr + n, 0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << sumElement(arr, n) << endl;
    }
    return 0;
}