// Second most repeated string in a sequence 

// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

// Note: No two strings are the second most repeated, there will be always a single string.

// Example :

// Input:
// N = 6
// arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
// Output: bbb
// Explanation: "bbb" is the second most 
// occurring string with frequency 2.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        string str="";
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int m1=0,m2=0;
        string res;
        
        for(auto it:mp)
            m1=max(m1,it.second);
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<"\n";
            if(it.second!=m1)
                if(it.second>m2){
                    m2=it.second;
                    res=it.first;
                }
        }
        
        return res;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}