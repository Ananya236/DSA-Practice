// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Input:
// The first line of input contains an integer T denoting the number of test cases. T testcases follow.The first line of each test case is n.

// Output:
// For each testcase, in a new line, print number of ways/combinations to reach the given score.

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ n ≤ 1000

// Example:
// Input
// 3
// 8
// 20
// 13
// Output
// 1
// 4
// 2
// Explanation
// For 1st example when n = 8
// { 3, 5 } and {5, 3} are the two possible permutations but these represent the same cobmination. Hence output is 1.

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

long long int count(long long int n)
{
	// If 0 sum is required number of ways is 1.
	int S[3] = {3, 5, 10};
	long long int t[4][n + 1];
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == 0 && i == 0)
				t[i][j] = 1;
			else if (i == 0)
				t[i][j] = 0;
			else if (S[i - 1] <= j)
				t[i][j] = t[i][j - S[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[3][n];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << count(n) << endl;
	}
	return 0;
}