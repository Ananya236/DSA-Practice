//#Leetcode
//#Kth symbol in grammar

//On the first row, we write a 0.
//Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
//Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.)

//eg:
// Input: N = 4, K = 5
// Output: 1

// Explanation:
// row 1: 0
// row 2: 01
// row 3: 0110
// row 4: 01101001

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int kthGrammar(int N, int K) {
    if(N==1 && K==1)
        return 0;
    int mid=pow(2,N-2); //pow(2,n-1)/2
    if(K<=mid)
        return kthGrammar(N-1,K);
    else
        return !kthGrammar(N-1,K-mid);
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<kthGrammar(n,k);
    return 0;
}