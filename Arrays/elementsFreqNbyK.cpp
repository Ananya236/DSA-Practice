// GFG
// Given an array of size n and a number k, find all elements that appear more than n/k times

// Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3. 

#include<bits/stdc++.h>
using namespace std;
 
void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;
    unordered_map<int, int> freq;
 
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
   
      // Traversing the map
    for(auto i : freq)
    {
         
        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x)
        {
             
            // Print the key of whose value
            // is greater than x
            cout << i.first << endl;
        }
    }
}
 
int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 
                  4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
     
    morethanNbyK(arr, n, k);
 
    return 0;
}