class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0, delCount = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='b') bCount++;
            else{
                delCount = min(delCount + 1, bCount);
            }
        }
        return delCount;
    }
};