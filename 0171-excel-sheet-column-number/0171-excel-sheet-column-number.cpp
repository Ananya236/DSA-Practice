class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int res=0;
        for(int i=0; i<n; i++){
            int curr = int(columnTitle[i]) - int('A') + 1;
            res = res*26 + curr;
        }
        return res;
    }
}; 