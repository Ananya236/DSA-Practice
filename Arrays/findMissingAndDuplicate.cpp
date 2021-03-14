// GFG
// Find Missing And Repeating 

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example :

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *res=new int(2); 
        for(int i=0;i<n;i++) {
            if(arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1]=0-arr[abs(arr[i])-1];
            else
            res[0]=abs(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                res[1]=i+1;
                break;
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} 