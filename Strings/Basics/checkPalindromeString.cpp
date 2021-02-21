// GFG
// Check Palindrome String

// Given a string S, check if it is palindrome or not.

// Example :

// Input: S = "abba"
// Output: 1
// Explanation: S is a palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPlaindrome(string S)
    {
        int i = 0, j = S.length() - 1;
        while (i < j)
        {
            if (S[i] == S[j])
            {
                i++;
                j--;
            }
            else
                return 0;
        }
        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPlaindrome(s) << "\n";
    }

    return 0;
}