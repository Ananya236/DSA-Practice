//#GFG
//#Number of unique paths

// Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

// Example:

// Input:
// A = 2, B = 2
// Output: 2
// Explanation: There are only two unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.

#include<bits/stdc++.h>
using namespace std;

int NumberOfPath( int, int);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout << NumberOfPath(a,b) << endl;
    }
}

int NumberOfPath(int a, int b) {
    int t[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(i==0 || j==0)       // initialisation for if size matrix is of 1*n or m*1 dimension, then only 1 path will be possible
            t[i][j]=1;
            else
            t[i][j]=t[i-1][j]+t[i][j-1];
        }
    }
    return t[a-1][b-1];
}
