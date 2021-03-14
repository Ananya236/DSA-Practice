// GFG
// Count Palindromic Subsequences

// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.

// Example :

// Input:
// Str = "abcd"
// Output:
// 4
// Explanation:
// palindromic subsequence are : "a" ,"b", "c" ,"d"

#include <iostream>
#include <cstring>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << countPS(str) << endl;
    }
}

int t[31][31];
int count(string s, int start, int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (t[start][end] != -1)
        return t[start][end];
    if (s[start] == s[end])
        return t[start][end] = 1 + count(s, start + 1, end) + count(s, start, end - 1);
    else
        return t[start][end] = count(s, start + 1, end) + count(s, start, end - 1) - count(s, start + 1, end - 1);
}

int countPS(string str)
{
    memset(t, -1, sizeof(t));
    return count(str, 0, str.length() - 1);
}
