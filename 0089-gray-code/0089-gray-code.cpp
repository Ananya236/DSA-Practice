class Solution {
public:
    void helper(int &num, int n, vector<int> &v){
        num ^= 1<<n;
        v.push_back(num);
        for(int i=0; i<n; i++){
            helper(num, i, v);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> v;
        int num = 0;
        v.push_back(num);
        for(int i=0; i<n; i++){
            helper(num, i, v);
        }
        return v;
    }
};