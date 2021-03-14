// GFG
// Parenthesis Checker 

// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

// Example :

// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balaced pairs, with 0 number of 
// unbalanced bracket.

#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        stack<char> st;
        int t = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (!st.empty() && ((s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{') || (s[i] == ')' && st.top() == '(')))
            {
                st.pop();
            }
            else
            {
                t = 0;
                break;
            }
        }
        if (st.empty() && t == 1)
            cout << "balanced\n";
        else
            cout << "not balanced\n";
    }
    return 0;
}