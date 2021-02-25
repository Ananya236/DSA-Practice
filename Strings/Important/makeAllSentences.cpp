// GFG
// Recursively print all sentences that can be formed from list of word lists

// Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?

// Example:

// Input: {{"you", "we"},
//         {"have", "are"},
//         {"sleep", "eat", "drink"}}

// Output:
//   you have sleep
//   you have eat
//   you have drink
//   you are sleep
//   you are eat
//   you are drink
//   we have sleep
//   we have eat
//   we have drink
//   we are sleep
//   we are eat
//   we are drink

#include <bits/stdc++.h>
using namespace std;

void makeSentence(string*words, int r, int c, int crow, int ccol, string op[])
{
    op[crow] = *((words + (crow * c)) + ccol);
    // cout<<op[crow];
    if (crow == r-1)  //end of current sentence
    {
        // cout<<"if"<<crow<<ccol<<"\n";
        for (int i = 0; i < r; i++)
            cout << op[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        // cout<<"else"<<crow<<ccol<<"\n";
        for (int i = 0; i < c; i++)
            if (*(words + (crow + 1) * c + i) != "")
                makeSentence(words, r, c, crow + 1, i, op);
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    string words[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> words[i][j];
        }
    }
    string op[r];
    for (int i = 0; i < c; i++)
        if (words[0][i] != "")
            makeSentence((string *)words, r, c, 0, i, op);
}